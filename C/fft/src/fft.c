#include "fft.h"
#include <stdio.h>
#include <math.h>

double* fft(double * coeff_vector){
  int n = sizeof(coeff_vector) / sizeof(double);
  if(n == 1){
    return coeff_vector;
  }

  double complex wn = cexp(2*M_PI*I/n);
  double w = 1;
  double coeff_even[n/2];
  double coeff_odd[n/2];
  for(int i = 0; i < n; i++){
    if(i%2 == 0){
      coeff_even[i/2] = coeff_vector[i];
    }
    else {
      coeff_odd[i/2] = coeff_vector[i];
    }
  }


}

int main(){
  printf("\n");
  return 0;
}
