// Workshop 5 - Functions
// Taxable.h
// Krystyna Lopez
// 2019/02/19

#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H
namespace sict {
  class Taxable {
    float tax;
  public:
    Taxable(float new_tax) :tax(new_tax) {};
    float operator()(float price) { return price * (1 + tax); };
  };
}
#endif // !SICT_TAXABLE_H
