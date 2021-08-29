CC = gcc
LINKER = ld
ASSEMBLER = nasm
KERNEL_DIR = arch
BOOT_DIR = boot

GCCFLAGS = -m32 -c -isystem ../libc/include  -ffreestanding \
-nostdlib\
-fno-builtin\
-fno-exceptions\

ASFALGS = -felf32
LDFLAGS = -melf_i386 -T $(KERNEL_DIR)/linker.ld 
EMULATOR = qemu-system-i386
EMULATOR_FLAG = -kernel




SRCS = $(KERNEL_DIR)/kernel.c
OBJS =  $(KERNEL_DIR)/boot.o $(KERNEL_DIR)/kernel.o




install: config  $(OBJS)
	rm -rf boot/
	mkdir boot/
	$(LINKER) $(LDFLAGS) $(OBJS) -o $(BOOT_DIR)/kernel.bin 
	echo "ready to run ..."

config: 
  C_INCLUDE_PATH = "../libc/include"

$(KERNEL_DIR)/boot.o: $(KERNEL_DIR)/boot.asm 
	$(ASSEMBLER) $(ASFALGS) $< -o $@ 

$(KERNEL_DIR)/%.o: $(KERNEL_DIR)/%.c
	$(CC) $(GCCFLAGS) $< -o $@

clean:
	rm -rf  $(BOOT_DIR)
	rm -rf $(KERNEL_DIR)/*.o
