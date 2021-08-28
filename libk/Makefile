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


SRCS = idt.c isr.c

OBJS = idt.o isr.o




compile: $(OBJS)
	echo "libk compiled successfully ..."



./%.o: ./src/%.c
	$(CC) $(GCCFLAGS) $< -o $@


clean:
	rm ./*.o