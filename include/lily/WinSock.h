#pragma once


#include <stdint.h>

#include "defs.h"


NAME_BGN

/**
 * 初始化WinSock2
 */
class WinSock
{
public:
    /**
     * 初始化winsock
     * @param [in] minor_ver 次版本号
     * @param [in] major_ver 主版本号
     */
    static void init(uint8_t minor_ver = 2, uint8_t major_ver = 2);

    ~WinSock();

public:
    /**
     * 返回winsock错误信息字符串
     */
    static char* strerror();

private:
    WinSock();

private:
    static WinSock *instance_;
};

NAME_END
