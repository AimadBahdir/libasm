global _ft_read
extern ___error

_ft_read:
    mov rax, 0x02000003
    syscall
    jnc _return
    push rax
    call ___error
    pop r10
    mov [rax], r10
    mov rax, -1
_return:
    ret