// source: https://youtu.be/YG4jexlSAjc?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
#include <chrono>
#include <iostream>
#include <memory>

class Timer {
 public:
  Timer() {
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
    std::cout << duration << "us (" << ms << "ms)" << std::endl;
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time_point;
};
