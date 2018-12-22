#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "stopwatch.h"
#include "uart.h"

#define LED_PIN 5
#define HOUR_LED_PIN 7
#define MIN_LED_PIN 6
#define SEC_LED_PIN 5
#define BUTTON 4
#define REFS (1 << REFS0) | (1<<REFS1) | (1<<ADLAR)
void InitGPIO(void);

struct stopwatch stopwatch = {0,0,0,0};

ISR(TIMER1_COMPA_vect){
  stopwatch.ms++;
}

int main(void){
  InitGPIO();
  InitStopwatch();
  sei();

  while(1){
    if (stopwatch.ms >= 1000){
      cli();

      stopwatch.sec++;
      stopwatch.ms = 0;

      // PORTB ^= (1<<LED_PIN);
      PORTD ^= (1<<SEC_LED_PIN);

      sei();
    }
    if (stopwatch.sec >= 60){
      cli();
      stopwatch.min++;
      stopwatch.sec = 0;
      stopwatch.ms = 0;
      PORTD ^= (1<<MIN_LED_PIN);
      sei();
    }
    if (stopwatch.min >= 60){
      cli();
      stopwatch.hour++;
      stopwatch.min = 0;
      stopwatch.sec = 0;
      stopwatch.ms = 0;
      PORTD ^= (1<<HOUR_LED_PIN);
      sei();
    }
  }


  return 0;
}

void InitGPIO(void){
  DDRB = (1 << LED_PIN);
  DDRD = (1 << HOUR_LED_PIN) | (1 << MIN_LED_PIN) | (1 << SEC_LED_PIN);
}
