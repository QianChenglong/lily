#pragma once


#include "defs.h"
#include "Error.h"


NAME_BGN

#ifndef DEF_ERROR_OK
#define DEF_ERROR_OK
ERR_DEF(ERROR_OK, 0, "no error");
#endif

ERR_DEF(ERROR_TEST, 1, "error test");

ERR_DEF(ERROR_INVALID_ARGUMENTS, 1000, "invalid arguments");
ERR_DEF(ERROR_NAME_RESOLVE_FAIL, 1001, "name resolove fail");

NAME_END
