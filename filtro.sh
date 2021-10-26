#!/bin/bash
nasm -f elf filtro.s -o filtro.o
gcc -m32 filtro.o filtro.c -o filtro
./filtro "imagen1.rgb" "imagen2.rgb" "mask.rgb" 1098 732

