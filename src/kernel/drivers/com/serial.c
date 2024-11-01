#include <asm/asm.h>
#include <drivers/com/serial.h>

/* basic serial driver */

bool serial_transmit_empty(port_t port);
bool serial_recived(port_t port);

/* initialize the serial port */
void serial_init(port_t port) {
    outb(port +1, 0x00); /* disable all interrupts */
    outb(port +3, 0x80); /* enable DLAB */
    outb(port +0, 0x03); /* set divisor latch */
    outb(port +1, 0x00); /* set divisor latch */
    outb(port +3, 0x03); /* 8 bits, no parity, one stop bit */
    outb(port +2, 0xC7); /* enable FIFO, clear them, with 14-byte threshold */
    outb(port +4, 0x0B); /* IRQs enabled, RTS low, DTR high */
}

/* send char to serial port */
void serial_send_char(port_t port, char c) {
    while (!serial_transmit_empty(port));
    outb(port, c);
}

/* send string to serial port */
void serial_send_string(port_t port, char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        serial_send_char(port, str[i]);
    }
}

/* get data from given serial port */
char serial_recv(port_t port) {
    while (!serial_recived(port));
    
    return inb(port);
}


/* utility functions */

bool serial_transmit_empty(port_t port) {
    return inb(port +5) & 0x20;
}

bool serial_recived(port_t port) {
    return inb(port +5) & 0x01;
}

/* end of file */