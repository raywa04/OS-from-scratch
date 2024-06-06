
#include "io.h"

void outb(uint16_t port, uint8_t value) {
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

void clear_screen() {
    char *video_memory = (char*)0xb8000;
    for (int i = 0; i < 80 * 25 * 2; i++) {
        video_memory[i] = 0;
    }
}

void print(const char *message) {
    char *video_memory = (char*)0xb8000;
    int i = 0;
    while (message[i] != 0) {
        video_memory[i * 2] = message[i];
        video_memory[i * 2 + 1] = 0x07;
        i++;
    }
}
