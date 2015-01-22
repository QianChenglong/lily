#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

#include <tchar.h>
#include <WinSock2.h>
#include <IPHlpApi.h>

#include <lily/WinSock.h>


NAME_BGN

WinSock *WinSock::instance_ = NULL;

/**
 * winsock清理工作
 */
WinSock::~WinSock()
{
    WSACleanup();
}

void WinSock::init(uint8_t minor_ver, uint8_t major_ver)
{
    if (WinSock::instance_ != NULL) {
        return;
    }

    WinSock::instance_ = new WinSock;

    if (WinSock::instance_ == NULL) {
        exit(1);
    }

    WSADATA data;
    WORD sock_version = MAKEWORD(minor_ver, major_ver);
    if (WSAStartup(sock_version, &data)) {
        exit(1);
    }
}

WinSock::WinSock()
{

}

NAME_END