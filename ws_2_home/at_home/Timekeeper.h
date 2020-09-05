// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// Krystyna Lopez
// 2019/01/25

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <chrono>

namespace sict {

  const int max_num = 10;
  class Timekeeper {
    int num_of_records{ 0 };
    std::chrono::steady_clock::time_point  str_time, end_time;

    struct {
      const char* message;
      const char* time_unit;
      std::chrono::steady_clock::time_point::duration duration;
    }record[max_num];
  public:
    Timekeeper();
    void start();
    void stop();
    void recordEvent(const char*);
    void report(std::ostream&) const;
  };
}
#endif 
