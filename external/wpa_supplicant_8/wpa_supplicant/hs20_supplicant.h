/*
 * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef HS20_SUPPLICANT_H
#define HS20_SUPPLICANT_H

void wpas_hs20_add_indication(struct wpabuf *buf);

int hs20_anqp_send_req(struct wpa_supplicant *wpa_s, const u8 *dst, u32 stypes,
		       const u8 *payload, size_t payload_len);
struct wpabuf * hs20_build_anqp_req(u32 stypes, const u8 *payload,
				    size_t payload_len);
void hs20_parse_rx_hs20_anqp_resp(struct wpa_supplicant *wpa_s,
				  const u8 *sa, const u8 *data, size_t slen);
int is_hs20_network(struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid,
		    struct wpa_bss *bss);
#ifdef CONFIG_MTK_HS20R1
int hs20_sta_enable(struct wpa_supplicant *wpa_s, char *cmd, char *buf, size_t buflen);
int hs20_sta_disable(struct wpa_supplicant *wpa_s, char *cmd, char *buf, size_t buflen);
#endif /*CONFIG_MTK_HS20R1 */

#endif /* HS20_SUPPLICANT_H */
