#include "stopwatch.h"
#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static struct timer * ptimer;

void InitStopwatch(){
  struct timer timer1 = {
    TCCR1B,
    (1<<WGM12) | (1<<CS11),
    0,
    &OCR1AL,
    &OCR1AH,
    16000
  };

  ptimer = &timer1;

  InitTC1();
  SetCompareValue(timer1, timer1.output_compare_value);
}

void StartWatch(){
  EnableTimer(*ptimer);
  sei();
}

void StopWatch(){
  cli();
  DisableTimer(*ptimer);
}

void ResetWatch(struct stopwatch Stopwatch){
  Stopwatch.hour = 0;
  Stopwatch.min = 0;
  Stopwatch.sec = 0;
  Stopwatch.ms = 0;
}
