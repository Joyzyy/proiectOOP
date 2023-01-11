#pragma once
#include <string.h>

#include <ctime>
#include <iostream>

// @todo to namespace
class Utils {
 public:
  static void AllocChar(char*&, const char*);
  static void ReallocChar(char*&, const char*, bool = false);
  static void ReadFromStdin(char*&, std::istream&);
  static void DeallocChar(char*&);

  // static void CheckDate();
};
