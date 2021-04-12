global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
    call _ft_strlen
    push rdi
    mov rdi, rax
    inc rax
    call _malloc
    pop rdi
	cmp rax, 0
    je _return
    mov rsi, rdi
    mov rdi, rax
    call _ft_strcpy
_return:
    ret