#include <stdio.h>
#include <stdlib.h>

extern void enmascarar_asm(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
void enmascararAssembler(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
int enmascarar_c(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant);
int cargarBuffer(unsigned char *imagen, unsigned char *buffer,int cant);
void procesarImagen(unsigned char *buff1,unsigned char *buff2,unsigned char *buffMask,int cant);

int main(int argc, char *argv[])  
{
    unsigned char *img,*img2,*mask;
    unsigned char *buffer1,*buffer2,*buffermask;
    int alto,ancho,imagenSize;
    int RGB_size = 3; //en bytes
    
    img = (unsigned char *)argv[1];
    img2 = (unsigned char *)argv[2];
    mask = (unsigned char *)argv[3];
    sscanf(argv[4],"%d",&alto);
    sscanf(argv[5],"%d",&ancho);
    imagenSize = alto * ancho * RGB_size;
    

    buffer1 = (unsigned char *)malloc(imagenSize);
    buffer2 = (unsigned char *)malloc(imagenSize);
    buffermask = (unsigned char *)malloc(imagenSize); 
    
    cargarBuffer(img,buffer1,imagenSize);
    cargarBuffer(img2,buffer2,imagenSize);
    cargarBuffer(mask,buffermask,imagenSize);

    enmascarar_c(buffer1,buffer2,buffermask,imagenSize);
    //enmascararAssembler(buffer1,buffer2,buffermask,imagenSize);
    free(buffer1);
    free(buffer2);
    free(buffermask); 

    return 0;
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

int enmascarar_c(unsigned char *buff1 ,unsigned char *buff2 ,unsigned char *buffMask,int cant)
{
    int i=0;
    while(i<cant)
    {
        if (buffMask[i]==0 && buffMask[i+1]==0 && buffMask[i+2]==0)
        {
            buff1[i] = buff2[i];
            buff1[i+1] = buff2[i+1];
            buff1[i+2] = buff2[i+2];           
        }
        i+=3;
    }
    printf("valor de i: %d",i);

    FILE *archivo_C = fopen("salida.rgb","wb");
    fwrite(buff1,cant,1,archivo_C);
    fclose(archivo_C);    
}

void enmascararAssembler(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant)
{
    enmascarar_asm(a,b,mask,cant);

    FILE *archivo_Asm = fopen("salida2.rgb","wb");
    fwrite(a,cant,1,archivo_Asm);
    fclose(archivo_Asm);
}
