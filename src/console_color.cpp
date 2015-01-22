#pragma once


#include <iostream>

#include <windows.h>

#include "lily/console_color.h"


NAME_BGN

std::ostream& blue(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
        |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

std::ostream& red(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

std::ostream& green(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
        FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

NAME_END