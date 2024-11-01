global _gdt_load_asm
global _tss_load_asm

_gdt_load_asm:
    lgdt    [rdi]	; load GDT -> rdi is the first argument passed
    
    mov	    ax, 0x10	; 0x10 is the kernel data segment
    mov	    ds, ax	; load kernel data segment (into data segment registers)
    mov	    es, ax
    mov	    fs, ax
    mov	    gs, ax
    mov	    ss, ax
    
    pop	    rdi		; pop return address
    mov	    rax, 0x08	; 0x08 is the kernel code segment
    push    rax		; push the kernel code segment
    push    rdi		; push return address
    retfq		; far return

_tss_load_asm:
    mov	    ax, 0x28    ; 0x28 is the TSS segment 
    ltr	    ax		; load TSS
    ret			; return