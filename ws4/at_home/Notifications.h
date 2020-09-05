// Workshop 4 - Containers
// Notifications.h
// Krystyna Lopez
// 2019/02/13

#ifndef SICT_NOTIFICATION_H
#define SICT_NOTIFICATION_H
#include<iostream>
#include"MessagePack.h"
#include"Message.h"

namespace sict {

  class Message;

  class Notifications {

    const Message** mess {nullptr};
    int max_num=0 ;
    int currentNum=0 ;

  public:

    Notifications();
    Notifications(int);
    Notifications(const Notifications&);
    Notifications& operator=(const Notifications&);
    Notifications(Notifications&&);
    Notifications& operator=(Notifications&&);
    Notifications& operator+=(const Message&);
    Notifications& operator-=(const Message&);
    void display(std::ostream& os) const;
    size_t size() const;
    ~Notifications();
  };

  std::ostream& operator<<(std::ostream&, const Notifications&);


}
#endif