#include <gtest/gtest.h>

#include <lily/lily.h>

NAME_BGN

int error_test()
{
    return ERROR_TEST;
}

TEST(Error, ERROR_TEST)
{
    EXPECT_EQ(ERROR_TEST, error_test());
    EXPECT_STREQ(Error::toString(ERROR_TEST).c_str(), "error test");
}

TEST(Error, ERROR_INVALID_ARGUMENTS)
{
    EXPECT_STREQ(Error::toString(ERROR_INVALID_ARGUMENTS).c_str(), "invalid arguments");
}

NAME_END
