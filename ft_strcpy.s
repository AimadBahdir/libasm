global _ft_strcpy
_ft_strcpy:
        mov rcx, rsi
        jmp loop
loop:
        mov al, BYTE[rsi]
        mov BYTE[rdi], al
        inc rdi
        inc rsi
        cmp al, 0
        jne loop
        mov BYTE[rdi], 0
        mov rax, rcx
        ret