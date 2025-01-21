all:
	avr-gcc -DF_CPU=16000000UL -pedantic -Wall -Os -mmcu=atmega328p -o ./build/main.o main.c uart.c blink.c
	avr-objcopy -O ihex -j .text -j .data ./build/main.o ./build/main.hex
	avrdude -F -V -c arduino -p atmega328p -P /dev/ttyACM0 -b 115200 -U flash:w:./build/main.hex
clear:
	rm main.o main.hex
