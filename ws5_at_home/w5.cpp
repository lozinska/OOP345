// Workshop 5 - Functions
// w5.cpp
// Krystyna Lopez
// 2019/02/19

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;



template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
  std::ifstream file(filename);
  if (!file) {
    L list(0);
    return std::move(list);
    exit(3);
  }
  int no_records = 0;
  do {
    char c = file.get();
    if (file.good() && c == '\n') no_records++;
  } while (!file.eof());
  file.clear();
  file.seekg(std::ios::beg);
  L list(no_records);
  do {
    K key;
    V value;
    file >> key;
    if (file) {
      file >> value;
      file.ignore();
      list.push_back(T(key, value));
    }
  } while (file);

  return std::move(list);
}

int main(int argc, char* argv[]) {
  std::cout << "Command Line : ";
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << ' ';
  }
  std::cout << std::endl;

  // check for command line errors
  if (argc != 3) exit(1);

  // set for fixed, 2-decimal point output
  std::cout << std::fixed << std::setprecision(2);

  try {
    // process price list file
    KVList<KVPair<std::string, float>> priceList = createList<
      KVList<KVPair<std::string, float>>,
      KVPair<std::string, float>,
      std::string,
      float>
      (argv[1]);
    std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
    std::cout << "Description:      Price Price+Tax\n";
    priceList.display(std::cout, Taxable(HST));
  }
  catch (const char* msg) {
    std::cout << msg << std::endl;
  }

  try{
    // process student list file
    KVList<KVPair<int, float>> studentList = createList<
      KVList<KVPair<int, float>>,
      KVPair<int, float>,
      int,
      float>
      (argv[2]);
    std::cout << "\nStudent List Letter Grades Included\n===================================\n";
    std::cout << "Student No :      Grade    Letter\n";
    studentList.display(std::cout, [](float i) {
      if (i < 0)
      {
        exit(2);
      }
      else if (i < 50) { return "F "; }
      else if (i < 55 && i >= 50) {
        return "D ";
      }
      else if (i < 60 && i >= 55) {
        return "D+";
      }
      else if (i >= 60 && i < 65) {
        return "C ";
      }
      else if (i >= 65 && i < 70) {
        return "C+";
      }
      else if (i >= 70 && i < 75) {
        return "B ";
      }
      else if (i >= 75 && i < 80) {
        return "B+";
      }
      else if (i >= 80 && i < 90) {
        return "A ";
      }
      else {
        return "A+";
      }
    });
  }
  catch(const char* msg){
    std::cout << msg << std::endl;
  }
}