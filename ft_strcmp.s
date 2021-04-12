global _ft_strcmp
_ft_strcmp:
        jmp loop
loop:
        mov al, BYTE[rdi]
        mov cl, BYTE[rsi]
        cmp al, 0
        je _return
        cmp cl, 0
        je _return
        cmp al, cl
        je incr
        jmp _return
incr:
        add rdi, 1
        add rsi, 1
        jmp loop
_return:
        movzx rdx, al
        movzx rcx, cl
        sub rdx, rcx
        mov rax, rdx
        ret
       