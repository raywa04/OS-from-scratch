
all: os-image

boot/boot.bin: boot/boot.asm
    nasm -f bin -o boot/boot.bin boot/boot.asm

kernel/kernel.bin: kernel/kernel.c kernel/interrupts.c kernel/io.c kernel/memory.c
    gcc -ffreestanding -c kernel/kernel.c -o kernel/kernel.o
    gcc -ffreestanding -c kernel/interrupts.c -o kernel/interrupts.o
    gcc -ffreestanding -c kernel/io.c -o kernel/io.o
    gcc -ffreestanding -c kernel/memory.c -o kernel/memory.o
    ld -o kernel/kernel.bin -T linker.ld kernel/kernel.o kernel/interrupts.o kernel/io.o kernel/memory.o --oformat binary

os-image: boot/boot.bin kernel/kernel.bin
    cat boot/boot.bin kernel/kernel.bin > os-image

run: os-image
    qemu-system-i386 -drive format=raw,file=os-image

clean:
    rm -f boot/boot.bin kernel/*.o kernel/kernel.bin os-image
