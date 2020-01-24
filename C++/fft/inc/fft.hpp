#ifndef FFT_HPP
#define FFT_HPP

#include <complex>
#include <vector>

using namespace std;

vector<complex<double>>& fft(vector<complex<double>>&, size_t);
void print_coeffs(vector<complex<double>>*, size_t n);

#endif
