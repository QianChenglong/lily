#include <gtest/gtest.h>

#include <lily/lily.h>
#include <lily/error.h>

NAME_BGN

int error_test()
{
    return ERROR_TEST;
}

TEST(Error, strerror)
{
    EXPECT_STREQ(strerror(ERROR_OK), "no error");
    EXPECT_STREQ(strerror(ERROR_TEST), "error test");
    EXPECT_STREQ(strerror(ERROR_INVALID_ARGUMENTS), "invalid arguments");
    EXPECT_STREQ(strerror(ERROR_NAME_RESOLVE_FAIL), "name resolove fail");
}

TEST(Error, error_code)
{
    EXPECT_EQ(ERROR_TEST, error_test());
}

NAME_END
