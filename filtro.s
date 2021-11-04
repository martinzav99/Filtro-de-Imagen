section .data
pixelNegro db 0

section .text
    global enmascarar_asm

enmascarar_asm:
push ebp
mov ebp,esp

mov eax , [ebp+8] ;img1
mov ebx , [ebp+12] ;img2
mov ecx , [ebp+16] ; mask
mov edx , [ebp +20] ; imgSize
mov esi , 0
mov edi , [pixelNegro]

ciclo:
movd xmm0,[eax+esi]
movd xmm1,[ebx+esi]
cmp [ecx+esi] , edi
je esPixelNegro 
movd [eax+esi],xmm1

esPixelNegro:
add esi,4
cmp esi , edx
jb ciclo

mov esp,ebp
pop ebp

ret
