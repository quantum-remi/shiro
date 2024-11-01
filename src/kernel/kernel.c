#include <stdint.h>
#include <stddef.h>


#include <log/debug.h>
#include <log/log.h>
#include <tables/gdt.h>
/*#include <tests/unit_test.h> */

void kmain() 
{
    log(INFO, "Kernel started\n\r");

    /*  TODO fix unit tests*/
    /*  unit_test_run_all(); */

    gdt_init();
    for (;;)
        asm volatile ("hlt");
}