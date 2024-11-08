#include <stdarg.h>
#ifndef DEBUG_H
#define DEBUG_H
// bash color codes
#define TERM_BLACK	    "\e[0;30m"
#define TERM_RED	    "\e[0;31m"
#define TERM_GREEN	    "\e[0;32m"
#define TERM_YELLOW	    "\e[0;33m"
#define TERM_BLUE	    "\e[0;34m"
#define TERM_PURPLE	    "\e[0;35m"
#define TERM_CYAN	    "\e[0;36m"
#define TERM_WHITE	    "\e[0;37m"
#define TERM_COLOR_RESET    "\e[0m"
void debug(char *fmt, ...);
void debug_set_color(char *color_code);
#endif