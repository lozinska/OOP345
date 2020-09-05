// Workshop 2 - Copy and Move Semantics
// Text.cpp
// Krystyna Lopez
// 2019/01/25

#include<iostream>
#include<string>
#include<fstream>
#include"Text.h"

using namespace std;

namespace sict {

  //No-argument default constructor
  //
  Text::Text() {}

  //1-argument constructor
  //
  Text::Text(const std::string& str) {

    new_string = nullptr;
    noString = 0;

    if (!str.empty()) {
      std::string line;
      std::ifstream myfile(str);

      while (std::getline(myfile, line))
      {
        noString++;
      }

      new_string = new std::string[noString];
      myfile.clear();
      myfile.seekg(0);

      int i = 0;
      while (std::getline(myfile, line)) {
        new_string[i] = line;
        i++;
      }
    }
  }

  //A copy constructor
  //
  Text::Text(const Text& src) {
    *this = src;
  }

  //A copy assignment operator
  //
  Text& Text::operator=(const Text& src) {

    if (this != &src) {
      delete[]new_string;
      noString = src.noString;
      new_string = new string[noString];
      for (size_t i = 0; i < noString; i++) {
        new_string[i] = src.new_string[i];
      }
    }
    return *this;
  }

  //Destructor
  //
  Text::~Text() {
    delete[] new_string;
  }

  //A query that returns the number of records 
  //
  size_t Text::size() const {
    return noString;
  }
}