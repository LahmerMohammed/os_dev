CC = gcc
LINKER = ld
ASSEMBLER = nasm
KERNEL_DIR = arch
BOOT_DIR = boot
LIB_OBJ = ../libc/**/*.o
LIB_HEADERS = ../libc/include

GCCFLAGS = -m32 -c -isystem $(LIB_HEADERS)  -ffreestanding \
-nostdlib\
-fno-builtin\
-fno-exceptions\

ASFALGS = -felf32
LDFLAGS = -melf_i386 -T $(KERNEL_DIR)/linker.ld 
EMULATOR = qemu-system-i386
EMULATOR_FLAG = -kernel






SRCS = $(KERNEL_DIR)/kernel.c
OBJS =  $(KERNEL_DIR)/boot.o $(KERNEL_DIR)/kernel.o $(LIB_OBJ)




build: $(OBJS)
	rm -rf boot/
	mkdir boot/
	$(LINKER) $(LDFLAGS) $(OBJS) -o $(BOOT_DIR)/kernel.bin 
	echo "ready to run ..."

$(KERNEL_DIR)/boot.o: $(KERNEL_DIR)/boot.asm 
	$(ASSEMBLER) $(ASFALGS) $< -o $@ 

$(KERNEL_DIR)/%.o: $(KERNEL_DIR)/%.c
	$(CC) $(GCCFLAGS) $< -o $@

clean:
	rm -rf  $(BOOT_DIR) 2> /dev/null
	rm -rf $(KERNEL_DIR)/*.o 2> /dev/null
