// Workshop 4 - Containers
// MessagePack.h
// Krystyna Lopez
// 2019/02/13

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
#include<iostream>
#include"Message.h"

namespace sict {

  class Message;

  class MessagePack {
    Message* message{ nullptr };
    int num{ 0 };

  public:

    MessagePack();
    ~MessagePack();
    MessagePack(Message**, int);
    MessagePack(const MessagePack&);
    MessagePack& operator=(const MessagePack&);
    MessagePack (MessagePack&&);
    MessagePack& operator=(MessagePack&&);
    void display(std::ostream& os)const;
    size_t size() const;
  };
  std::ostream& operator<<(std::ostream&, const MessagePack&);
}
#endif