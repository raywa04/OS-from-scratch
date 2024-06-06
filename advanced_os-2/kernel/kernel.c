
#include "io.h"
#include "interrupts.h"
#include "memory.h"

void kernel_main() {
    clear_screen();
    print("Hello, Advanced OS!\n");

    // Initialize interrupts
    init_interrupts();

    // Enable interrupts
    asm volatile ("sti");

    while (1) {
        // Halt CPU until next interrupt
        asm volatile ("hlt");
    }
}
