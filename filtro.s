section .text
    global enmascarar_asm

enmascarar_asm:
push ebp
mov ebp,esp

mov eax , [ebp+8]
mov ebx , [ebp+12]
mov ecx , [ebp+16]

mov esp,ebp
pop ebp

ret