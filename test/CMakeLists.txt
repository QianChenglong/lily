enable_testing()

utest_link(gtest gtest_main ${PROJECT_NAME})

add_utest(console_color)
add_utest(inet_helper)
add_utest(Error)
