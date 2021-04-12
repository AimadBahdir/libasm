global _ft_strlen
_ft_strlen:
        mov rcx, -1
loop:
        add rcx, 1
        cmp BYTE[rdi + rcx], 0
        jne loop
        mov rax, rcx
        ret