MCU=atmega328p
F_CPU=16000000UL

main: main.o timer.o stopwatch.o
	avr-gcc -mmcu=$(MCU) main.o timer.o stopwatch.o -o main

main.o: main.c
	avr-gcc -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c -o main.o main.c

timer.o: timer.c timer.h
	avr-gcc -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c -o timer.o timer.c

stopwatch.o: stopwatch.c stopwatch.h timer.c timer.h
	avr-gcc -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c -o stopwatch.o stopwatch.c

clean:
	rm *.o main
