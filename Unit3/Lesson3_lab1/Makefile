
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASO=$(AS:.s=.o)
Project_name=learn-in-depth-cortex-m3

all:$(Project_name).bin
	@echo "build is done" 

%.o:%.c
	$(CC)gcc.exe -c  $(CFLAGS) $(INCS) -mthumb $< -o $@

$(Project_name).elf:$(OBJ) $(ASO)
	$(CC)ld.exe -T Linker_script.ld $(LIBS) $(OBJ) $(ASO) -o $@ -Map=map_file.map

$(Project_name).bin:$(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.bin *.elf *.map

clean:
	rm *.bin *.elf *.map