#include <stdio.h>
#include <stdlib.h>

extern void enmascarar_asm(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
void enmascarar_c(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
int cargarBuffer(unsigned char *imagen, unsigned char *buffer);

int main(int argc, char *argv[])
{
    unsigned char *img,*img2,*mask;
    int RGB_size = 3;
    
    img = (unsigned char *)argv[1];
    img2 = (unsigned char *)argv[2];
    mask = (unsigned char *)argv[3];
    int tamano = (int)argv[4] * (int)argv[5] * RGB_size; 
    return 0;
}

void enmascarar_c(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant)
{
    unsigned char *buffer1,*buffer2,*buffermask;

    buffer1 = (unsigned char*)malloc(cant);
    buffer2 = (unsigned char*)malloc(cant);
    buffermask = (unsigned char*)malloc(cant);
    
    cargarBuffer(a,buffer1);
    cargarBuffer(b,buffer2);
    cargarBuffer(mask,buffermask);
    
}

int cargarBuffer(unsigned char *imagen, unsigned char *buffer)
{
    FILE *archivo = fopen(imagen,"rb");

    if (archivo =NULL)
    {
        perror("Error al abrir archivo");
        return 1;
    }

    fseek(archivo,0,SEEK_END);
    int cant_caracteres = ftell(archivo);
    rewind(archivo);

    fread(buffer,cant_caracteres,sizeof(unsigned char),archivo);
    fclose(archivo);
}