MCU=atmega328p
F_CPU=16000000UL

VCA: VCA.o timer.o
	avr-gcc -mmcu=$(MCU) VCA.o timer.o -o VCA

VCA.o: VCA.c VCA.h 
	avr-gcc -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c -o VCA.o VCA.c

timer.o: timer.c timer.h
	avr-gcc -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c -o timer.o timer.c

clean:
	rm *.o VCA
