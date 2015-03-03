#pragma once


#include <stdint.h>

#include "defs.h"


NAME_BGN

/**
 * ��ʼ��WinSock2
 */
class WinSock
{
public:
    /**
     * ��ʼ��winsock
     * @param [in] minor_ver �ΰ汾��
     * @param [in] major_ver ���汾��
     */
    static void init(uint8_t minor_ver = 2, uint8_t major_ver = 2);

    ~WinSock();

public:
    /**
     * ����winsock������Ϣ�ַ���
     */
    static char* strerror();

private:
    WinSock();

private:
    static WinSock *instance_;
};

NAME_END
