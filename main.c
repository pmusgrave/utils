#ifndef F_CPU
#define F_CPU 160000000UL
#endif
#include <stdint.h>
#include "stopwatch.h"
#include "timer.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED_PIN 5
#define REFS (1 << REFS0) | (1<<REFS1) | (1<<ADLAR)

void InitGPIO(void);

int main(void){
  // InitGPIO();
  InitTC1();

  sei();

  struct timer timer1 = {
    TCCR1A,
    ((1<<COM1A1) | (1<<WGM10)),
    (1<<WGM10),
    (uint8_t*)&OCR1A,
    0
  };

  while(1){

  }

  return 0;
}

void InitGPIO(void){
  DDRB |= (1 << LED_PIN) | (1<<PB1) | (1<<PB3);
  DDRD |= (1<<PD6);
  PORTB |= (1<<PB4);
}

void InitADC(void){
  ADCSRA |= (1 << ADEN);
  ADCSRA |= (1<<ADPS0) | (1 << ADPS2);
  ADCSRA |= (0b11);

  ADMUX |= (1 << REFS0) | (1<<REFS1) | (1<<ADLAR);
}

volatile uint16_t ReadAdcChannel(int channel){
  //  ADMUX = (0xF0 & ADMUX) | channel;
  ADMUX = REFS | channel;
  ADCSRA |= (1 << ADSC);
  while (!(ADCSRA & (1 << ADSC))){
      ;
  }
  return ADCH;
}
