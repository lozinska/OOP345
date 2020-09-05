// Workshop 6 - STL Containers
// Product.h
// Krystyna Lopez
// 2019/03/08

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include"iProduct.h"

namespace sict {

  class Product:public iProduct {
    int productNo{ 0 };
    double prod_price{ 0 };

  public:
    Product(int, double);
    double price() const;
    void display(std::ostream& os)const;
  };
}
#endif // !SICT_PRODUCT_H
