#include <stdint.h>
#include "timer.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void InitTC1(void){
  TCCR1A = 0x00;
  TCCR1B = 0x00;
  // mode: CTC, TOP = OCR1A
  TCCR1B |= (1<<WGM12) | (1<<CS12);
  TIMSK1 |= (1<<OCIE1A);
}

void EnableTimer(struct timer timer){
  timer.timer_config_register = timer.timer_config_enabled_value;
}

void DisableTimer(struct timer timer){
  timer.timer_config_register = timer.timer_config_disabled_value;
}

void SetCompareValue(struct timer timer, uint8_t new_compare_value){
  // temporarily disable timer while changing compare value
  // not sure if this is necessary?
  DisableTimer(timer);

  *timer.output_compare_register_high = (uint8_t) ((new_compare_value & 0xFF00)>>8);
  *timer.output_compare_register_low = (uint8_t) new_compare_value & 0x00FF;

  // enable timer again after complete
  EnableTimer(timer);
}
