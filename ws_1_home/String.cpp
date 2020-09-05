// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.cpp
// Krystyna Lopez
// 2019/01/22

#include<cstring>
#include"String.h"

using namespace std;

extern const int INITIAL; //declaration of global variable that declared in in the w1

namespace sict {

  static int i=INITIAL; //using static in order to update the value of i

  //One argument constructor
  //
  String::String(const char* string) {

    if (string != nullptr&&string[0] != '\0') {
      delete[]str;
      int size = strlen(string);
      str = new char[size+1];
      strcpy(str, string);
    }
  }

  //A query that inserts the string stored in the instance variable 
  //
  void String::display(ostream& os) const {

    if (str != nullptr&&str[0] != '\0') {
      os << str;
    }
  }

  //Destructor
  //
  String::~String() {
    delete[]str;
  }
 
  //A helper non-friend operator that inserts the saved string into the left operand
  //
  ostream& operator<<(ostream& os, const String& string) {

    os << i << ": ";
    string.display(os);
    i++;

    return os;
  }
}