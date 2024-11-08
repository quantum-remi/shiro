#include <drivers/pic/pic.h>
#include <drivers/log/log.h>
#include <tables/idt.h>

#include <utils/utils.h>

extern void _load_idt_asm(uint64_t idtr);
extern uintptr_t _isr_vector_asm[];

static idt_descriptor_t idt[256];
static idtr_t idtr;

/* utils function */

void create_descriptor(uint8_t index, uint8_t type_attributes);

/* core functions */

void idt_init(void)
{
    uint16_t i = 0;

    for (; i< 32; i++) 
    {
        create_descriptor(i, IDT_INTERRUPT_GATE);
    }

    pic_init();

    /* standard ISA IRQ's  */

    for (; i< 48; i++)
    {
        create_descriptor(i, IDT_INTERRUPT_GATE);
    }

    /* remaining IRQ's */

    for (; i< 256; i++)
    {
        create_descriptor(i, IDT_INTERRUPT_GATE);
    }

    idtr.limit = sizeof(idt) - 1;
    idtr.base = (uint64_t)&idt;

    idt_load();

    asm volatile ("sti"); // store interrupt enable flag allowing interrupts

    log(INFO, "IDT initialized\n\r");
}
void idt_load(void)
{
    _load_idt_asm((uintptr_t)&idtr);
}

/* create idt descriptor */

void create_descriptor(uint8_t index, uint8_t type_attributes) {
    uint64_t offset = _isr_vector_asm[index]; // ISR handler address

    idt[index].offset_low = offset & 0xFFFF;
    idt[index].selector = 0x08; // kernel code segment
    idt[index].ist = 0;
    idt[index].type_attributes = type_attributes;
    idt[index].offset_middle = (offset >> 16) & 0xFFFF;
    idt[index].offset_high = (offset >> 32) & 0xFFFFFFFF;
    idt[index].zero = 0;
}