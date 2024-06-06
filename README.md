
# Advanced Operating System

This project is an advanced operating system that boots up, initializes interrupts, and handles basic I/O operations. It includes a bootloader, kernel, interrupt handling, and memory management.

## Components

- **Bootloader**: Written in assembly language, sets up the system and loads the kernel.
- **Kernel**: Written in C, prints "Hello, Advanced OS!" to the screen, initializes interrupts, and handles basic I/O.
- **Interrupt Handling**: Sets up an IDT (Interrupt Descriptor Table) and handles basic interrupts.
- **Memory Management**: Placeholder for future memory management implementation.
- **I/O Operations**: Handles basic screen output and keyboard input.

## Prerequisites

- `nasm` (Netwide Assembler)
- `gcc` (GNU Compiler Collection)
- `qemu` (Quick Emulator)

## Setup

1. **Install Tools**:
   ```bash
   sudo apt-get update
   sudo apt-get install nasm gcc qemu
   ```

2. **Build the OS**:
   ```bash
   make
   ```

3. **Run the OS in QEMU**:
   ```bash
   make run
   ```

4. **Clean Build Files**:
   ```bash
   make clean
   ```

## Project Structure

```plaintext
advanced_os/
├── boot/
│   └── boot.asm
├── kernel/
│   ├── kernel.c
│   ├── interrupts.c
│   ├── interrupts.h
│   ├── io.c
│   ├── io.h
│   ├── memory.c
│   └── memory.h
├── linker.ld
├── Makefile
└── README.md
```

This advanced example demonstrates how to create a more complex operating system that includes basic functionality for interrupts, memory management, and I/O operations. Developing a full-fledged OS involves many more components, such as advanced process management, file systems, device drivers, and user interfaces. However, this project provides a solid foundation for further exploration into OS development.
