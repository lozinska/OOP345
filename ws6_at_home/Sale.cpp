// Workshop 6 - STL Containers
// Sale.cpp
// Krystyna Lopez
// 2019/03/12

#include"Sale.h"
extern int FW;
namespace sict {

  //Single argument constructor
  //
  Sale::Sale(const char* file) {

    std::ifstream output(file);
    iProduct* p;
    if (!output) {
      throw "No file";
    }

    while (output) {
      p = readRecord(output);
      if (output) {
        product.push_back(p);
      }
    }

  }

  //Query that displays the products that make up the sale 
  //
  void Sale::display(std::ostream& os) const {
    double sum = 0;
    os << "Product No" << std::setw(FW) << "Cost" << " Taxable"<<std::endl;
    for (auto i : product) {
      i->display(os);
      sum += i->price();
    }
    os<<'\n' << std::setw(FW) << "Total" << std::setw(FW) << sum << std::endl;
  }

}