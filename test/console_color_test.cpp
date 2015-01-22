#include <gtest/gtest.h>

#include "lily/console_color.h"

NAME_BGN

TEST(console_color, blue) {
    std::cout << blue << "It's blue." << std::endl;
}

TEST(console_color, red) {
    std::cout << red << "It's red." << std::endl;
}

TEST(console_color, green) {
    std::cout << green << "It's green." << std::endl;
}

NAME_END