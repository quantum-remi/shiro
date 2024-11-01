#include <drivers/com/serial.h>
#include <log/debug.h>
#include <libs/kprintf/kprintf.h>


char debug_buffer[5120];

/* core debug */


void debug(char *fmt, ...) {
    va_list ptr;
    va_start(ptr, fmt);
    vsnprintf((char *)&debug_buffer, -1, fmt, ptr);
    serial_send_string(COM1, (char *)debug_buffer);
    va_end(ptr);
}
void debug_set_color(char *color_code)
{
    if (color_code[0] != '\e' || color_code[1] != '[')
        return;
    serial_send_string(COM1, color_code);
}