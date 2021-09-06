CC = gcc
LINKER = ld
ASSEMBLER = nasm

GCCFLAGS = -m32 -c -isystem ./include  -ffreestanding \
-nostdlib\
-fno-builtin\
-fno-exceptions\
-g

ASFALGS = -felf32
LDFLAGS = -melf_i386 -T ./src/linker.ld 
EMULATOR = qemu-system-i386
EMULATOR_FLAG = -kernel


OBJ = kernel/boot/kernel.bin  


run: $(OBJ)
#   objcopy --only-keep-debug  $(OBJ) kernel/boot/kernel.sym
#	objcopy --strip-debug $(OBJ)
	$(EMULATOR) $(EMULATOR_FLAG) $(OBJ)

#init: compile  $(OBJS)
#	rm -rf boot/
#	mkdir boot/
#	$(LINKER) $(LDFLAGS) $(OBJS) -o ./boot/kernel.bin 

#compile: $(SRCS)
#	rm -rf objs/
#	mkdir obj/

#./obj/boot.o: ./src/boot.asm 
#	$(ASSEMBLER) $(ASFALGS) $< -o $@ 

#./obj/%.o: ./src/%.c
#	$(CC) $(GCCFLAGS) $< -o $@

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
