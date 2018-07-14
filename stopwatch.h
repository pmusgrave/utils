#ifndef STOPWATCH_H
#define STOPWATCH_H

#ifndef F_CPU
#define F_CPU 160000000UL
#endif

#include <stdint.h>

struct stopwatch{
  uint16_t ms;
  uint16_t s;
  uint16_t min;
  uint16_t hour;
};

void StartWatch();
void StopWatch();
void ResetWatch();
uint8_t ReadWatchValue();

#endif
