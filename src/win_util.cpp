#include <stdio.h>

#include <Windows.h>

#include <lily/win_util.h>


NAME_BGN

namespace win_util{

char* strerror()
{
    return strerror(GetLastError());
}

char* strerror(int errcode)
{
    static char msg[1024];
    char *errmsg;
    DWORD  result = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        errcode,
        MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
        (LPSTR)&errmsg,
        0,
        NULL);
    if (result == 0) {
        sprintf(msg, "Format message failed with %#x", GetLastError());
    } else {
        _snprintf_s(msg, sizeof(msg), _TRUNCATE, "%d:%s", errcode, errmsg);
        LocalFree(errmsg);
    }

    return msg;
}

}

NAME_END
