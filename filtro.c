#include <stdio.h>
#include <stdlib.h>

extern void enmascarar_asm(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
int enmascarar_c(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
int cargarBuffer(unsigned char *imagen, unsigned char *buffer,int cant);
void procesarImagen(unsigned char *buff1,unsigned char *buff2,unsigned char *buffMask,int cant);

int main(int argc, char *argv[])  
{
    unsigned char *img,*img2,*mask;
    int alto,ancho,imagenSize;
    int RGB_size = 3; //en bytes
    
    img = (unsigned char *)argv[1];
    img2 = (unsigned char *)argv[2];
    mask = (unsigned char *)argv[3];
    sscanf(argv[4],"%d",&alto);
    sscanf(argv[5],"%d",&ancho);
    imagenSize = alto * ancho * RGB_size;
    enmascarar_c(img,img2,mask,imagenSize);

    return 0;
}

int enmascarar_c(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant)
{
    unsigned char *buffer1,*buffer2,*buffermask;

    buffer1 = (unsigned char *)malloc(cant);
    buffer2 = (unsigned char *)malloc(cant);
    buffermask = (unsigned char *)malloc(cant); 
    
    cargarBuffer(a,buffer1,cant);
    cargarBuffer(b,buffer2,cant);
    cargarBuffer(mask,buffermask,cant);

    procesarImagen(buffer1,buffer2,buffermask,cant);

    FILE *archivo_C = fopen("salida.rgb","wb");
    fwrite(buffer1,cant,1,archivo_C);
    fclose(archivo_C);
    
    free(buffer1);
    free(buffer2);
    free(buffermask);     
}

int cargarBuffer(unsigned char *imagen, unsigned char * buffer,int cant_bytes)
{
    FILE *archivo = fopen(imagen,"rb");

    if (!archivo)
    {
        perror("Error al abrir archivo");
        return 2;
    }

    fread(buffer,cant_bytes,sizeof(unsigned char),archivo);    
    fclose(archivo);
}

void procesarImagen(unsigned char *buff1,unsigned char *buff2,unsigned char *buffMask,int cant)
{
    int i=0;
    int cant_RGBs = cant/3;
    while(i<cant_RGBs)
    {
        if (buffMask[i]==0 && buffMask[i+1]==0 && buffMask[i+2]==0)
        {
            buff1[i] = buff2[i];
            buff1[i+1] = buff2[i+1];
            buff1[i+2] = buff2[i+2];           
        }
        i+=3;
    }
}