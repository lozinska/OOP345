// Workshop 2 - Copy and Move Semantics
// Text.h
// Krystyna Lopez
// 2019/01/25

#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include<fstream>

namespace sict {

  class Text {
    std::string* new_string = nullptr;
    size_t noString{ 0 };
  public:
    Text();
    Text(const std::string&);
    Text(const Text&);
    Text(Text&&);
    Text& operator=(const Text&);
    Text& operator=(Text&&);
    ~Text();
    size_t size() const;
  };
}
#endif 
