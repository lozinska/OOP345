// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.h
//Krystyna Lopez

#ifndef SICT_STRING_H
#define  SICT_STRING_H
#include<iostream>
#include"process.h"

namespace sict {

  const int MAX = 3;

  class String {
    char str[MAX + 1];

  public:
    String(const char*);
    void display(std::ostream&) const;
  };

  std::ostream& operator<<(std::ostream&, const String&);
}
#endif 
