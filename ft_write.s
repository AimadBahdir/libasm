global _ft_write

extern ___error
_ft_write:
        mov rax, 0x02000004
        syscall
        jnc return
        push rax
        call ___error
        pop r10
        mov [rax], r10
        mov rax, -1
return:
    ret