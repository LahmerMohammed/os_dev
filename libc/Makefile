CC = gcc
LINKER = ld
ASSEMBLER = nasm

GCCFLAGS = -m32 -c -isystem ./include  -ffreestanding \
-nostdlib\
-fno-builtin\
-fno-exceptions\

ASFALGS = -felf32
LDFLAGS = -melf_i386 -T ./src/linker.ld 
EMULATOR = qemu-system-i386
EMULATOR_FLAG = -kernel


SRCS = stdio/keyboard.c stdio/screen.c string/string.c

OBJS =./stdio/keyboard.o\
./stdio/screen.o\
./string/string.o\
./string/memory.o



./string/%.o: ./string/%.c
	$(CC) $(GCCFLAGS) $< -o $@

./stdio/%.o: ./stdio/%.c
	$(CC) $(GCCFLAGS) $< -o $@

#./obj/keyboard.o: ./src/keyboard.c
#	$(CC) $(GCCFLAGS) $< -o $@

#./obj/string.o: ./src/string.c
#	$(CC) $(GCCFLAGS) $< -o $@

#./obj/idt.o: ./src/idt.c
#	$(CC) $(GCCFLAGS) $< -o $@

#./obj/screen.o: ./src/screen.c
#	$(CC) $(GCCFLAGS) $< -o $@

#./obj/system.o: ./src/system.c
#	$(CC) $(GCCFLAGS) $< -o $@

clean:
	rm -rf  boot/
	rm -rf obj/
