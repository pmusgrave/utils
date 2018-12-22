#!/bin/bash

#avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o LEDStuff.o LEDStuff.c
#avr-gcc -mmcu=atmega328p LEDStuff.o -o LEDStuff
avr-objcopy -O ihex -R .eeprom main main.hex
avrdude -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex
