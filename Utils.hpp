#pragma once
#include <iostream>
#include <string.h>

class Utils {
public:
    static void AllocChar(char*&, const char*);
    static void ReallocChar(char*&, const char*, bool = false);
    static void ReadFromStdin(char*&, std::istream&);
    static void DeallocChar(char*&);
};
