// Workshop 6 - STL Containers
// Product.cpp
// Krystyna Lopez
// 2019/03/12

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
    os << Product::price();
  }

  //Helper function
  //
  std::ostream& operator<<(std::ostream& os, const iProduct& p) {
    p.display(os);
    return os;
  }

  //Three argument constructor
  //
  TaxableProduct::TaxableProduct(tax_status tax, int num, double pr_price) :Product(num, pr_price) {
    if (tax == HST) {
      status =tax_status:: HST;
    }
    if (tax == PST) {
      status = tax_status::PST;
    }
  }

  //a query that returns the price of a product tax included
  //
  double TaxableProduct::price() const {
    double prc;
    if (status == HST) {
     prc=Product::price()*1.13;
    }
    if (status == PST) {
prc=Product::price()*1.08;
    }
    return prc;
  }

  //– a query that displays the information about the product 
  //
  void TaxableProduct::display(std::ostream& os) const {
    switch (status) {
    case HST:
      os << '\n';
      Product::display(os);
      os <<" HST" << std::endl;
      break;
    case PST:
     // os << '\n';
      Product::display(os);
      os << " PST"<<std::endl;
      break;
    default:
      os << '\n';
      Product::display(os);
    
    }
  }

  //Function reads a single record from file 
 //
  iProduct* readRecord(std::ifstream& file) {
    tax_status s;
    char sts;
    iProduct* iproduct = nullptr;
    double price;
    int number;
    file >> number >> price;

    if (file.get()!='\n') {
      file >> sts;

      if (sts == 'H') {
       s =tax_status::HST;
      }
      else {
        s = tax_status::PST;
      }
      iproduct = new TaxableProduct(s, number, price);
    }

    else {
      iproduct = new Product(number, price);
    }
    return iproduct;
  }

}