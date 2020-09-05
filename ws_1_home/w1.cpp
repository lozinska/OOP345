// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Krystyna Lopez
// 2019/01/22

#include"String.h"

using namespace std;
using namespace sict;

//Definition of global variable
//
extern const int INITIAL = 3;

//Main() receives a set of standard command line arguments
//
int main(int arg, char* argv[]) {

  cout << "Command Line : ";

  //Check if number of enetered arguments >1
  //
  if (arg <= 1) {
    cout << "***Insufficient number of arguments***" << endl;
    return 1;
  }

  //Echoes the set of arguments to standard output 
  //
  for (int i = 0; i < arg; i++) {
    cout << argv[i] << " ";
  }
  cout << endl;

  //Calls the process function for each string 
  //
  for (int i = 1; i < arg; i++) {
    process(argv[i]);
  }
  return 0;

}


