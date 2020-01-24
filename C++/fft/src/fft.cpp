#include "../inc/fft.hpp"
#include <iostream>
#include <complex>
#include <math.h>
#include <vector>

using namespace std;

vector<complex<double>>& fft(vector<complex<double>>&coeff_vector, size_t n) {
  cout << "Recursive call. N: " << n << endl;
  if (n == 1) return coeff_vector;

  const complex<double> ci(0,1);
  complex<double> wn = exp(2*M_PI * ci);
  complex<double> w(1,0);
  vector<complex<double>> coeff_even;
  vector<complex<double>> coeff_odd;
  coeff_even.reserve(n/2);
  coeff_odd.reserve(n/2);
  for (int i = 0; i < n; i++) {
    if (i%2 == 0) {
      coeff_even.push_back(coeff_vector[i]);
    }
    else {
      coeff_odd.push_back(coeff_vector[i]);
    }
  }

  vector<complex<double>>* y = new vector<complex<double>>(n);
  vector<complex<double>>& y_out = *y;
  y_out.reserve(n);
  vector<complex<double>> &y_0 = fft(coeff_even, n/2);
  vector<complex<double>> &y_1 = fft(coeff_odd, n/2);
  if ( (n/2) == 1) {
    y_out[0] = y_0[0] + w * y_1[0];
  }
  for (int k = 0; k < n/2 - 1; k++) {
    y_out[k] = y_0[k] + w * y_1[k];
    y_out[k + n/2] = y_0[k] - w * y_1[k];
    w = w * wn;
  }

  for (int i = 0; i < n; i++) {
    cout << y_out[i] << endl;
  }
  return y_out;
}
