// Workshop 5 - Functions
// KVList.h
// Krystyna Lopez
// 2019/02/15

#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H
#include"KVPair.h"
namespace sict {
  template<typename T>
  class KVList {

    T* objects{nullptr};
    size_t number{ 0 };
    size_t count{ 0 };

  public:

    //default constructor
    //
    KVList() {};

    //a single-argument constructor that receives the number of objects 
    //
    KVList(int n) {
      if (n >0) {
        number = n;
        objects = new T[number];
      }
     
    }

    //A move constructor
    //
    KVList(KVList&& kvlist) {

      objects = nullptr;
      objects = kvlist.objects;
      number = kvlist.number;
      count = kvlist.count;
      kvlist.objects = nullptr;
      kvlist.number = 0;
      kvlist.count = 0;

    }
 
    //Destructor
    //
    ~KVList() {
      delete[] objects;
    }

    //a subscripting operator that returns an unmodifiable reference 
    //
    const T& operator[](size_t i)const {
      return objects[i];
    }

    //a templated query that inserts into the output stream
    //
    template<typename F> void display(std::ostream& os, F f) const {
      if (objects != nullptr) {
        for (size_t i = 0; i < count; i++) {
          objects[i].display(os,f);
        }
      }
    }

    //a modifier that adds the object t to the list
   void push_back(const T& t) {
     if (count < number) {
       objects[count]= t;
       count++;
     }
    }
  };
}
#endif // !SICT_KVLIST_H
