// Workshop 8 - Smart Pointers
// Utilities.cpp
// Krystyna Lopez
// 2019/03/22

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
  List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
    List<Product> priceList;

    // code to build a list of products using raw pointers
    //
    for (size_t i = 0; i < desc.size(); i++) {
      for(size_t j=0;j<price.size();j++)
      if (desc[i].code==price[j].code) {
        Product* temp(new Product(desc[i].desc, price[j].price));
        temp->validate();
        priceList += temp;
        delete temp;
        temp = nullptr;
      }
    }


    return priceList;
  }
}