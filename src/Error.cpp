#include <lily/Error.h>

NAME_BGN

static const char *error_tables[] = {
    "no error",
    "error test",
    "invalid arguments",
    "name resolove fail",
    ""
};


extern const char *strerror(unsigned int error_code)
{
    if (error_code > sizeof(error_tables) / sizeof(char *)) {
        return "no such error";
    }
    return error_tables[error_code];
}

NAME_END