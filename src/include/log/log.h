#include <stdarg.h>

#ifndef LOG_H
#define LOG_H

#define log(...) log_impl(__FILE__, __LINE__, __VA_ARGS__);

typedef enum {
    INFO,
    WARNING, 
    PANIC
} log_status_t;

void log_impl(char *file, int line_nr, log_status_t status, char *fmt, ...);

#endif