/* Tell the linker that we want an x86_64 ELF64 output file */
OUTPUT_FORMAT(elf64-x86-64)

/* We want the symbol kmain to be our entry point */
ENTRY(kmain)

/* Define the program headers we want so the bootloader gives us the right */
/* MMU permissions; this also allows us to exert more control over the linking */
/* process. */
PHDRS
{
    null    PT_NULL    FLAGS(0) ;                  
    text    PT_LOAD    FLAGS((1 << 0) | (1 << 2)) ;
    rodata  PT_LOAD    FLAGS((1 << 2)) ;           
    data    PT_LOAD    FLAGS((1 << 1) | (1 << 2)) ;
    dynamic PT_DYNAMIC FLAGS((1 << 1) | (1 << 2)) ;
}

SECTIONS
{
    . = 0xffffffff80200000;
 
    .text : {
        *(.text*)
    } :text
 
    . += 0x1000;
 
    .stivale2hdr : {
        KEEP(*(.stivale2hdr))
    } :rodata
 
    .rodata : {
        *(.rodata*)
    } :rodata
 
    . += 0x1000;
 
    .data : {
        *(.data*)
    } :data
 
    .dynamic : {
        *(.dynamic)
    } :data :dynamic
 
    .bss : {
        *(COMMON)
        *(.bss*)
    } :data
}
