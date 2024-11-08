#include <libs/kprintf/kprintf.h>
#include <drivers/log/debug.h>
#include <drivers/log/log.h>

char log_buffer[5120];

/* core log */

void log_impl(char *file, int line_nr, log_status_t status, char *fmt, ...) {

    va_list ptr;
    va_start(ptr, fmt);
    vsnprintf((char *)&log_buffer, -1, fmt, ptr);
    if (status == INFO)
    {
        debug_set_color(TERM_CYAN);
        debug("[INFO]    | %s:%d ─→ %s", file, line_nr, (char *)log_buffer);
    }
    else if (status == WARNING)
    {
        debug_set_color(TERM_YELLOW);
        debug("[WARNING] | %s:%d ─→ %s", file, line_nr, (char *)log_buffer);
    }
    else if (status == PANIC)
    {
        debug_set_color(TERM_RED);
        debug("[PANIC]   | %s:%d ─→ %s", file, line_nr, (char *)log_buffer);
	for (;;)
	    asm volatile("cli; hlt");
    }
    debug_set_color(TERM_COLOR_RESET);
}