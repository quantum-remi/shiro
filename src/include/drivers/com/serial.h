#include <stdint.h>
#include <stdbool.h>

#ifndef serial_h
#define serial_h

typedef enum {
    COM1 = 0x3f8,
    COM2 = 0x2f8,
    COM3 = 0x3e8,
    COM4 = 0x2e8
} port_t;

void serial_init(port_t port);
void serial_send_char(port_t port, char c);
void serial_send_string(port_t port, char *str);
char serial_recv(port_t port);

#endif