MCU = atmega32
AVRDUDE = avrdude -e -p $(MCU) -c usbtiny
CFLAGS = -std=gnu99 -Os -Wall -I/opt/avr/avr/include

all: main.hex

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom $< $@

main.elf: main.c
	avr-gcc -mmcu=$(MCU) $(CFLAGS) $< -o $@

.PHONY: program
program: main.hex
	$(AVRDUDE) -U flash:w:main.hex

.PHONY: fuse
fuse:
	$(AVRDUDE) -U lfuse:w:0x3e:m
	$(AVRDUDE) -U hfuse:w:0xd8:m

.PHONY: fuse-jtag
fuse-jtag:
	$(AVRDUDE) -U lfuse:w:0x3e:m
	$(AVRDUDE) -U hfuse:w:0x98:m

clean:
	rm -f main.hex
	rm -f main.elf
