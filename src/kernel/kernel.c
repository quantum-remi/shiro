#include <stdint.h>
#include <stddef.h>
#include <log/debug.h>
#include <log/log.h>
/*#include <tests/unit_test.h> */

void kmain() 
{
    log(INFO, "Kernel started\n");
    /*  TODO fix unit tests*/
    /*  unit_test_run_all(); */

    for (;;)
        asm volatile ("hlt");
}