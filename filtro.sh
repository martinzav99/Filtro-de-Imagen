#!/bin/bash
nasm -f elf filtro.s -o filtro.o
gcc -m32 filtro.o filtro.c -o filtro
./filtro "imagen1.rgb" "imagen2.rgb" "mask.rgb" 1098 732
gm convert -size 1098x732 -depth 8  salida.rgb  salida.jpg
#gm convert -size 1098x732 -depth 8  salida2.rgb  salida2.jpg

