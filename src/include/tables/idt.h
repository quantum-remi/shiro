#ifndef IDT_H
#define IDT_H

#include <stdint.h>

#define IDT_INTERRUPT_GATE 0x8E

typedef struct __attribute__((__packed__))
{
    uint16_t	offset_low;
    uint16_t	selector;
    uint8_t	    ist;
    uint8_t	    type_attributes;
    uint16_t	offset_middle;
    uint16_t	offset_high;
    uint32_t	zero;
} idt_descriptor_t;

typedef struct __attribute__((__packed__))
{
    uint16_t	limit;
    uint64_t	base;
} idtr_t;

void idt_init(void);
void idt_load(void);

#endif