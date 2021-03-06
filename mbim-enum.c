/*
 * umbim
 * Copyright (C) 2014 John Crispin <blogic@openwrt.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>

#include "mbim.h"

struct mbim_enum mbim_service_values[] = {
    { MBIM_SERVICE_INVALID, "MBIM_SERVICE_INVALID", "invalid" },
    { MBIM_SERVICE_BASIC_CONNECT, "MBIM_SERVICE_BASIC_CONNECT", "basic-connect" },
    { MBIM_SERVICE_SMS, "MBIM_SERVICE_SMS", "sms" },
    { MBIM_SERVICE_USSD, "MBIM_SERVICE_USSD", "ussd" },
    { MBIM_SERVICE_PHONEBOOK, "MBIM_SERVICE_PHONEBOOK", "phonebook" },
    { MBIM_SERVICE_STK, "MBIM_SERVICE_STK", "stk" },
    { MBIM_SERVICE_AUTH, "MBIM_SERVICE_AUTH", "auth" },
    { MBIM_SERVICE_DSS, "MBIM_SERVICE_DSS", "dss" },
    { MBIM_SERVICE_MS_FIRMWARE_ID, "MBIM_SERVICE_MS_FIRMWARE_ID", "ms-firmware-id" },
    { MBIM_SERVICE_MS_HOST_SHUTDOWN, "MBIM_SERVICE_MS_HOST_SHUTDOWN", "ms-host-shutdown" },
    { MBIM_SERVICE_PROXY_CONTROL, "MBIM_SERVICE_PROXY_CONTROL", "proxy-control" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_context_type_values[] = {
    { MBIM_CONTEXT_TYPE_INVALID, "MBIM_CONTEXT_TYPE_INVALID", "invalid" },
    { MBIM_CONTEXT_TYPE_NONE, "MBIM_CONTEXT_TYPE_NONE", "none" },
    { MBIM_CONTEXT_TYPE_INTERNET, "MBIM_CONTEXT_TYPE_INTERNET", "internet" },
    { MBIM_CONTEXT_TYPE_VPN, "MBIM_CONTEXT_TYPE_VPN", "vpn" },
    { MBIM_CONTEXT_TYPE_VOICE, "MBIM_CONTEXT_TYPE_VOICE", "voice" },
    { MBIM_CONTEXT_TYPE_VIDEO_SHARE, "MBIM_CONTEXT_TYPE_VIDEO_SHARE", "video-share" },
    { MBIM_CONTEXT_TYPE_PURCHASE, "MBIM_CONTEXT_TYPE_PURCHASE", "purchase" },
    { MBIM_CONTEXT_TYPE_IMS, "MBIM_CONTEXT_TYPE_IMS", "ims" },
    { MBIM_CONTEXT_TYPE_MMS, "MBIM_CONTEXT_TYPE_MMS", "mms" },
    { MBIM_CONTEXT_TYPE_LOCAL, "MBIM_CONTEXT_TYPE_LOCAL", "local" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_basic_connect_values[] = {
    { MBIM_CID_BASIC_CONNECT_UNKNOWN, "MBIM_CID_BASIC_CONNECT_UNKNOWN", "unknown" },
    { MBIM_CID_BASIC_CONNECT_DEVICE_CAPS, "MBIM_CID_BASIC_CONNECT_DEVICE_CAPS", "device-caps" },
    { MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS, "MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS", "subscriber-ready-status" },
    { MBIM_CID_BASIC_CONNECT_RADIO_STATE, "MBIM_CID_BASIC_CONNECT_RADIO_STATE", "radio-state" },
    { MBIM_CID_BASIC_CONNECT_PIN, "MBIM_CID_BASIC_CONNECT_PIN", "pin" },
    { MBIM_CID_BASIC_CONNECT_PIN_LIST, "MBIM_CID_BASIC_CONNECT_PIN_LIST", "pin-list" },
    { MBIM_CID_BASIC_CONNECT_HOME_PROVIDER, "MBIM_CID_BASIC_CONNECT_HOME_PROVIDER", "home-provider" },
    { MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS, "MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS", "preferred-providers" },
    { MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS, "MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS", "visible-providers" },
    { MBIM_CID_BASIC_CONNECT_REGISTER_STATE, "MBIM_CID_BASIC_CONNECT_REGISTER_STATE", "register-state" },
    { MBIM_CID_BASIC_CONNECT_PACKET_SERVICE, "MBIM_CID_BASIC_CONNECT_PACKET_SERVICE", "packet-service" },
    { MBIM_CID_BASIC_CONNECT_SIGNAL_STATE, "MBIM_CID_BASIC_CONNECT_SIGNAL_STATE", "signal-state" },
    { MBIM_CID_BASIC_CONNECT_CONNECT, "MBIM_CID_BASIC_CONNECT_CONNECT", "connect" },
    { MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS, "MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS", "provisioned-contexts" },
    { MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION, "MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION", "service-activation" },
    { MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION, "MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION", "ip-configuration" },
    { MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES, "MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES", "device-services" },
    { MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST, "MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST", "device-service-subscribe-list" },
    { MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS, "MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS", "packet-statistics" },
    { MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT, "MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT", "network-idle-hint" },
    { MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE, "MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE", "emergency-mode" },
    { MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS, "MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS", "ip-packet-filters" },
    { MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS, "MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS", "multicarrier-providers" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_sms_values[] = {
    { MBIM_CID_SMS_UNKNOWN, "MBIM_CID_SMS_UNKNOWN", "unknown" },
    { MBIM_CID_SMS_CONFIGURATION, "MBIM_CID_SMS_CONFIGURATION", "configuration" },
    { MBIM_CID_SMS_READ, "MBIM_CID_SMS_READ", "read" },
    { MBIM_CID_SMS_SEND, "MBIM_CID_SMS_SEND", "send" },
    { MBIM_CID_SMS_DELETE, "MBIM_CID_SMS_DELETE", "delete" },
    { MBIM_CID_SMS_MESSAGE_STORE_STATUS, "MBIM_CID_SMS_MESSAGE_STORE_STATUS", "message-store-status" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_ussd_values[] = {
    { MBIM_CID_USSD_UNKNOWN, "MBIM_CID_USSD_UNKNOWN", "ussd-unknown" },
    { MBIM_CID_USSD, "MBIM_CID_USSD", "ussd" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_phonebook_values[] = {
    { MBIM_CID_PHONEBOOK_UNKNOWN, "MBIM_CID_PHONEBOOK_UNKNOWN", "unknown" },
    { MBIM_CID_PHONEBOOK_CONFIGURATION, "MBIM_CID_PHONEBOOK_CONFIGURATION", "configuration" },
    { MBIM_CID_PHONEBOOK_READ, "MBIM_CID_PHONEBOOK_READ", "read" },
    { MBIM_CID_PHONEBOOK_DELETE, "MBIM_CID_PHONEBOOK_DELETE", "delete" },
    { MBIM_CID_PHONEBOOK_WRITE, "MBIM_CID_PHONEBOOK_WRITE", "write" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_stk_values[] = {
    { MBIM_CID_STK_UNKNOWN, "MBIM_CID_STK_UNKNOWN", "unknown" },
    { MBIM_CID_STK_PAC, "MBIM_CID_STK_PAC", "pac" },
    { MBIM_CID_STK_TERMINAL_RESPONSE, "MBIM_CID_STK_TERMINAL_RESPONSE", "terminal-response" },
    { MBIM_CID_STK_ENVELOPE, "MBIM_CID_STK_ENVELOPE", "envelope" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_auth_values[] = {
    { MBIM_CID_AUTH_UNKNOWN, "MBIM_CID_AUTH_UNKNOWN", "unknown" },
    { MBIM_CID_AUTH_AKA, "MBIM_CID_AUTH_AKA", "aka" },
    { MBIM_CID_AUTH_AKAP, "MBIM_CID_AUTH_AKAP", "akap" },
    { MBIM_CID_AUTH_SIM, "MBIM_CID_AUTH_SIM", "sim" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_dss_values[] = {
    { MBIM_CID_DSS_UNKNOWN, "MBIM_CID_DSS_UNKNOWN", "unknown" },
    { MBIM_CID_DSS_CONNECT, "MBIM_CID_DSS_CONNECT", "connect" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_ms_firmware_id_values[] = {
    { MBIM_CID_MS_FIRMWARE_ID_UNKNOWN, "MBIM_CID_MS_FIRMWARE_ID_UNKNOWN", "unknown" },
    { MBIM_CID_MS_FIRMWARE_ID_GET, "MBIM_CID_MS_FIRMWARE_ID_GET", "get" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_ms_host_shutdown_values[] = {
    { MBIM_CID_MS_HOST_SHUTDOWN_UNKNOWN, "MBIM_CID_MS_HOST_SHUTDOWN_UNKNOWN", "unknown" },
    { MBIM_CID_MS_HOST_SHUTDOWN_NOTIFY, "MBIM_CID_MS_HOST_SHUTDOWN_NOTIFY", "notify" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cid_proxy_control_values[] = {
    { MBIM_CID_PROXY_CONTROL_UNKNOWN, "MBIM_CID_PROXY_CONTROL_UNKNOWN", "unknown" },
    { MBIM_CID_PROXY_CONTROL_CONFIGURATION, "MBIM_CID_PROXY_CONTROL_CONFIGURATION", "configuration" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_message_type_values[] = {
    { MBIM_MESSAGE_TYPE_INVALID, "MBIM_MESSAGE_TYPE_INVALID", "invalid" },
    { MBIM_MESSAGE_TYPE_OPEN, "MBIM_MESSAGE_TYPE_OPEN", "open" },
    { MBIM_MESSAGE_TYPE_CLOSE, "MBIM_MESSAGE_TYPE_CLOSE", "close" },
    { MBIM_MESSAGE_TYPE_COMMAND, "MBIM_MESSAGE_TYPE_COMMAND", "command" },
    { MBIM_MESSAGE_TYPE_HOST_ERROR, "MBIM_MESSAGE_TYPE_HOST_ERROR", "host-error" },
    { MBIM_MESSAGE_TYPE_OPEN_DONE, "MBIM_MESSAGE_TYPE_OPEN_DONE", "open-done" },
    { MBIM_MESSAGE_TYPE_CLOSE_DONE, "MBIM_MESSAGE_TYPE_CLOSE_DONE", "close-done" },
    { MBIM_MESSAGE_TYPE_COMMAND_DONE, "MBIM_MESSAGE_TYPE_COMMAND_DONE", "command-done" },
    { MBIM_MESSAGE_TYPE_FUNCTION_ERROR, "MBIM_MESSAGE_TYPE_FUNCTION_ERROR", "function-error" },
    { MBIM_MESSAGE_TYPE_INDICATE_STATUS, "MBIM_MESSAGE_TYPE_INDICATE_STATUS", "indicate-status" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_message_command_type_values[] = {
    { MBIM_MESSAGE_COMMAND_TYPE_UNKNOWN, "MBIM_MESSAGE_COMMAND_TYPE_UNKNOWN", "unknown" },
    { MBIM_MESSAGE_COMMAND_TYPE_QUERY, "MBIM_MESSAGE_COMMAND_TYPE_QUERY", "query" },
    { MBIM_MESSAGE_COMMAND_TYPE_SET, "MBIM_MESSAGE_COMMAND_TYPE_SET", "set" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_device_type_values[] = {
    { MBIM_DEVICE_TYPE_UNKNOWN, "MBIM_DEVICE_TYPE_UNKNOWN", "unknown" },
    { MBIM_DEVICE_TYPE_EMBEDDED, "MBIM_DEVICE_TYPE_EMBEDDED", "embedded" },
    { MBIM_DEVICE_TYPE_REMOVABLE, "MBIM_DEVICE_TYPE_REMOVABLE", "removable" },
    { MBIM_DEVICE_TYPE_REMOTE, "MBIM_DEVICE_TYPE_REMOTE", "remote" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_cellular_class_values[] = {
    { MBIM_CELLULAR_CLASS_GSM, "MBIM_CELLULAR_CLASS_GSM", "gsm" },
    { MBIM_CELLULAR_CLASS_CDMA, "MBIM_CELLULAR_CLASS_CDMA", "cdma" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_voice_class_values[] = {
    { MBIM_VOICE_CLASS_UNKNOWN, "MBIM_VOICE_CLASS_UNKNOWN", "unknown" },
    { MBIM_VOICE_CLASS_NO_VOICE, "MBIM_VOICE_CLASS_NO_VOICE", "no-voice" },
    { MBIM_VOICE_CLASS_SEPARATED_VOICE_DATA, "MBIM_VOICE_CLASS_SEPARATED_VOICE_DATA", "separated-voice-data" },
    { MBIM_VOICE_CLASS_SIMULTANEOUS_VOICE_DATA, "MBIM_VOICE_CLASS_SIMULTANEOUS_VOICE_DATA", "simultaneous-voice-data" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sim_class_values[] = {
    { MBIM_SIM_CLASS_LOGICAL, "MBIM_SIM_CLASS_LOGICAL", "logical" },
    { MBIM_SIM_CLASS_REMOVABLE, "MBIM_SIM_CLASS_REMOVABLE", "removable" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_data_class_values[] = {
    { MBIM_DATA_CLASS_GPRS, "MBIM_DATA_CLASS_GPRS", "gprs" },
    { MBIM_DATA_CLASS_EDGE, "MBIM_DATA_CLASS_EDGE", "edge" },
    { MBIM_DATA_CLASS_UMTS, "MBIM_DATA_CLASS_UMTS", "umts" },
    { MBIM_DATA_CLASS_HSDPA, "MBIM_DATA_CLASS_HSDPA", "hsdpa" },
    { MBIM_DATA_CLASS_HSUPA, "MBIM_DATA_CLASS_HSUPA", "hsupa" },
    { MBIM_DATA_CLASS_LTE, "MBIM_DATA_CLASS_LTE", "lte" },
    { MBIM_DATA_CLASS_1XRTT, "MBIM_DATA_CLASS_1XRTT", "1xrtt" },
    { MBIM_DATA_CLASS_1XEVDO, "MBIM_DATA_CLASS_1XEVDO", "1xevdo" },
    { MBIM_DATA_CLASS_1XEVDO_REVA, "MBIM_DATA_CLASS_1XEVDO_REVA", "1xevdo-reva" },
    { MBIM_DATA_CLASS_1XEVDV, "MBIM_DATA_CLASS_1XEVDV", "1xevdv" },
    { MBIM_DATA_CLASS_3XRTT, "MBIM_DATA_CLASS_3XRTT", "3xrtt" },
    { MBIM_DATA_CLASS_1XEVDO_REVB, "MBIM_DATA_CLASS_1XEVDO_REVB", "1xevdo-revb" },
    { MBIM_DATA_CLASS_UMB, "MBIM_DATA_CLASS_UMB", "umb" },
    { MBIM_DATA_CLASS_CUSTOM, "MBIM_DATA_CLASS_CUSTOM", "custom" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_caps_values[] = {
    { MBIM_SMS_CAPS_PDU_RECEIVE, "MBIM_SMS_CAPS_PDU_RECEIVE", "pdu-receive" },
    { MBIM_SMS_CAPS_PDU_SEND, "MBIM_SMS_CAPS_PDU_SEND", "pdu-send" },
    { MBIM_SMS_CAPS_TEXT_RECEIVE, "MBIM_SMS_CAPS_TEXT_RECEIVE", "text-receive" },
    { MBIM_SMS_CAPS_TEXT_SEND, "MBIM_SMS_CAPS_TEXT_SEND", "text-send" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_ctrl_caps_values[] = {
    { MBIM_CTRL_CAPS_REG_MANUAL, "MBIM_CTRL_CAPS_REG_MANUAL", "reg-manual" },
    { MBIM_CTRL_CAPS_HW_RADIO_SWITCH, "MBIM_CTRL_CAPS_HW_RADIO_SWITCH", "hw-radio-switch" },
    { MBIM_CTRL_CAPS_CDMA_MOBILE_IP, "MBIM_CTRL_CAPS_CDMA_MOBILE_IP", "cdma-mobile-ip" },
    { MBIM_CTRL_CAPS_CDMA_SIMPLE_IP, "MBIM_CTRL_CAPS_CDMA_SIMPLE_IP", "cdma-simple-ip" },
    { MBIM_CTRL_CAPS_MULTI_CARRIER, "MBIM_CTRL_CAPS_MULTI_CARRIER", "multi-carrier" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_subscriber_ready_state_values[] = {
    { MBIM_SUBSCRIBER_READY_STATE_NOT_INITIALIZED, "MBIM_SUBSCRIBER_READY_STATE_NOT_INITIALIZED", "not-initialized" },
    { MBIM_SUBSCRIBER_READY_STATE_INITIALIZED, "MBIM_SUBSCRIBER_READY_STATE_INITIALIZED", "initialized" },
    { MBIM_SUBSCRIBER_READY_STATE_SIM_NOT_INSERTED, "MBIM_SUBSCRIBER_READY_STATE_SIM_NOT_INSERTED", "sim-not-inserted" },
    { MBIM_SUBSCRIBER_READY_STATE_BAD_SIM, "MBIM_SUBSCRIBER_READY_STATE_BAD_SIM", "bad-sim" },
    { MBIM_SUBSCRIBER_READY_STATE_FAILURE, "MBIM_SUBSCRIBER_READY_STATE_FAILURE", "failure" },
    { MBIM_SUBSCRIBER_READY_STATE_NOT_ACTIVATED, "MBIM_SUBSCRIBER_READY_STATE_NOT_ACTIVATED", "not-activated" },
    { MBIM_SUBSCRIBER_READY_STATE_DEVICE_LOCKED, "MBIM_SUBSCRIBER_READY_STATE_DEVICE_LOCKED", "device-locked" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_ready_info_flag_values[] = {
    { MBIM_READY_INFO_FLAG_PROTECT_UNIQUE_ID, "MBIM_READY_INFO_FLAG_PROTECT_UNIQUE_ID", "id" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_radio_switch_state_values[] = {
    { MBIM_RADIO_SWITCH_STATE_OFF, "MBIM_RADIO_SWITCH_STATE_OFF", "off" },
    { MBIM_RADIO_SWITCH_STATE_ON, "MBIM_RADIO_SWITCH_STATE_ON", "on" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_pin_type_values[] = {
    { MBIM_PIN_TYPE_UNKNOWN, "MBIM_PIN_TYPE_UNKNOWN", "unknown" },
    { MBIM_PIN_TYPE_CUSTOM, "MBIM_PIN_TYPE_CUSTOM", "custom" },
    { MBIM_PIN_TYPE_PIN1, "MBIM_PIN_TYPE_PIN1", "pin1" },
    { MBIM_PIN_TYPE_PIN2, "MBIM_PIN_TYPE_PIN2", "pin2" },
    { MBIM_PIN_TYPE_DEVICE_SIM_PIN, "MBIM_PIN_TYPE_DEVICE_SIM_PIN", "device-sim-pin" },
    { MBIM_PIN_TYPE_DEVICE_FIRST_SIM_PIN, "MBIM_PIN_TYPE_DEVICE_FIRST_SIM_PIN", "device-first-sim-pin" },
    { MBIM_PIN_TYPE_NETWORK_PIN, "MBIM_PIN_TYPE_NETWORK_PIN", "network-pin" },
    { MBIM_PIN_TYPE_NETWORK_SUBSET_PIN, "MBIM_PIN_TYPE_NETWORK_SUBSET_PIN", "network-subset-pin" },
    { MBIM_PIN_TYPE_SERVICE_PROVIDER_PIN, "MBIM_PIN_TYPE_SERVICE_PROVIDER_PIN", "service-provider-pin" },
    { MBIM_PIN_TYPE_CORPORATE_PIN, "MBIM_PIN_TYPE_CORPORATE_PIN", "corporate-pin" },
    { MBIM_PIN_TYPE_SUBSIDY_PIN, "MBIM_PIN_TYPE_SUBSIDY_PIN", "subsidy-pin" },
    { MBIM_PIN_TYPE_PUK1, "MBIM_PIN_TYPE_PUK1", "puk1" },
    { MBIM_PIN_TYPE_PUK2, "MBIM_PIN_TYPE_PUK2", "puk2" },
    { MBIM_PIN_TYPE_DEVICE_FIRST_SIM_PUK, "MBIM_PIN_TYPE_DEVICE_FIRST_SIM_PUK", "device-first-sim-puk" },
    { MBIM_PIN_TYPE_NETWORK_PUK, "MBIM_PIN_TYPE_NETWORK_PUK", "network-puk" },
    { MBIM_PIN_TYPE_NETWORK_SUBSET_PUK, "MBIM_PIN_TYPE_NETWORK_SUBSET_PUK", "network-subset-puk" },
    { MBIM_PIN_TYPE_SERVICE_PROVIDER_PUK, "MBIM_PIN_TYPE_SERVICE_PROVIDER_PUK", "service-provider-puk" },
    { MBIM_PIN_TYPE_CORPORATE_PUK, "MBIM_PIN_TYPE_CORPORATE_PUK", "corporate-puk" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_pin_state_values[] = {
    { MBIM_PIN_STATE_UNLOCKED, "MBIM_PIN_STATE_UNLOCKED", "unlocked" },
    { MBIM_PIN_STATE_LOCKED, "MBIM_PIN_STATE_LOCKED", "locked" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_pin_operation_values[] = {
    { MBIM_PIN_OPERATION_ENTER, "MBIM_PIN_OPERATION_ENTER", "enter" },
    { MBIM_PIN_OPERATION_ENABLE, "MBIM_PIN_OPERATION_ENABLE", "enable" },
    { MBIM_PIN_OPERATION_DISABLE, "MBIM_PIN_OPERATION_DISABLE", "disable" },
    { MBIM_PIN_OPERATION_CHANGE, "MBIM_PIN_OPERATION_CHANGE", "change" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_pin_mode_values[] = {
    { MBIM_PIN_MODE_NOT_SUPPORTED, "MBIM_PIN_MODE_NOT_SUPPORTED", "not-supported" },
    { MBIM_PIN_MODE_ENABLED, "MBIM_PIN_MODE_ENABLED", "enabled" },
    { MBIM_PIN_MODE_DISABLED, "MBIM_PIN_MODE_DISABLED", "disabled" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_pin_format_values[] = {
    { MBIM_PIN_FORMAT_UNKNOWN, "MBIM_PIN_FORMAT_UNKNOWN", "unknown" },
    { MBIM_PIN_FORMAT_NUMERIC, "MBIM_PIN_FORMAT_NUMERIC", "numeric" },
    { MBIM_PIN_FORMAT_ALPHANUMERIC, "MBIM_PIN_FORMAT_ALPHANUMERIC", "alphanumeric" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_provider_state_values[] = {
    { MBIM_PROVIDER_STATE_UNKNOWN, "MBIM_PROVIDER_STATE_UNKNOWN", "unknown" },
    { MBIM_PROVIDER_STATE_HOME, "MBIM_PROVIDER_STATE_HOME", "home" },
    { MBIM_PROVIDER_STATE_FORBIDDEN, "MBIM_PROVIDER_STATE_FORBIDDEN", "forbidden" },
    { MBIM_PROVIDER_STATE_PREFERRED, "MBIM_PROVIDER_STATE_PREFERRED", "preferred" },
    { MBIM_PROVIDER_STATE_VISIBLE, "MBIM_PROVIDER_STATE_VISIBLE", "visible" },
    { MBIM_PROVIDER_STATE_REGISTERED, "MBIM_PROVIDER_STATE_REGISTERED", "registered" },
    { MBIM_PROVIDER_STATE_PREFERRED_MULTICARRIER, "MBIM_PROVIDER_STATE_PREFERRED_MULTICARRIER", "preferred-multicarrier" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_visible_providers_action_values[] = {
    { MBIM_VISIBLE_PROVIDERS_ACTION_FULL_SCAN, "MBIM_VISIBLE_PROVIDERS_ACTION_FULL_SCAN", "full-scan" },
    { MBIM_VISIBLE_PROVIDERS_ACTION_RESTRICTED_SCAN, "MBIM_VISIBLE_PROVIDERS_ACTION_RESTRICTED_SCAN", "restricted-scan" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_nw_error_values[] = {
    { MBIM_NW_ERROR_UNKNOWN, "MBIM_NW_ERROR_UNKNOWN", "unknown" },
    { MBIM_NW_ERROR_IMSI_UNKNOWN_IN_HLR, "MBIM_NW_ERROR_IMSI_UNKNOWN_IN_HLR", "imsi-unknown-in-hlr" },
    { MBIM_NW_ERROR_ILLEGAL_MS, "MBIM_NW_ERROR_ILLEGAL_MS", "illegal-ms" },
    { MBIM_NW_ERROR_IMSI_UNKNOWN_IN_VLR, "MBIM_NW_ERROR_IMSI_UNKNOWN_IN_VLR", "imsi-unknown-in-vlr" },
    { MBIM_NW_ERROR_IMEI_NOT_ACCEPTED, "MBIM_NW_ERROR_IMEI_NOT_ACCEPTED", "imei-not-accepted" },
    { MBIM_NW_ERROR_ILLEGAL_ME, "MBIM_NW_ERROR_ILLEGAL_ME", "illegal-me" },
    { MBIM_NW_ERROR_GPRS_NOT_ALLOWED, "MBIM_NW_ERROR_GPRS_NOT_ALLOWED", "gprs-not-allowed" },
    { MBIM_NW_ERROR_GPRS_AND_NON_GPRS_NOT_ALLOWED, "MBIM_NW_ERROR_GPRS_AND_NON_GPRS_NOT_ALLOWED", "gprs-and-non-gprs-not-allowed" },
    { MBIM_NW_ERROR_MS_IDENTITY_NOT_DERIVED_BY_NETWORK, "MBIM_NW_ERROR_MS_IDENTITY_NOT_DERIVED_BY_NETWORK", "ms-identity-not-derived-by-network" },
    { MBIM_NW_ERROR_IMPLICITLY_DETACHED, "MBIM_NW_ERROR_IMPLICITLY_DETACHED", "implicitly-detached" },
    { MBIM_NW_ERROR_PLMN_NOT_ALLOWED, "MBIM_NW_ERROR_PLMN_NOT_ALLOWED", "plmn-not-allowed" },
    { MBIM_NW_ERROR_LOCATION_AREA_NOT_ALLOWED, "MBIM_NW_ERROR_LOCATION_AREA_NOT_ALLOWED", "location-area-not-allowed" },
    { MBIM_NW_ERROR_ROAMING_NOT_ALLOWED_IN_LOCATION_AREA, "MBIM_NW_ERROR_ROAMING_NOT_ALLOWED_IN_LOCATION_AREA", "roaming-not-allowed-in-location-area" },
    { MBIM_NW_ERROR_GPRS_NOT_ALLOWED_IN_PLMN, "MBIM_NW_ERROR_GPRS_NOT_ALLOWED_IN_PLMN", "gprs-not-allowed-in-plmn" },
    { MBIM_NW_ERROR_NO_CELLS_IN_LOCATION_AREA, "MBIM_NW_ERROR_NO_CELLS_IN_LOCATION_AREA", "no-cells-in-location-area" },
    { MBIM_NW_ERROR_MSC_TEMPORARILY_NOT_REACHABLE, "MBIM_NW_ERROR_MSC_TEMPORARILY_NOT_REACHABLE", "msc-temporarily-not-reachable" },
    { MBIM_NW_ERROR_NETWORK_FAILURE, "MBIM_NW_ERROR_NETWORK_FAILURE", "network-failure" },
    { MBIM_NW_ERROR_MAC_FAILURE, "MBIM_NW_ERROR_MAC_FAILURE", "mac-failure" },
    { MBIM_NW_ERROR_SYNCH_FAILURE, "MBIM_NW_ERROR_SYNCH_FAILURE", "synch-failure" },
    { MBIM_NW_ERROR_CONGESTION, "MBIM_NW_ERROR_CONGESTION", "congestion" },
    { MBIM_NW_ERROR_GSM_AUTHENTICATION_UNACCEPTABLE, "MBIM_NW_ERROR_GSM_AUTHENTICATION_UNACCEPTABLE", "gsm-authentication-unacceptable" },
    { MBIM_NW_ERROR_NOT_AUTHORIZED_FOR_CSG, "MBIM_NW_ERROR_NOT_AUTHORIZED_FOR_CSG", "not-authorized-for-csg" },
    { MBIM_NW_ERROR_MISSING_OR_UNKNOWN_APN, "MBIM_NW_ERROR_MISSING_OR_UNKNOWN_APN", "missing-or-unknown-apn" },
    { MBIM_NW_ERROR_SERVICE_OPTION_NOT_SUPPORTED, "MBIM_NW_ERROR_SERVICE_OPTION_NOT_SUPPORTED", "service-option-not-supported" },
    { MBIM_NW_ERROR_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED, "MBIM_NW_ERROR_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED", "requested-service-option-not-subscribed" },
    { MBIM_NW_ERROR_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER, "MBIM_NW_ERROR_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER", "service-option-temporarily-out-of-order" },
    { MBIM_NW_ERROR_NO_PDP_CONTEXT_ACTIVATED, "MBIM_NW_ERROR_NO_PDP_CONTEXT_ACTIVATED", "no-pdp-context-activated" },
    { MBIM_NW_ERROR_SEMANTICALLY_INCORRECT_MESSAGE, "MBIM_NW_ERROR_SEMANTICALLY_INCORRECT_MESSAGE", "semantically-incorrect-message" },
    { MBIM_NW_ERROR_INVALID_MANDATORY_INFORMATION, "MBIM_NW_ERROR_INVALID_MANDATORY_INFORMATION", "invalid-mandatory-information" },
    { MBIM_NW_ERROR_MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED, "MBIM_NW_ERROR_MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED", "message-type-non-existent-or-not-implemented" },
    { MBIM_NW_ERROR_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE, "MBIM_NW_ERROR_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE", "message-type-not-compatible-with-protocol-state" },
    { MBIM_NW_ERROR_INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED, "MBIM_NW_ERROR_INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED", "information-element-non-existent-or-not-implemented" },
    { MBIM_NW_ERROR_CONDITIONAL_IE_ERROR, "MBIM_NW_ERROR_CONDITIONAL_IE_ERROR", "conditional-ie-error" },
    { MBIM_NW_ERROR_MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE, "MBIM_NW_ERROR_MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE", "message-not-compatible-with-protocol-state" },
    { MBIM_NW_ERROR_PROTOCOL_ERROR_UNSPECIFIED, "MBIM_NW_ERROR_PROTOCOL_ERROR_UNSPECIFIED", "protocol-error-unspecified" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_register_action_values[] = {
    { MBIM_REGISTER_ACTION_AUTOMATIC, "MBIM_REGISTER_ACTION_AUTOMATIC", "automatic" },
    { MBIM_REGISTER_ACTION_MANUAL, "MBIM_REGISTER_ACTION_MANUAL", "manual" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_register_state_values[] = {
    { MBIM_REGISTER_STATE_UNKNOWN, "MBIM_REGISTER_STATE_UNKNOWN", "unknown" },
    { MBIM_REGISTER_STATE_DEREGISTERED, "MBIM_REGISTER_STATE_DEREGISTERED", "deregistered" },
    { MBIM_REGISTER_STATE_SEARCHING, "MBIM_REGISTER_STATE_SEARCHING", "searching" },
    { MBIM_REGISTER_STATE_HOME, "MBIM_REGISTER_STATE_HOME", "home" },
    { MBIM_REGISTER_STATE_ROAMING, "MBIM_REGISTER_STATE_ROAMING", "roaming" },
    { MBIM_REGISTER_STATE_PARTNER, "MBIM_REGISTER_STATE_PARTNER", "partner" },
    { MBIM_REGISTER_STATE_DENIED, "MBIM_REGISTER_STATE_DENIED", "denied" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_register_mode_values[] = {
    { MBIM_REGISTER_MODE_UNKNOWN, "MBIM_REGISTER_MODE_UNKNOWN", "unknown" },
    { MBIM_REGISTER_MODE_AUTOMATIC, "MBIM_REGISTER_MODE_AUTOMATIC", "automatic" },
    { MBIM_REGISTER_MODE_MANUAL, "MBIM_REGISTER_MODE_MANUAL", "manual" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_registration_flag_values[] = {
    { MBIM_REGISTRATION_FLAG_NONE, "MBIM_REGISTRATION_FLAG_NONE", "none" },
    { MBIM_REGISTRATION_FLAG_MANUAL_SELECTION_NOT_AVAILABLE, "MBIM_REGISTRATION_FLAG_MANUAL_SELECTION_NOT_AVAILABLE", "manual-selection-not-available" },
    { MBIM_REGISTRATION_FLAG_PACKET_SERVICE_AUTOMATIC_ATTACH, "MBIM_REGISTRATION_FLAG_PACKET_SERVICE_AUTOMATIC_ATTACH", "packet-service-automatic-attach" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_packet_service_action_values[] = {
    { MBIM_PACKET_SERVICE_ACTION_ATTACH, "MBIM_PACKET_SERVICE_ACTION_ATTACH", "attach" },
    { MBIM_PACKET_SERVICE_ACTION_DETACH, "MBIM_PACKET_SERVICE_ACTION_DETACH", "detach" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_packet_service_state_values[] = {
    { MBIM_PACKET_SERVICE_STATE_UNKNOWN, "MBIM_PACKET_SERVICE_STATE_UNKNOWN", "unknown" },
    { MBIM_PACKET_SERVICE_STATE_ATTACHING, "MBIM_PACKET_SERVICE_STATE_ATTACHING", "attaching" },
    { MBIM_PACKET_SERVICE_STATE_ATTACHED, "MBIM_PACKET_SERVICE_STATE_ATTACHED", "attached" },
    { MBIM_PACKET_SERVICE_STATE_DETACHING, "MBIM_PACKET_SERVICE_STATE_DETACHING", "detaching" },
    { MBIM_PACKET_SERVICE_STATE_DETACHED, "MBIM_PACKET_SERVICE_STATE_DETACHED", "detached" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_activation_command_values[] = {
    { MBIM_ACTIVATION_COMMAND_DEACTIVATE, "MBIM_ACTIVATION_COMMAND_DEACTIVATE", "deactivate" },
    { MBIM_ACTIVATION_COMMAND_ACTIVATE, "MBIM_ACTIVATION_COMMAND_ACTIVATE", "activate" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_compression_values[] = {
    { MBIM_COMPRESSION_NONE, "MBIM_COMPRESSION_NONE", "none" },
    { MBIM_COMPRESSION_ENABLE, "MBIM_COMPRESSION_ENABLE", "enable" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_auth_protocol_values[] = {
    { MBIM_AUTH_PROTOCOL_NONE, "MBIM_AUTH_PROTOCOL_NONE", "none" },
    { MBIM_AUTH_PROTOCOL_PAP, "MBIM_AUTH_PROTOCOL_PAP", "pap" },
    { MBIM_AUTH_PROTOCOL_CHAP, "MBIM_AUTH_PROTOCOL_CHAP", "chap" },
    { MBIM_AUTH_PROTOCOL_MSCHAPV2, "MBIM_AUTH_PROTOCOL_MSCHAPV2", "mschapv2" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_context_ip_type_values[] = {
    { MBIM_CONTEXT_IP_TYPE_DEFAULT, "MBIM_CONTEXT_IP_TYPE_DEFAULT", "default" },
    { MBIM_CONTEXT_IP_TYPE_IPV4, "MBIM_CONTEXT_IP_TYPE_IPV4", "ipv4" },
    { MBIM_CONTEXT_IP_TYPE_IPV6, "MBIM_CONTEXT_IP_TYPE_IPV6", "ipv6" },
    { MBIM_CONTEXT_IP_TYPE_IPV4V6, "MBIM_CONTEXT_IP_TYPE_IPV4V6", "ipv4v6" },
    { MBIM_CONTEXT_IP_TYPE_IPV4_AND_IPV6, "MBIM_CONTEXT_IP_TYPE_IPV4_AND_IPV6", "ipv4-and-ipv6" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_activation_state_values[] = {
    { MBIM_ACTIVATION_STATE_UNKNOWN, "MBIM_ACTIVATION_STATE_UNKNOWN", "unknown" },
    { MBIM_ACTIVATION_STATE_ACTIVATED, "MBIM_ACTIVATION_STATE_ACTIVATED", "activated" },
    { MBIM_ACTIVATION_STATE_ACTIVATING, "MBIM_ACTIVATION_STATE_ACTIVATING", "activating" },
    { MBIM_ACTIVATION_STATE_DEACTIVATED, "MBIM_ACTIVATION_STATE_DEACTIVATED", "deactivated" },
    { MBIM_ACTIVATION_STATE_DEACTIVATING, "MBIM_ACTIVATION_STATE_DEACTIVATING", "deactivating" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_voice_call_state_values[] = {
    { MBIM_VOICE_CALL_STATE_NONE, "MBIM_VOICE_CALL_STATE_NONE", "none" },
    { MBIM_VOICE_CALL_STATE_IN_PROGRESS, "MBIM_VOICE_CALL_STATE_IN_PROGRESS", "in-progress" },
    { MBIM_VOICE_CALL_STATE_HANG_UP, "MBIM_VOICE_CALL_STATE_HANG_UP", "hang-up" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_ip_configuration_available_flag_values[] = {
    { MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_NONE, "MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_NONE", "none" },
    { MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_ADDRESS, "MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_ADDRESS", "address" },
    { MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_GATEWAY, "MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_GATEWAY", "gateway" },
    { MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_DNS, "MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_DNS", "dns" },
    { MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_MTU, "MBIM_IP_CONFIGURATION_AVAILABLE_FLAG_MTU", "mtu" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_storage_state_values[] = {
    { MBIM_SMS_STORAGE_STATE_NOT_INITIALIZED, "MBIM_SMS_STORAGE_STATE_NOT_INITIALIZED", "not-initialized" },
    { MBIM_SMS_STORAGE_STATE_INITIALIZED, "MBIM_SMS_STORAGE_STATE_INITIALIZED", "initialized" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_format_values[] = {
    { MBIM_SMS_FORMAT_PDU, "MBIM_SMS_FORMAT_PDU", "pdu" },
    { MBIM_SMS_FORMAT_CDMA, "MBIM_SMS_FORMAT_CDMA", "cdma" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_flag_values[] = {
    { MBIM_SMS_FLAG_ALL, "MBIM_SMS_FLAG_ALL", "all" },
    { MBIM_SMS_FLAG_INDEX, "MBIM_SMS_FLAG_INDEX", "index" },
    { MBIM_SMS_FLAG_NEW, "MBIM_SMS_FLAG_NEW", "new" },
    { MBIM_SMS_FLAG_OLD, "MBIM_SMS_FLAG_OLD", "old" },
    { MBIM_SMS_FLAG_SENT, "MBIM_SMS_FLAG_SENT", "sent" },
    { MBIM_SMS_FLAG_DRAFT, "MBIM_SMS_FLAG_DRAFT", "draft" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_cdma_lang_values[] = {
    { MBIM_SMS_CDMA_LANG_UNKNOWN, "MBIM_SMS_CDMA_LANG_UNKNOWN", "unknown" },
    { MBIM_SMS_CDMA_LANG_ENGLISH, "MBIM_SMS_CDMA_LANG_ENGLISH", "english" },
    { MBIM_SMS_CDMA_LANG_FRENCH, "MBIM_SMS_CDMA_LANG_FRENCH", "french" },
    { MBIM_SMS_CDMA_LANG_SPANISH, "MBIM_SMS_CDMA_LANG_SPANISH", "spanish" },
    { MBIM_SMS_CDMA_LANG_JAPANESE, "MBIM_SMS_CDMA_LANG_JAPANESE", "japanese" },
    { MBIM_SMS_CDMA_LANG_KOREAN, "MBIM_SMS_CDMA_LANG_KOREAN", "korean" },
    { MBIM_SMS_CDMA_LANG_CHINESE, "MBIM_SMS_CDMA_LANG_CHINESE", "chinese" },
    { MBIM_SMS_CDMA_LANG_HEBREW, "MBIM_SMS_CDMA_LANG_HEBREW", "hebrew" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_cdma_encoding_values[] = {
    { MBIM_SMS_CDMA_ENCODING_OCTET, "MBIM_SMS_CDMA_ENCODING_OCTET", "octet" },
    { MBIM_SMS_CDMA_ENCODING_EPM, "MBIM_SMS_CDMA_ENCODING_EPM", "epm" },
    { MBIM_SMS_CDMA_ENCODING_7BIT_ASCII, "MBIM_SMS_CDMA_ENCODING_7BIT_ASCII", "7bit-ascii" },
    { MBIM_SMS_CDMA_ENCODING_LA5, "MBIM_SMS_CDMA_ENCODING_LA5", "la5" },
    { MBIM_SMS_CDMA_ENCODING_UNICODE, "MBIM_SMS_CDMA_ENCODING_UNICODE", "unicode" },
    { MBIM_SMS_CDMA_ENCODING_SHIFT_JIS, "MBIM_SMS_CDMA_ENCODING_SHIFT_JIS", "shift-jis" },
    { MBIM_SMS_CDMA_ENCODING_KOREAN, "MBIM_SMS_CDMA_ENCODING_KOREAN", "korean" },
    { MBIM_SMS_CDMA_ENCODING_LATIN_HEBREW, "MBIM_SMS_CDMA_ENCODING_LATIN_HEBREW", "latin-hebrew" },
    { MBIM_SMS_CDMA_ENCODING_LATIN, "MBIM_SMS_CDMA_ENCODING_LATIN", "latin" },
    { MBIM_SMS_CDMA_ENCODING_GSM_7BIT, "MBIM_SMS_CDMA_ENCODING_GSM_7BIT", "gsm-7bit" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_status_values[] = {
    { MBIM_SMS_STATUS_NEW, "MBIM_SMS_STATUS_NEW", "new" },
    { MBIM_SMS_STATUS_OLD, "MBIM_SMS_STATUS_OLD", "old" },
    { MBIM_SMS_STATUS_DRAFT, "MBIM_SMS_STATUS_DRAFT", "draft" },
    { MBIM_SMS_STATUS_SENT, "MBIM_SMS_STATUS_SENT", "sent" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_sms_status_flag_values[] = {
    { MBIM_SMS_STATUS_FLAG_NONE, "MBIM_SMS_STATUS_FLAG_NONE", "none" },
    { MBIM_SMS_STATUS_FLAG_MESSAGE_STORE_FULL, "MBIM_SMS_STATUS_FLAG_MESSAGE_STORE_FULL", "message-store-full" },
    { MBIM_SMS_STATUS_FLAG_NEW_MESSAGE, "MBIM_SMS_STATUS_FLAG_NEW_MESSAGE", "new-message" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_ussd_action_values[] = {
    { MBIM_USSD_ACTION_INITIATE, "MBIM_USSD_ACTION_INITIATE", "initiate" },
    { MBIM_USSD_ACTION_CONTINUE, "MBIM_USSD_ACTION_CONTINUE", "continue" },
    { MBIM_USSD_ACTION_CANCEL, "MBIM_USSD_ACTION_CANCEL", "cancel" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_ussd_response_values[] = {
    { MBIM_USSD_RESPONSE_NO_ACTION_REQUIRED, "MBIM_USSD_RESPONSE_NO_ACTION_REQUIRED", "no-action-required" },
    { MBIM_USSD_RESPONSE_ACTION_REQUIRED, "MBIM_USSD_RESPONSE_ACTION_REQUIRED", "action-required" },
    { MBIM_USSD_RESPONSE_TERMINATED_BY_NETWORK, "MBIM_USSD_RESPONSE_TERMINATED_BY_NETWORK", "terminated-by-network" },
    { MBIM_USSD_RESPONSE_OTHER_LOCAL_CLIENT, "MBIM_USSD_RESPONSE_OTHER_LOCAL_CLIENT", "other-local-client" },
    { MBIM_USSD_RESPONSE_OPERATION_NOT_SUPPORTED, "MBIM_USSD_RESPONSE_OPERATION_NOT_SUPPORTED", "operation-not-supported" },
    { MBIM_USSD_RESPONSE_NETWORK_TIMEOUT, "MBIM_USSD_RESPONSE_NETWORK_TIMEOUT", "network-timeout" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_ussd_session_state_values[] = {
    { MBIM_USSD_SESSION_STATE_NEW_SESSION, "MBIM_USSD_SESSION_STATE_NEW_SESSION", "new-session" },
    { MBIM_USSD_SESSION_STATE_EXISTING_SESSION, "MBIM_USSD_SESSION_STATE_EXISTING_SESSION", "existing-session" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_phonebook_state_values[] = {
    { MBIM_PHONEBOOK_STATE_NOT_INITIALIZED, "MBIM_PHONEBOOK_STATE_NOT_INITIALIZED", "not-initialized" },
    { MBIM_PHONEBOOK_STATE_INITIALIZED, "MBIM_PHONEBOOK_STATE_INITIALIZED", "initialized" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_phonebook_flag_values[] = {
    { MBIM_PHONEBOOK_FLAG_ALL, "MBIM_PHONEBOOK_FLAG_ALL", "all" },
    { MBIM_PHONEBOOK_FLAG_INDEX, "MBIM_PHONEBOOK_FLAG_INDEX", "index" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_phonebook_write_flag_values[] = {
    { MBIM_PHONEBOOK_WRITE_FLAG_SAVE_UNUSED, "MBIM_PHONEBOOK_WRITE_FLAG_SAVE_UNUSED", "unused" },
    { MBIM_PHONEBOOK_WRITE_FLAG_SAVE_INDEX, "MBIM_PHONEBOOK_WRITE_FLAG_SAVE_INDEX", "index" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_stk_pac_profile_values[] = {
    { MBIM_STK_PAC_PROFILE_NOT_HANDLED_BY_FUNCTION_HANDLED_BY_HOST, "MBIM_STK_PAC_PROFILE_NOT_HANDLED_BY_FUNCTION_HANDLED_BY_HOST", "not-handled-by-function-handled-by-host" },
    { MBIM_STK_PAC_PROFILE_NOT_HANDLED_BY_FUNCTION_MAY_BE_HANDLED_BY_HOST, "MBIM_STK_PAC_PROFILE_NOT_HANDLED_BY_FUNCTION_MAY_BE_HANDLED_BY_HOST", "not-handled-by-function-may-be-handled-by-host" },
    { MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_ONLY_TRANSPARENT_TO_HOST, "MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_ONLY_TRANSPARENT_TO_HOST", "handled-by-function-only-transparent-to-host" },
    { MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_NOTIFICATION_TO_HOST_POSSIBLE, "MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_NOTIFICATION_TO_HOST_POSSIBLE", "handled-by-function-notification-to-host-possible" },
    { MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_NOTIFICATIONS_TO_HOST_ENABLED, "MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_NOTIFICATIONS_TO_HOST_ENABLED", "handled-by-function-notifications-to-host-enabled" },
    { MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_CAN_BE_OVERRIDEN_BY_HOST, "MBIM_STK_PAC_PROFILE_HANDLED_BY_FUNCTION_CAN_BE_OVERRIDEN_BY_HOST", "handled-by-function-can-be-overriden-by-host" },
    { MBIM_STK_PAC_PROFILE_HANDLED_BY_HOST_FUNCTION_NOT_ABLE_TO_HANDLE, "MBIM_STK_PAC_PROFILE_HANDLED_BY_HOST_FUNCTION_NOT_ABLE_TO_HANDLE", "handled-by-host-function-not-able-to-handle" },
    { MBIM_STK_PAC_PROFILE_HANDLED_BY_HOST_FUNCTION_ABLE_TO_HANDLE, "MBIM_STK_PAC_PROFILE_HANDLED_BY_HOST_FUNCTION_ABLE_TO_HANDLE", "handled-by-host-function-able-to-handle" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_stk_pac_type_values[] = {
    { MBIM_STK_PAC_TYPE_PROACTIVE_COMMAND, "MBIM_STK_PAC_TYPE_PROACTIVE_COMMAND", "proactive-command" },
    { MBIM_STK_PAC_TYPE_NOTIFICATION, "MBIM_STK_PAC_TYPE_NOTIFICATION", "notification" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_network_idle_hint_state_values[] = {
    { MBIM_NETWORK_IDLE_HINT_STATE_DISABLED, "MBIM_NETWORK_IDLE_HINT_STATE_DISABLED", "disabled" },
    { MBIM_NETWORK_IDLE_HINT_STATE_ENABLED, "MBIM_NETWORK_IDLE_HINT_STATE_ENABLED", "enabled" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_emergency_mode_state_values[] = {
    { MBIM_EMERGENCY_MODE_STATE_OFF, "MBIM_EMERGENCY_MODE_STATE_OFF", "off" },
    { MBIM_EMERGENCY_MODE_STATE_ON, "MBIM_EMERGENCY_MODE_STATE_ON", "on" },
    { 0, NULL, NULL },
};

struct mbim_enum mbim_dss_link_state_values[] = {
    { MBIM_DSS_LINK_STATE_DEACTIVATE, "MBIM_DSS_LINK_STATE_DEACTIVATE", "deactivate" },
    { MBIM_DSS_LINK_STATE_ACTIVATE, "MBIM_DSS_LINK_STATE_ACTIVATE", "activate" },
    { 0, NULL, NULL },
};
