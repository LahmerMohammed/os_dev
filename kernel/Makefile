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
KERNEL_DIR = arch_i386



SRCS = $(KERNEL_DIR)/kernel.c
OBJS =  $(KERNEL_DIR)/boot.o $(KERNEL_DIR)/kernel.o




init:  $(OBJS)
	rm -rf boot/
	mkdir boot/
	$(LINKER) $(LDFLAGS) $(OBJS) -o $(KERNEL_DIR)/boot/kernel.bin 
	echo "ready to run ..."

boot.o: $(KERNEL_DIR)/boot.asm 
	$(ASSEMBLER) $(ASFALGS) $< -o $@ 

%.o: $(KERNEL_DIR)/%.c
	$(CC) $(GCCFLAGS) $< -o $@

clean:
	rm -rf  boot/
	rm -rf $(KERNEL_DIR)/*.o
