# Target: Upload the program
upload:
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing -c uart.c
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing uart.o -o uart.elf
	avr-objcopy -j .text -j .data -O ihex uart.elf uart.hex
	avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:uart.hex:i

# Clean the project
clean:
	rm -f *.o *.elf *.hex
