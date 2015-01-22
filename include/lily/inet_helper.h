#pragma once


#include "defs.h"


NAME_BGN

/**
 * 获取网卡的网关
 * @param [in] apapter_uuid 网卡的UUID
 * @param [out] gateway 网关
 */
bool getGateway(const char *adapter_uuid, char *gateway);

/**
 * 获取网卡的IP
 * @param [in] adapter_uuid 网卡的UUID
 * @param [out] ip 网卡的IP
 */
bool getDeviceIP(const char *adapter_uuid, char *ip);

/**
 * 获取域名对应的IP
 * @param [in] hostname 域名
 * @param [out] ip 对应的首个IP
 */
int name2ip(const char *hostname, char *ip);

NAME_END