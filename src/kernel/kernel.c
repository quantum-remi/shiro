#include <stdint.h>
#include <stddef.h>


void kmain() 
{
    for (;;)
        asm volatile ("hlt");
}