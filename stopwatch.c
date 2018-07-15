#include "stopwatch.h"
#include "timer.h"
#include <avr/io.h>

void InitStopwatch(){
    struct timer timer1 = {
      TCCR1B,
      (1<<WGM12) | (1<<CS11),
      0,
      &OCR1AL,
      &OCR1AH,
      62499
    };

    InitTC1();
    SetCompareValue(timer1, timer1.output_compare_value);
}

void StartWatch(){}
void StopWatch(){}
void ResetWatch(){}
uint8_t ReadWatchValue(){}
