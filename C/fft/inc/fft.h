#ifndef FFT_H
#define FFT_H

#include<stdlib.h>
#include<math.h>
#include<complex.h>
// e => M_E, pi => M_PI

double* fft(double * coeff_vector, size_t);
void print_coeffs(double* coeff_vector, size_t n);

#endif
