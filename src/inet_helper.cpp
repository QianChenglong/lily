#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>

#include <tchar.h>
#include <WinSock2.h>
#include <Windows.h>
#include <IPHlpApi.h>

#include <lily/lily.h>
#include <lily/inet_helper.h>
#include <lily/WinSock.h>


NAME_BGN

bool getGateway(const char *adapter_uuid, char *gateway)
{
    PIP_ADAPTER_INFO pAdapterInfo = NULL;
    // Make an initial call to GetAdaptersInfo to get
    // the necessary size into the ulOutBufLen variable
    ULONG ulOutBufLen = 0;

    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        pAdapterInfo = (IP_ADAPTER_INFO *) malloc(ulOutBufLen);

        if (pAdapterInfo == NULL) {
            printf("Error allocating memory needed to call GetAdaptersinfo\n");
            return false;
        }
    }

    DWORD dwRetVal = 0;

    // 若获取失败
    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) != NO_ERROR) {
        printf("GetAdaptersInfo failed with error: %d\n", dwRetVal);

        return false;
    }

    // 查询目标适配器
    PIP_ADAPTER_INFO pAdapter = pAdapterInfo;

    while (pAdapter) {
        if (strcmp(pAdapter->AdapterName, adapter_uuid) == 0) {
            break;
        }

        pAdapter = pAdapter->Next;
    }

    if (pAdapter != NULL) {
        assert(gateway != NULL);
        sprintf(gateway, pAdapter->GatewayList.IpAddress.String);
        free(pAdapterInfo);
        return true;
    } else {
        return false;
    }
}

bool getDeviceIP(const char *adapter_uuid, char *ip)
{
    /**
     * 返回windows错误字符串
     */
    PIP_ADAPTER_INFO pAdapterInfo = NULL;
    // Make an initial call to GetAdaptersInfo to get
    // the necessary size into the ulOutBufLen variable
    ULONG ulOutBufLen = 0;

    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        pAdapterInfo = (IP_ADAPTER_INFO *) malloc(ulOutBufLen);

        if (pAdapterInfo == NULL) {
            printf("Error allocating memory needed to call GetAdaptersinfo\n");
            return false;
        }
    }

    DWORD dwRetVal = 0;

    // 若获取失败
    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) != NO_ERROR) {
        printf("GetAdaptersInfo failed with error: %d\n", dwRetVal);

        return false;
    }

    // 查询目标适配器
    PIP_ADAPTER_INFO pAdapter = pAdapterInfo;

    while (pAdapter) {
        if (strcmp(pAdapter->AdapterName, adapter_uuid) == 0) {
            break;
        }

        pAdapter = pAdapter->Next;
    }

    if (pAdapter != NULL) {
        assert(ip != NULL);
        sprintf(ip, "%s", pAdapter->IpAddressList.IpAddress.String);
        free(pAdapterInfo);
        return true;
    } else {
        return false;
    }
}

int name2ip(const char *hostname, char *ip)
{
    WinSock::init();

    if (hostname == NULL || ip == NULL) {
        return ERROR_INVALID_ARGUMENTS;
    }

    hostent *ent = gethostbyname(hostname);
    if (ent == NULL) {
        return ERROR_NAME_RESOLVE_FAIL;
    }
    in_addr addr;
    memcpy(&addr.S_un.S_addr, ent->h_addr_list[0], ent->h_length);
    strcpy(ip, inet_ntoa(addr));

    return ERROR_OK;
}

NAME_END