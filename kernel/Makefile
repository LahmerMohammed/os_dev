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


SRCS = ./kernel.c
OBJS =  ./obj/boot.o ./obj/kernel.o

KERNEL_DIR = arch_i386



init: compile  $(OBJS)
	rm -rf boot/
	mkdir boot/
	$(LINKER) $(LDFLAGS) $(OBJS) -o $(KERNEL_DIR)/boot/kernel.bin 

compile: $(SRCS)
	rm -rf objs/
	mkdir obj/

./obj/boot.o: $(KERNEL_DIR)/boot.asm 
	$(ASSEMBLER) $(ASFALGS) $< -o $@ 

./obj/%.o: $(KERNEL_DIR)/%.c
	$(CC) $(GCCFLAGS) $< -o $@

clean:
	rm -rf  boot/
	rm -rf obj/
