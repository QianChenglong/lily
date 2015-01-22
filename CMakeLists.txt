cmake_minimum_required(VERSION 3.0)

option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." OFF)

# 项目名称
project(lily)

include(cmake/internal_utils.cmake)

config_cmake()

# 宏定义
add_definitions(-DWIN32 -D_WINDOWS -DUNICODE /wd"4819" /wd"4996")

use_library(. gtest-1.7.0-lib-msvcprt)

# 递归处理
add_subdirectory(src)
add_subdirectory(test)

# 安装
install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY lib/ DESTINATION lib)
