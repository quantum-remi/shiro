#include <drivers/pic/pic.h>
#include <utils/utils.h>

/* core functions */


/* dissable pic function */

void pic_disable(void) {
    asm_io_outb(PIC2_DATA, 0xFF);
    asm_io_outb(PIC1_DATA, 0xFF);
}

/* initialize pic function */

void pic_init(void)
{
    uint8_t mask1 = asm_io_inb(PIC1_DATA);
    uint8_t mask2 = asm_io_inb(PIC2_DATA);

    asm_io_outb(PIC1_COMMAND, 0x11);
    asm_io_outb(PIC2_COMMAND, 0x11);
    asm_io_wait();

    asm_io_outb(PIC1_COMMAND, 0x20);
    asm_io_outb(PIC2_COMMAND, 0x20);
    asm_io_wait();

    asm_io_outb(PIC1_COMMAND, 0x04);
    asm_io_outb(PIC2_COMMAND, 0x02);
    asm_io_wait();

    asm_io_outb(PIC1_COMMAND, 0x01);
    asm_io_outb(PIC2_COMMAND, 0x01);
    asm_io_wait();

    asm_io_outb(PIC1_COMMAND, 0x00);
    asm_io_outb(PIC2_COMMAND, 0x00);
    asm_io_wait();

    asm_io_outb(PIC1_DATA, ICW4_8086);
    asm_io_wait();
    asm_io_outb(PIC2_DATA, ICW4_8086);
    asm_io_wait();

    asm_io_outb(PIC1_DATA, mask1);
    asm_io_outb(PIC2_DATA, mask2);
}

/* set interrupt mask function to ignore irqs */

void pic_set_mask(uint8_t irq_line)
{
    uint16_t port;
    uint8_t value;

    if (irq_line < 8)
    {
        port = PIC1_DATA;
    }
    else
    {
        port = PIC2_DATA;
        irq_line -= 8;
    }

    value = asm_io_inb(port) | (1 << irq_line);
    asm_io_outb(port, value);
}

/* set interrupt mask function to enable irqs */

void pic_clear_mask(uint8_t irq_line)
{
    uint16_t port;
    uint8_t value;

    if (irq_line < 8)
    {
        port = PIC1_DATA;
    }
    else
    {
        port = PIC2_DATA;
        irq_line -= 8;
    }

    value = asm_io_inb(port) & ~(1 << irq_line);
    asm_io_outb(port, value);
}

/* signal end of interrupt */

void pic_end_of_interrupt(uint64_t isr_line) 
{
    /*check if irq cpmes from slave pic */
    if(isr_line >= 40)
    {
        asm_io_outb(PIC2_COMMAND, 0x20);
    }

    /* irq comes from master pic */
    asm_io_outb(PIC1_COMMAND, 0x20);
}