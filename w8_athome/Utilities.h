#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
// Workshop 8 - Smart Pointers
// Utilities.h
// Krystyna Lopez
// 2019/03/26

#include "List.h"
#include "Element.h"

namespace sict {
  List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
  List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif