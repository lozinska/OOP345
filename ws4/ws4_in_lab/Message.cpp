// Workshop 4 - Containers
// Message.cpp
// Krystyna Lopez
// 2019/02/08

#include"Message.h"
using namespace std;

namespace sict {

  //Default constructor
  //
  Message::Message() {
    text = " ";
    reply = " ";
    user = " ";
  };

  //One-Argument Constructor that receives a reference to an unmodifiable string and parses the string into three substrings
  //
  Message::Message(const string& str){
    if (str != " ") {

      size_t found = str.find(" ");
      size_t found1 = str.find("@");
      size_t found2 = str.find('\n');
      std::string sbstr;

      if (found != string::npos&&found1 != string::npos&&found2 == string::npos) {

        user = str.substr(0, found);
        sbstr = str.substr(str.find(" ") + 1, str.find('\n'));
        reply = sbstr.substr(sbstr.find("@") + 1, sbstr.find(" ") - 1);
        text = sbstr.substr(reply.length() + 2, sbstr.find('\n'));

      }
      else

        if (found != string::npos&&found2 == string::npos)
        {
          user = str.substr(0, str.find(" "));
          reply = "";
          text = str.substr(user.length() + 1, str.find('\n'));
        }
        else {
          *this = Message();
        }
    }
    else {
      *this = Message();
    }
  }

  //A query that returns true if the current object is in a safe empty state
  //
  bool Message::empty() const {

    bool value = false;
    if (user == " "||text == " ")
      value = true;
    return value;
  }

  //A query that inserts into the output stream os the message
  //
  void Message::display(std::ostream& os) const {
    if (!empty()) {
      os << ">User  : " << user<<endl;
     if (reply != "") {
      os << " Reply : " << reply << endl;
      }
      os << " Tweet : " << text << endl;
    }
  }
 
}