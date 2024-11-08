#ifndef PIC_H
#define PIC_H

#include <stdint.h>

#define PIC1 0x20 
#define PIC2 0xA0
#define PIC1_COMMAND PIC1
#define PIC1_DATA (PIC1 + 1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA (PIC2 + 1)
#define ICW1_8086 0x01

void pic_disable(void);
void pic_init(void);
void pic_set_mask(uint8_t irq_line);
void pic_clear_mask(uint8_t irq_line);
void pic_end_of_interrupt(uint64_t isr_line);

#endif
