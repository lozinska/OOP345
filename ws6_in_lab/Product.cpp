// Workshop 6 - STL Containers
// Product.cpp
// Krystyna Lopez
// 2019/03/08

#include"Product.h"
extern int FW;

namespace sict {

  //Constructor that receives and stores the product number and its price before tax
  //
  Product::Product(int pr_num, double prc) {
    productNo = pr_num;
    prod_price = prc;
  }

  //Query that returns the price of a product
  //
  double Product::price() const {
    return prod_price;
  }

  //Query that displays the information about the product
  //
  void Product::display(std::ostream& os) const {
    os << std::setw(FW) << productNo << std::setw(FW);
    os.setf(std::ios::fixed);
    os.precision(2);
    os<<prod_price << std::endl;
  }

  //function that reads a single record from file
  //
  iProduct* readRecord(std::ifstream& file) {
    iProduct* iproduct = nullptr;
    double price;
    int number;
    file >> number >> price;
    iproduct = new Product(number, price);
    return iproduct;
    
  }

  //Helper function
  //
  std::ostream& operator<<(std::ostream& os, const iProduct& p) {
    p.display(os);
    return os;
  }
 
}