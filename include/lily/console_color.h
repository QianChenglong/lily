#pragma once


#include <iostream>

#include <windows.h>

#include "defs.h"


NAME_BGN

#ifdef _WIN32
std::ostream& blue(std::ostream &s);
std::ostream& red(std::ostream &s);
std::ostream& green(std::ostream &s);
#endif // _WIN32

NAME_END
