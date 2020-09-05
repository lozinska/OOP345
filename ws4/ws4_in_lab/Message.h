// Workshop 4 - Containers
// Message.h
// Krystyna Lopez
// 2019/02/08

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include<string>
#include<iostream>

namespace sict {
  class Message {
    std::string user;
    std::string text;
    std::string reply;

  public:
    Message();
    Message(const std::string&);
    bool empty() const;
    void display(std::ostream&) const;
  };
}
#endif // !SICT_MESSAGE_H
