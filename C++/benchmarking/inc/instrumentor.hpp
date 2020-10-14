#ifndef INC_INSTRUMENTOR_HPP_
#define INC_INSTRUMENTOR_HPP_

// source: https://youtu.be/xlAH4dbMVnU?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
// This outputs timing data from the Timer class in a JSON format readable by
// Google Chrome tracing

#define PROFILING 0
#if(PROFILING)
#define PROFILE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE(__PRETTY_FUNCTION__)
#else
#define PROFILE(name)
#define PROFILE_FUNCTION()
#endif

#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

struct ProfileResult {
  std::string name;
  long long start, end;
  uint32_t thread_id;
};

struct InstrumentationSession {
  std::string name;
};

class Instrumentor {
 public:
  Instrumentor()
    : current_session(nullptr), profile_count(0) {}
  void begin_session(const std::string& name, const std::string& filepath = "results.json") {
    output_stream.open(filepath);
    write_header();
    current_session = new InstrumentationSession { name };
  }
  void end_session() {
    write_footer();
    output_stream.close();
    delete current_session;
    current_session = nullptr;
    profile_count = 0;
  }

  void write_profile(const ProfileResult& result) {
    if (profile_count++ > 3)  // not sure why 0 doesn't work here
      output_stream << ",";

    std::string name = result.name;
    std::replace(name.begin(), name.end(), '"', '\'');

    output_stream << "{";
    output_stream << "\"cat\":\"function\",";
    output_stream << "\"dur\":" << (result.end - result.start) << ',';
    output_stream << "\"name\":\"" << name << "\",";
    output_stream << "\"ph\":\"X\",";
    output_stream << "\"pid\":0,";
    output_stream << "\"tid\":" << result.thread_id << ",";
    output_stream << "\"ts\":" << result.start;
    output_stream << "}";

    output_stream.flush();
  }

  void write_header() {
    output_stream << "{\"otherData\": {},\"traceEvents\":[";
    output_stream.flush();
  }

  void write_footer() {
    output_stream << "]}";
    output_stream.flush();
  }

  static Instrumentor& get() {
    static Instrumentor instance;
    return instance;
  }

 private:
  InstrumentationSession* current_session;
  std::ofstream output_stream;
  int profile_count;
};

#endif // INC_INSTRUMENTOR_HPP_
