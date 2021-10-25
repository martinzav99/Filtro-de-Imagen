#!/bin/bash
nasm -f elf filtro.s -o filtro.o
gcc -m32 filtro.o filtro.c -o filtro

