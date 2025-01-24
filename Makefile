default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o uart.o uart.c
	avr-gcc -o uart.bin uart.o
	avr-objcopy -O ihex -R .eeprom uart.bin uart.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:uart.hex
