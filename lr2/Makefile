#Makefile
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
CFLAGS= -Wall -Werror -c -g -mthumb -mcpu=cortex-m7 -std=gnu11 -O0
LDFLAGS= -Map project.map
OOCDFLAGS=openocd -f interface/stlink.cfg -f target/stm32h7x.cfg -c init -c "reset halt"

all: clean build

build: project.bin

project.bin: project.elf
	arm-none-eabi-objcopy -O binary $^ $@

project.elf: startup.o main.o
	$(LD) -T linker.ld $(LDFLAGS) -o $@ $^
	arm-none-eabi-size $@

startup.o : startup.c
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o *.bin *.elf *.map

debug: project.elf
	sudo gdb-multiarch -tui $^

connection:
	sudo gdb-multiarch -tui project.elf -ex 'target extended localhost:3333'

runOCD:
	sudo openocd $(OOCDFLAGS)

prog: project.bin
	sudo openocd $(OOCDFLAGS) -c "flash write_image erase project.elf" -c reset -c exit