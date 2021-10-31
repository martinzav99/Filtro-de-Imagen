section .data
pixelBlanco db 255

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
mov edi , [pixelBlanco]

ciclo:
movd xmm0,[eax+esi]
movd xmm1,[ebx+esi]
cmp [ecx+esi] , edi
jne esPixelNegro 
movaps xmm2,xmm1
jmp continuar

esPixelNegro:
movaps xmm2,xmm0

continuar:
movd [eax+esi],xmm2
add esi,4
cmp esi , edx
jb ciclo

mov esp,ebp
pop ebp

ret