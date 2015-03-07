#include <gtest/gtest.h>

#include <lily/win_util.h>


NAME_BGN

TEST(strerror, noError)
{
    printf("%s", win_util::strerror());
    EXPECT_STREQ(win_util::strerror(), "0:The operation completed successfully.\r\n");
}

NAME_END
