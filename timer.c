#include <stdint.h>
#include "timer.h"
#include <util/delay.h>
#include <avr/io.h>

void InitTC1(void){
  TCCR1A = 0x00;
  TCCR1B = 0x00;
  TCCR1A |= (1<<WGM10);
  TCCR1B |= (1<<WGM12) | (1<<CS11);
}

void SetCompareValue(struct timer timer, uint8_t new_compare_value){
  timer.output_compare_value = new_compare_value;
}

void SetOCR(struct timer timer){
/*

  if(timer.output_compare_value < LED_THRESHOLD){
    timer.timer_config_register = timer.timer_config_disabled_value;
    *timer.output_config.port_ddr &= ~(1<<timer.output_config.pin);
    *timer.output_config.port &= ~(1<<timer.output_config.pin);
  }
  else {
    *timer.output_config.port_ddr |= (1<<timer.output_config.pin);
    *timer.output_config.port |= (1<<timer.output_config.pin);
    timer.timer_config_register = timer.timer_config_enabled_value;
    *timer.output_compare_register = timer.output_compare_value;
  }

  _delay_ms(10);

*/  
}
