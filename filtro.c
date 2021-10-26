#include <stdio.h>
#include <stdlib.h>

extern void enmascarar_asm(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
int enmascarar_c(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
int cargarBuffer(unsigned char *imagen, unsigned char *buffer,int cant);

int main(int argc, char *argv[])
{
    unsigned char *img,*img2,*mask;
    int alto,ancho,tamano;
    int RGB_size = 3;
    
    img = (unsigned char *)argv[1];
    img2 = (unsigned char *)argv[2];
    mask = (unsigned char *)argv[3];
    sscanf(argv[4],"%d",&alto);
    sscanf(argv[5],"%d",&ancho);
    tamano = alto * ancho * RGB_size;
    enmascarar_c(img,img2,mask,tamano);

    return 0;
}

int enmascarar_c(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant)
{
    unsigned char *buffer1,*buffer2,*buffermask;

    buffer1 = (unsigned char *)malloc(cant);
    if (buffer1 ==NULL)
    {
        perror("Error al reservar memoria");
        return 1;
    }
    buffer2 = (unsigned char *)malloc(cant);
    if (buffer2 ==NULL)
    {
        perror("Error al reservar memoria");
        return 1;
    }
    buffermask = (unsigned char *)malloc(cant);
    if (buffermask ==NULL)
    {
        perror("Error al reservar memoria");
        return 1;
    }
     
    cargarBuffer(a,buffer1,cant);
    cargarBuffer(b,buffer2,cant);
    cargarBuffer(mask,buffermask,cant);
    
    free(buffer1);
    free(buffer2);
    free(buffermask); 
    
}

int cargarBuffer(unsigned char *imagen, unsigned char * buffer,int cant_caracteres)
{
    FILE *archivo = fopen(imagen,"rb");

    if (!archivo)
    {
        perror("Error al abrir archivo");
        return 2;
    }

    fread(buffer,cant_caracteres,sizeof(unsigned char),archivo);
    
    fclose(archivo);
}