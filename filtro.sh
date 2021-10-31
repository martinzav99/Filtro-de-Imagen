#!/bin/bash
nasm -f elf filtro.s -o filtro.o
gcc -m32 filtro.o filtro.c -o filtro

gm convert paisaje.jpg paisaje.rgb
gm convert lobo.jpg lobo.rgb
gm convert boceto.jpg boceto.rgb

./filtro "paisaje.rgb" "lobo.rgb" "boceto.rgb" 3888 2592

gm convert -size 3888x2592 -depth 8  salida.rgb  salida.jpg
gm convert -size 3888x2592 -depth 8  salida2.rgb  salida2.jpg

rm paisaje.rgb lobo.rgb boceto.rgb salida.rgb salida2.rgb 


#---------------------------------------------------
gm convert -resize 1098x732 paisaje.jpg imagen1.jpg
gm convert -resize 1098x732 lobo.jpg imagen2.jpg
gm convert -resize 1098x732 boceto.jpg mask.jpg

gm convert imagen1.jpg imagen1.rgb
gm convert imagen2.jpg imagen2.rgb
gm convert mask.jpg mask.rgb

./filtro "imagen1.rgb" "imagen2.rgb" "mask.rgb" 1098 732
gm convert -size 1098x732 -depth 8  salida.rgb  salida.jpg
gm convert -size 1098x732 -depth 8  salida2.rgb  salida2.jpg

rm imagen1.rgb imagen2.rgb mask.rgb salida.rgb salida2.rgb

#---------------------------------------------------

<< 'comentario'

gm convert -resize 486x324 paisaje.jpg imagen1.jpg
gm convert -resize 486x324 lobo.jpg imagen2.jpg
gm convert -resize 486x324 boceto.jpg mask.jpg

gm convert imagen1.jpg imagen1.rgb
gm convert imagen2.jpg imagen2.rgb
gm convert mask.jpg mask.rgb

./filtro "imagen1.rgb" "imagen2.rgb" "mask.rgb" 486 324
gm convert -size 486x324 -depth 8  salida.rgb  salida.jpg
gm convert -size 486x324 -depth 8  salida2.rgb  salida2.jpg

rm imagen1.rgb imagen2.rgb mask.rgb salida.rgb salida2.rgb

comentario
