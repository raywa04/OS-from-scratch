
#include "interrupts.h"
#include "io.h"

struct idt_entry idt[IDT_SIZE];
struct idt_ptr idtp;

void init_interrupts() {
    idtp.limit = (sizeof(struct idt_entry) * IDT_SIZE) - 1;
    idtp.base = (uint32_t)&idt;

    for (int i = 0; i < IDT_SIZE; i++) {
        idt[i].base_low = 0;
        idt[i].sel = 0x08;
        idt[i].always0 = 0;
        idt[i].flags = 0x8E;
        idt[i].base_high = 0;
    }

    set_idt_gate(0, (uint32_t)isr_handler);
    load_idt(&idtp);
}

void set_idt_gate(int n, uint32_t handler) {
    idt[n].base_low = handler & 0xFFFF;
    idt[n].base_high = (handler >> 16) & 0xFFFF;
}

void isr_handler() {
    print("Interrupt received!\n");
}
