#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "fft.hpp"
#include <complex>

using namespace std;

TEST_CASE("", "[]"){
  vector<complex<double>> sample_buffer(4);

  for (int i = 0; i < 4; i++) {
    complex<double> c_num(i, 0);
    sample_buffer[i] = c_num;
  }
  vector<complex<double>> &output_vector = fft(sample_buffer, 4);

  REQUIRE(output_vector[0] == 6.0);
}
