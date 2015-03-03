#include <gtest/gtest.h>

#include <WinSock2.h>
#include <Windows.h>

#include <lily/lily.h>
#include <lily/WinSock.h>


NAME_BGN

TEST(strerror, noError)
{
    EXPECT_STREQ(WinSock::strerror(), "0:The operation completed successfully.\r\n");
}

TEST(strerror, error_10)
{
    SOCKET socket = ::socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port = 111;
    int len = sizeof(addr);
    recvfrom(socket, NULL, 0, 0, (sockaddr*)&addr, &len);
    EXPECT_STREQ(WinSock::strerror(), "10093:Either the application has not called WSAStartup, or WSAStartup failed.\r\n");
}

NAME_END
