// Workshop 2 - Copy and Move Semantics
// Timekeeper.cpp
// Krystyna Lopez
// 2019/01/25

#include<iostream>
#include<iomanip>
#include"Timekeeper.h"

using namespace std;
namespace sict {

  //Default no-argument constructor
  //
  Timekeeper::Timekeeper() {}

  //Modifier that starts the stopwatch for an event
  //
  void Timekeeper::start() {
    str_time= std::chrono::steady_clock::now();
  }

  //Modifier that stops the stopwatch for an event
  void Timekeeper::stop() {
    end_time = std::chrono::steady_clock::now();
  }

  //Function that copies the address of the description and calculates the duration of the event 
  //
  void Timekeeper::recordEvent(const char* description) {

     record[num_of_records].message = description;
     record[num_of_records].time_unit = "seconds";
     record[num_of_records].duration = end_time-str_time;

      num_of_records++;
  }

  //A query that , inserts the title into the object and inserts and inserts the time record stored in the object
  //
  void Timekeeper::report(ostream& os) const {

    os << "\nExecution Times:" << endl;

    for (int i = 0; i < num_of_records; i++) {
    os << record[i].message <<setw(5)<< record[i].duration.count()/1000000 <<" "<< record[i].time_unit << endl;
    }
  }
 
}