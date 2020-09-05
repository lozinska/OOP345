// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Krystyna Lopez
// 2019/01/22

#include <iostream>
#include "String.h"

namespace sict {
  void process(const char* str) {
    String a = String(str);
    std::cout << a << std::endl;
  }
}