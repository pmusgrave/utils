#include <stdio.h>
#include <unity.h>
#include <math.h>
#include <complex.h>
#include "../inc/fft.h"

void setUp(void) {}
void tearDown(void) {}

void test_fft() {
  double* sample_buffer = malloc(4 * sizeof(double));
  double* vector_test = malloc(4 * sizeof(double));
  for (int i = 0; i < 4; i++) {
    vector_test[i] = i;
  }
  sample_buffer = fft(vector_test,4);
  for(int i = 0; i< 4; i++) {
    printf("%f ", cabs(sample_buffer[i]));
  }
  free(sample_buffer);
  free(vector_test);
}

int main(void) {
  RUN_TEST(test_fft);
  return 0;
}
