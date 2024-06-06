
[org 0x7c00] ; Boot sector starts at address 0x7c00

; Set up stack
cli
xor ax, ax
mov ss, ax
mov sp, 0x7c00

; Set up segment registers
mov ax, 0x07c0
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

; Load GDT
lgdt [gdt_descriptor]

; Switch to protected mode
mov eax, cr0
or eax, 1
mov cr0, eax

; Far jump to clear prefetch and set CS
jmp 0x08:protected_mode

gdt_start:
gdt_null:
    dq 0x0000000000000000
gdt_code:
    dq 0x00cf9a000000ffff
gdt_data:
    dq 0x00cf92000000ffff
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

protected_mode:
    ; Set segment registers for protected mode
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; Load kernel
    call 0x1000

    ; Infinite loop
    jmp $

times 510 - ($-$$) db 0 ; Fill the rest of the boot sector with zeros
dw 0xaa55 ; Boot sector signature
