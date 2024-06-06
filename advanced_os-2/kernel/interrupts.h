
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

void init_interrupts();
void isr_handler();

#define IDT_SIZE 256

struct idt_entry {
    uint16_t base_low;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

extern struct idt_entry idt[IDT_SIZE];
extern struct idt_ptr idtp;

#endif
