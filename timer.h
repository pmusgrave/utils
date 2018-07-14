#ifndef TIMER_H
#define TIMER_H

struct timer {
  uint8_t timer_config_register;
  // enabled_value is what to write to config_register to enable timer
  // disabled_value is what to write to config_register to disable timer
  uint8_t timer_config_enabled_value;
  uint8_t timer_config_disabled_value;
  uint8_t *output_compare_register;
  uint8_t output_compare_value;
};

void InitTC1(void);
void SetCompareValue(struct timer timer, uint8_t new_compare_value);
void SetOCR(struct timer timer);

#endif
