global _load_idt_asm

_load_idt_asm:
    lidt [rdi]
    ret