#ifndef FFT_H
#define FFT_H

#include<math.h>
#include<complex.h>
// e => M_E, pi => M_PI

double buffer[1024];
double complex coefficients[16];
double* fft(double * coeff_vector);

#endif
