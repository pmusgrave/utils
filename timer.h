#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

struct timer {
  uint8_t timer_config_register;
  // enabled_value is what to write to config_register to enable timer
  // disabled_value is what to write to config_register to disable timer
  uint8_t timer_config_enabled_value;
  uint8_t timer_config_disabled_value;
  volatile uint8_t *output_compare_register_low;
  volatile uint8_t *output_compare_register_high;
  uint16_t output_compare_value;
};

void InitTC1(void);
void EnableTimer(struct timer timer);
void DisableTimer(struct timer timer);
void SetCompareValue(struct timer timer, uint8_t new_compare_value);

#endif
