#include <gtest/gtest.h>

#include <lily/lily.h>
#include <lily/inet_helper.h>

NAME_BGN

//TEST(getGateway, InvalidUUID)
//{
//    char gateway[256];
//    EXPECT_FALSE(getGateway("111", gateway));
//}
//
//TEST(getGateway, ValidUUID)
//{
//    char gateway[256];
//    EXPECT_TRUE(getGateway("2A7DEE95-B437-444C-BB09-85E4EAD5E61C", gateway));
//}
//
//TEST(getGateway, MultiGateWay)
//{
//    char gateway[256];
//    EXPECT_TRUE(getGateway("{3DF11E58-F6A1-4B92-AF00-E74CB25B4DF2}", gateway));
//}
//
//
//TEST(getDeviceIP, InvalidUUID)
//{
//    char gateway[256];
//    EXPECT_FALSE(getDeviceIP("111", gateway));
//}
//
//TEST(getDeviceIP, ValidUUID)
//{
//    char gateway[256];
//    EXPECT_TRUE(getDeviceIP("2A7DEE95-B437-444C-BB09-85E4EAD5E61C", gateway));
//}
//
//TEST(getDeviceIP, MultiIP)
//{
//    char gateway[256];
//    EXPECT_TRUE(getDeviceIP("{3DF11E58-F6A1-4B92-AF00-E74CB25B4DF2}", gateway));
//}

TEST(name2ip, localhost)
{
    char ip[16];
    EXPECT_EQ(name2ip("localhost", ip), ERROR_OK);
    EXPECT_STREQ(ip, "127.0.0.1");
}

//TEST(name2ip, non_exist)
//{
//    char ip[16];
//    EXPECT_EQ(name2ip("local", ip), (int)ERROR_NAME_RESOLVE_FAIL);
//}
//
//TEST(name2ip, domain)
//{
//    char ip[16];
//    EXPECT_EQ(name2ip("jd.com", ip), (int)ERROR_OK);
//    EXPECT_STREQ(ip, "211.152.122.55");
//}
//
//TEST(name2ip, domain1)
//{
//    char ip[16];
//    EXPECT_EQ(name2ip("img2.wifi.com", ip), (int)ERROR_OK);
//    EXPECT_STREQ(ip, "192.192.192.243");
//}

NAME_END