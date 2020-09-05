// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.h
//Krystyna Lopez
// 2019/01/22

#ifndef SICT_STRING_H
#define  SICT_STRING_H
#include<iostream>
#include"process.h"

namespace sict {

  const int MAX = 3;

  class String {

    char* str=nullptr;

  public:

    String(const char*);
    void display(std::ostream&) const;
    ~String();
  };

  std::ostream& operator<<(std::ostream&, const String&);
}
#endif 
