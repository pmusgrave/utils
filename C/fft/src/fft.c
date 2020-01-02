#include "../inc/fft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// xk = e^(i*k*tau/n)

double* fft(double* coeff_vector, size_t n){
  printf("Recursive call. N: %ld", n);
  print_coeffs(coeff_vector, n);
  if(n == 1){
    return coeff_vector;
  }

  double complex wn = cexp(2*M_PI*I/n);
  double complex w = 1;
  double* coeff_even = malloc(n/2 * sizeof(double));
  double* coeff_odd = malloc(n/2 * sizeof(double));
  for(int i = 0; i < n; i++){
    if(i%2 == 0){
      coeff_even[i/2] = coeff_vector[i];
    }
    else {
      coeff_odd[i/2] = coeff_vector[i];
    }
  }

  print_coeffs(coeff_even, n/2);
  print_coeffs(coeff_odd, n/2);

  double* y_0 = malloc(n/2 * sizeof(double));
  double* y_1 = malloc(n/2 * sizeof(double));
  double* y = malloc(n* sizeof(double));
  y_0 = fft(coeff_even, n/2);
  y_1 = fft(coeff_odd, n/2);
  if ( (n/2) == 1) {
    y[0] = (*y_0) + w * (*y_1);
  }
  for (int k = 0; k < n/2 - 1; k++) {
    y[k] = y_0[k] + w * y_1[k];
    printf("\ny0:%f w:%f y1:%f yk:%f\n", y_0[k], w, y_1[k], y[k]);
    y[k + n/2] = y_0[k] - w * y_1[k];
    w = w * wn;
    printf("w:%f wn:%f ",w, wn);
  }

  for (int i = 0; i < n; i++) {
    printf("%f\n", y[i]);
  }
  free(y_0);
  free(y_1);
  return y;
}

void print_coeffs(double* coeff_vector, size_t n) {
  printf("\nCoefficients\n");
  for (int i = 0; i < n; i++) {
    printf("%f ", coeff_vector[i]);
  }
  printf("\n");
}
