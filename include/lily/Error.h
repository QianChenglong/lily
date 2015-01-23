#pragma once


#include <lily/defs.h>


NAME_BGN

enum ErrorCode {
    ERROR_OK = 0,
    ERROR_TEST,
    ERROR_INVALID_ARGUMENTS,
    ERROR_NAME_RESOLVE_FAIL,
    ERROR_NULL
};

extern const char* strerror(unsigned int error_code);

NAME_END
