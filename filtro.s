section .text
    global enmascarar_asm

enmascarar_asm:
push ebp
mov ebp,esp


mov esp,ebp
pop ebp

ret