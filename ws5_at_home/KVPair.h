// Workshop 5 - Functions
// KVPair
// Krystyna Lopez
// 2019/02/19

#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include<iostream>
#include<iomanip>
extern int fieldWidth;
namespace sict {
  template<typename K, typename V>
  class KVPair {
    K key;
    V value;

  public:

    //Default constructor
    //
    KVPair() {};

    //Two argument constructor that stores the received key and value in obj instance variable
    //
    KVPair(const K& new_key, const V& new_value) :key(new_key), value(new_value) {};

    //A templated query that inserts into the output stream
    //
    template<typename F> void display(std::ostream& os, F f) const {
      if (value) {
        os << std::setw(fieldWidth);
        os << std::left << key << std::right << " : " << std::setw(fieldWidth) << value << " " << std::setw(fieldWidth - 1) << f(value) << std::endl;
      }
    }
  };
}
#endif // !SICT_KVPAIR_H
