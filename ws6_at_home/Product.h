// Workshop 6 - STL Containers
// Product.h
// Krystyna Lopez
// 2019/03/12

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include"iProduct.h"

namespace sict {
  enum tax_status { HST, PST };

  class Product :public iProduct {
    int productNo{ 0 };
    double prod_price{ 0 };

  public:
    Product(int, double);
    double price() const;
    void display(std::ostream& os)const;
  };
  class TaxableProduct :public Product {
    tax_status status;
  public:
    TaxableProduct(tax_status, int, double);
    double price() const;
    void display(std::ostream& os) const;
   // iProduct* readRecord(std::ifstream& file);
  };
}
#endif // !SICT_PRODUCT_H
