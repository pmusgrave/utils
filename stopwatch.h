#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <stdint.h>

struct stopwatch{
  volatile uint16_t ms;
  volatile uint16_t sec;
  volatile uint16_t min;
  volatile uint16_t hour;
};

void InitStopwatch();
void StartWatch();
void StopWatch();
void ResetWatch();
uint8_t ReadWatchValue();

#endif
