#include "Utils.hpp"

void Utils::AllocChar(char *&dest, const char *src) {
  if (src != nullptr) {
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
  } else {
    dest = nullptr;
  }
}

void Utils::ReallocChar(char *&dest, const char *src, bool shouldVerify) {
  if (shouldVerify) {
    if (strlen(src) == 0) {
      std::cout << "[LOG] Invalid input!" << std::endl;
      return;
    } else {
      if (dest != nullptr) {
        delete[] dest;
      }
      AllocChar(dest, src);
    }
  } else {
    if (src != nullptr) {
      delete[] dest;
      dest = new char[strlen(src) + 1];
      strcpy(dest, src);
    } else {
      delete[] dest;
      dest = nullptr;
    }
  }
}

void Utils::ReadFromStdin(char *&dest, std::istream &in) {
  char buffer[256];
  in.getline(buffer, 256);
  ReallocChar(dest, buffer);
}

void Utils::DeallocChar(char *&dest) {
  if (dest != nullptr) {
    delete[] dest;
    dest = nullptr;
  }
}