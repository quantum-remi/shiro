
#include <drivers/cpu.h>
#include <drivers/log/log.h>

uint64_t isr_handler(uint64_t rsp)
{
    interrupt_cpu_state_t *cpu = (interrupt_cpu_state_t*)rsp;

    log(WARNING, "ISR %d / 0x%x\n", cpu->isr_number, cpu->isr_number);

    for (;;)
	asm volatile("cli; hlt");

    return rsp;
}