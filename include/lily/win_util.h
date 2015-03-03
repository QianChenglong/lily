#pragma once


#include "defs.h"


NAME_BGN

namespace win_util {

/**
 * 返回windows错误信息字符串
 */
char* strerror();

/**
 *  返回对应错误代码的信息字符串
 */
char* strerror(int errcode);

}

NAME_END
