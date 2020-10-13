// source: https://youtu.be/YG4jexlSAjc?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <chrono>
#include <iostream>
#include <memory>

#include "instrumentor.hpp"

class Timer {
public:
  Timer(const char* name) : name(name) {
    start_time_point = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
    stop();
  }

  void stop() {
    auto end_time_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time_point).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch().count();
    auto duration = end - start;
    double ms = duration * 0.001;
    //std::cout << name << " : " << duration << "us (" << ms << "ms)" << std::endl;
    Instrumentor::get().write_profile({ name, start, end });
  }

private:
  const char* name;
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time_point;
};


#endif  // UTILS_CPP_INC_INSTRUMENTOR_HPP_
