// Workshop 6 - STL Containers
// iProduct.h
// Krystyna Lopez
// 2019/03/12

#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>

extern int FW;

namespace sict {

  class iProduct {
  public:
    virtual double price() const = 0;
    virtual void display(std::ostream& os) const = 0;
  };

  iProduct* readRecord(std::ifstream& file);
  std::ostream& operator<<(std::ostream& os, const iProduct& p);
}
#endif // !SICT_IPRODUCT_H
