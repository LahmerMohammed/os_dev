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


SRCS = stdio/keyboard.c\
stdio/screen.c\
string/string.c \
drivers/idt.c \
drivers/isr.c \
drivers/system.c \

OBJS =./stdio/keyboard.o\
stdio/screen.o\
string/string.o\
string/memory.o \
drivers/idt.o \
drivers/isr.o \
drivers/system.o \


compile: $(OBJS)
	echo "libc compiled successfully ..."

./string/%.o: ./string/%.c
	$(CC) $(GCCFLAGS) $< -o $@

./stdio/%.o: ./stdio/%.c
	$(CC) $(GCCFLAGS) $< -o $@

./drivers/%.o: ./drivers/%.c
	$(CC) $(GCCFLAGS) $< -o $@

clean:
	rm ./**/*.o