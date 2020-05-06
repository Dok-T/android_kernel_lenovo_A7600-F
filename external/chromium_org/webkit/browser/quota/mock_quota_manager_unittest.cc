// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


#include <set>

#include "base/bind.h"
#include "base/file_util.h"
#include "base/files/scoped_temp_dir.h"
#include "base/memory/scoped_ptr.h"
#include "base/message_loop/message_loop.h"
#include "base/message_loop/message_loop_proxy.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "webkit/browser/quota/mock_quota_manager.h"
#include "webkit/browser/quota/mock_special_storage_policy.h"
#include "webkit/browser/quota/mock_storage_client.h"

namespace quota {

const char kTestOrigin1[] = "http://host1:1/";
const char kTestOrigin2[] = "http://host2:1/";
const char kTestOrigin3[] = "http://host3:1/";

const GURL kOrigin1(kTestOrigin1);
const GURL kOrigin2(kTestOrigin2);
const GURL kOrigin3(kTestOrigin3);

const StorageType kTemporary = kStorageTypeTemporary;
const StorageType kPersistent = kStorageTypePersistent;

const QuotaClient::ID kClientFile = QuotaClient::kFileSystem;
const QuotaClient::ID kClientDB = QuotaClient::kIndexedDatabase;

class MockQuotaManagerTest : public testing::Test {
 public:
  MockQuotaManagerTest()
    : weak_factory_(this),
      deletion_callback_count_(0) {
  }

  virtual void SetUp() {
    ASSERT_TRUE(data_dir_.CreateUniqueTempDir());
    policy_ = new MockSpecialStoragePolicy;
    manager_ = new MockQuotaManager(false /* is_incognito */,
                                    data_dir_.path(),
                                    base::MessageLoopProxy::current().get(),
                                    base::MessageLoopProxy::current().get(),
                                    policy_.get());
  }

  virtual void TearDown() {
    // Make sure the quota manager cleans up correctly.
    manager_ = NULL;
    base::MessageLoop::current()->RunUntilIdle();
  }

  void GetModifiedOrigins(StorageType type, base::Time since) {
    manager_->GetOriginsModifiedSince(
        type, since,
        base::Bind(&MockQuotaManagerTest::GotModifiedOrigins,
                   weak_factory_.GetWeakPtr()));
  }

  void GotModifiedOrigins(const std::set<GURL>& origins, StorageType type) {
    origins_ = origins;
    type_ = type;
  }

  void DeleteOriginData(const GURL& origin, StorageType type,
      int quota_client_mask) {
    manager_->DeleteOriginData(
        origin, type, quota_client_mask,
        base::Bind(&MockQuotaManagerTest::DeletedOriginData,
                   weak_factory_.GetWeakPtr()));
  }

  void DeletedOriginData(QuotaStatusCode status) {
    ++deletion_callback_count_;
    EXPECT_EQ(quota::kQuotaStatusOk, status);
  }

  int deletion_callback_count() const {
    return deletion_callback_count_;
  }

  MockQuotaManager* manager() const {
    return manager_.get();
  }

  const std::set<GURL>& origins() const {
    return origins_;
  }

  const StorageType& type() const {
    return type_;
  }

 private:
  base::MessageLoop message_loop_;
  base::ScopedTempDir data_dir_;
  base::WeakPtrFactory<MockQuotaManagerTest> weak_factory_;
  scoped_refptr<MockQuotaManager> manager_;
  scoped_refptr<MockSpecialStoragePolicy> policy_;

  int deletion_callback_count_;

  std::set<GURL> origins_;
  StorageType type_;

  DISALLOW_COPY_AND_ASSIGN(MockQuotaManagerTest);
};

TEST_F(MockQuotaManagerTest, BasicOriginManipulation) {
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kTemporary, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kPersistent, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientDB));

  manager()->AddOrigin(kOrigin1, kTemporary, kClientFile, base::Time::Now());
  EXPECT_TRUE(manager()->OriginHasData(kOrigin1, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kTemporary, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kPersistent, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientDB));

  manager()->AddOrigin(kOrigin1, kPersistent, kClientFile, base::Time::Now());
  EXPECT_TRUE(manager()->OriginHasData(kOrigin1, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kTemporary, kClientDB));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin1, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kPersistent, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientDB));

  manager()->AddOrigin(kOrigin2, kTemporary, kClientFile | kClientDB,
      base::Time::Now());
  EXPECT_TRUE(manager()->OriginHasData(kOrigin1, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kTemporary, kClientDB));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin1, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin1, kPersistent, kClientDB));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin2, kTemporary, kClientFile));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin2, kTemporary, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kPersistent, kClientDB));
}

TEST_F(MockQuotaManagerTest, OriginDeletion) {
  manager()->AddOrigin(kOrigin1, kTemporary, kClientFile, base::Time::Now());
  manager()->AddOrigin(kOrigin2, kTemporary, kClientFile | kClientDB,
      base::Time::Now());
  manager()->AddOrigin(kOrigin3, kTemporary, kClientFile | kClientDB,
      base::Time::Now());

  DeleteOriginData(kOrigin2, kTemporary, kClientFile);
  base::MessageLoop::current()->RunUntilIdle();

  EXPECT_EQ(1, deletion_callback_count());
  EXPECT_TRUE(manager()->OriginHasData(kOrigin1, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientFile));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin2, kTemporary, kClientDB));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin3, kTemporary, kClientFile));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin3, kTemporary, kClientDB));

  DeleteOriginData(kOrigin3, kTemporary, kClientFile | kClientDB);
  base::MessageLoop::current()->RunUntilIdle();

  EXPECT_EQ(2, deletion_callback_count());
  EXPECT_TRUE(manager()->OriginHasData(kOrigin1, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin2, kTemporary, kClientFile));
  EXPECT_TRUE(manager()->OriginHasData(kOrigin2, kTemporary, kClientDB));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin3, kTemporary, kClientFile));
  EXPECT_FALSE(manager()->OriginHasData(kOrigin3, kTemporary, kClientDB));
}

TEST_F(MockQuotaManagerTest, ModifiedOrigins) {
  base::Time now = base::Time::Now();
  base::Time then = base::Time();
  base::TimeDelta an_hour = base::TimeDelta::FromMilliseconds(3600000);
  base::TimeDelta a_minute = base::TimeDelta::FromMilliseconds(60000);

  GetModifiedOrigins(kTemporary, then);
  base::MessageLoop::current()->RunUntilIdle();
  EXPECT_TRUE(origins().empty());

  manager()->AddOrigin(kOrigin1, kTemporary, kClientFile, now - an_hour);

  GetModifiedOrigins(kTemporary, then);
  base::MessageLoop::current()->RunUntilIdle();

  EXPECT_EQ(kTemporary, type());
  EXPECT_EQ(1UL, origins().size());
  EXPECT_EQ(1UL, origins().count(kOrigin1));
  EXPECT_EQ(0UL, origins().count(kOrigin2));

  manager()->AddOrigin(kOrigin2, kTemporary, kClientFile, now);

  GetModifiedOrigins(kTemporary, then);
  base::MessageLoop::current()->RunUntilIdle();

  EXPECT_EQ(kTemporary, type());
  EXPECT_EQ(2UL, origins().size());
  EXPECT_EQ(1UL, origins().count(kOrigin1));
  EXPECT_EQ(1UL, origins().count(kOrigin2));

  GetModifiedOrigins(kTemporary, now - a_minute);
  base::MessageLoop::current()->RunUntilIdle();

  EXPECT_EQ(kTemporary, type());
  EXPECT_EQ(1UL, origins().size());
  EXPECT_EQ(0UL, origins().count(kOrigin1));
  EXPECT_EQ(1UL, origins().count(kOrigin2));
}
}  // Namespace quota
