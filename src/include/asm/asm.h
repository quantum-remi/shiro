#include <stdint.h>

#ifndef ASM_H
#define ASM_H

void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
void wait(void);

#endif