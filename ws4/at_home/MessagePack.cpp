// Workshop 4 - Containers
// MessagePack.cpp
// Krystyna Lopez
// 2019/02/13

#include"MessagePack.h"

namespace sict {

  //Default constructor
  //
  MessagePack::MessagePack() {};

  //Destructor
  //
  MessagePack::~MessagePack() {
    delete[] message;
  }

  //Copy constructor
  //
  MessagePack::MessagePack(const MessagePack& msgPk) {
    *this = msgPk;
  }

  //Copy assignment operator
  //
  MessagePack& MessagePack:: operator=(const MessagePack& msgPk) {
    if (this != &msgPk) {
      delete[] message;
      num = msgPk.num;
      message = new Message(*msgPk.message);
  }
    return *this;
  };

  //Two argument constructor that allocates dynamic memory for the specified number of Message objects
  //
  MessagePack::MessagePack(Message** msg, int numEl) {

    if (numEl > 0&&msg!=nullptr) {
     message = new Message[numEl];
     for (int i = 0; i < numEl; i++) {
       if (!msg[i]->empty()) {
         message[i] = *msg[i];
         num++;
       }
    }
    }

    else {
      *this = MessagePack();
    }
  }

  //A query that inserts into output stream
  //
  void MessagePack::display(std::ostream& os)const {
    if (message != nullptr) {
      for (int i = 0; i <= num; i++) {
        message[i].display(os);
      }
    }
  }

  //A query that returns the number of Message objects
  //
  size_t MessagePack:: size() const {
    return num;
  }

  //Move constructor
  //
  MessagePack::MessagePack(MessagePack&& msgPk) {
    *this = std::move(msgPk);
  }

  //Move assignment operator
  //
  MessagePack& MessagePack::operator=(MessagePack&& msgPk) {
    if (this != &msgPk) {
      delete[] message;
      message = msgPk.message;
      num = msgPk.num;
      msgPk.message = nullptr;
      msgPk.num = 0;
    }
    return *this;
  }

  //non friend helper function
  //
  std::ostream& operator<<(std::ostream& os, const MessagePack& msgPk) {
    msgPk.display(os);
    return os;
  }
}