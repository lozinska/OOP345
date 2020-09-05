// Workshop 4 - Containers
// w4.cpp
// Krystyna Lopez
// 2019/02/13

#include"Notifications.h"

namespace sict {

  //Default constructor
  //
  Notifications::Notifications() {};
  
  //A one argument constructor that dynamically allocate memory for the specified number of pointers
  //
  Notifications::Notifications(int mxNum):max_num(mxNum) {
    if (max_num > 0) {
      mess = new const Message*[max_num];
  }
    else *this = Notifications();
  };

  //Copy constructor
  //
  Notifications::Notifications(const Notifications& note) : mess(new const Message*[note.max_num]) {
    *this = note;
  };

  //Copy assignment operator
  //
  Notifications& Notifications:: operator=(const Notifications& note){
    if (this != &note) {
      delete[] mess;
      mess = new const Message*(*note.mess);
      max_num = note.max_num;
      currentNum = note.currentNum;
    }
    return *this;
  };

  //Move constructor
  //
  Notifications::Notifications(Notifications&& note) {
    *this = std::move(note);
  };

  //Move assignment operator
  //
  Notifications& Notifications::operator=(Notifications&& note) {
    if (this != &note) {
      delete[] mess;
      mess = note.mess;
      max_num = note.max_num;
      currentNum = note.currentNum;
      note.mess = nullptr;
      note.max_num = 0;
      note.currentNum = 0;
  }
    return *this;
  };

  //A modifier that receives a reference to an unmodifiable Message object
  //
  Notifications& Notifications::operator+=(const Message& msg) {
    if (!msg.empty() && currentNum <= max_num) {
      mess[currentNum++] = &msg;

    }
    return *this;
  };

  //A modifier that receives a reference to an unmodifiable Message object
  //
  Notifications& Notifications::operator-=(const Message&msg) {
    bool found = false;
    int i;
    for (i = 0; i < currentNum && !found; i++) {
      if (mess[i] == &msg)
      {
        found = true;
      }
    }
      if (found) {
        for (; i < currentNum; i++) {
          mess[i - 1] = mess[i];
        }
        if (currentNum) {
          mess[currentNum - 1] = nullptr;
          currentNum--;
        }
    }
    return *this;
  };

  //A query that inserts into os stream
  //
  void Notifications::display(std::ostream& os) const {
    if (currentNum!=0&&mess!=nullptr) {
      for (int i = 0; i < currentNum; i++) {
        mess[i]->display(os);
      }
    }
  };

  //A query that returns the number of Message objects pointed to by the current object
  //
  size_t Notifications::size() const {
    return currentNum;
  };

  //Destructor
  //
  Notifications::~Notifications() {
    delete[] mess;
  }

  //Non-friend helper function
  //
  std::ostream& operator<<(std::ostream& os, const Notifications& note) {
    note.display(os);
    return os;
  };

}