# TP2 Orga II


## Descripción 
En el presente trabajo se presentará un programa tanto en assembler como en lenguaje C que permita combinar dos imagenes en base a una mascara, la cual es un imagen con solamente pixeles blancos y negros, donde en la imagen resultante los pixeles negros corresponde a la iamgen1  y los blancos a la iamgen 2. Para obtener resultados coherentes, se utilizarán imagenes del mismo tamaño.<p>
El objetivo de realizar esta aplicacion en dos entornos diferentes es comparar la performance de las instrucciones SIMD con las instrucciones aritmeticas y logicas de la ALU.

## Pre-Requisitos 📋
Los siguientes comandos se ejecutan en la terminal de Linux: 

<b>Clonar el repositorio<b>
```
sudo apt update
sudo apt-get install git
git clone https://gitlab.com/martinzavallagamarra/tp2-orga-ii.git 
```
<b>Uso de gcc<b>
```
sudo apt-get update
sudo apt-get install gcc 
```
<b>Uso de Nasm<b>
```
sudo apt-get update
sudo apt-get install nasm 
```
<b>Uso de GraphicsMagick<b>
```
sudo apt-get update
sudo apt-get install graphiscmagick 
```
_Nota: No es necesario hacer el update en cada paso, con hacerlo una vez al principio es suficiente._

## Ejercicio: Enmascarar 

### Pautas:
- Usar GraphicsMagick para independizarse del formato de imagen.
- Desarrolar una aplicacion de linea de comando que combine dos imagenes usando una mascara de seleccion.
- Implementar una funcion enmascar_Asm en ensamblador de 32 usando instrucciones SIMD y pasaje de parametros.
- Implementar una funcion enmascar_C  en lenguaje C.

### Resolución 🔧


```
int main(int argc, char *argv[])  
{
    unsigned char *img,*img2,*mask,*alt;
    unsigned char *buffer1,*buffer2,*buffermask;
    int alto,ancho,imagenSize;
    clock_t inicio,fin;
    double tiempoC,tiempoAsm;

    int RGB_size = 3; //en bytes
    img = (unsigned char *)argv[1];
    img2 = (unsigned char *)argv[2];
    mask = (unsigned char *)argv[3];
    alto = atoi(argv[4]);
    ancho = atoi(argv[5]); 
    ...
```


```
    ...
    imagenSize = alto * ancho * RGB_size;
    buffer1 = (unsigned char *)malloc(imagenSize);
    buffer2 = (unsigned char *)malloc(imagenSize);
    buffermask = (unsigned char *)malloc(imagenSize); 
    
    cargarBuffer(img,buffer1,imagenSize);
    cargarBuffer(img2,buffer2,imagenSize);
    cargarBuffer(mask,buffermask,imagenSize);
    ...
    free(buffer1);
    free(buffer2);
    free(buffermask);
    return 0;
}
```

```
int cargarBuffer(unsigned char *imagen, unsigned char * buffer,int cant_bytes)
{
    FILE *archivo = fopen(imagen,"rb");
    ...
    fread(buffer,cant_bytes,sizeof(unsigned char),archivo);    
    fclose(archivo);
}
```
```
    ...
    inicio=clock();
    enmascarar_c(buffer1,buffer2,buffermask,imagenSize);
    fin=clock();
    tiempoAsm = (double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("Imagen tamano: %d x %d\n",alto,ancho);
    printf("Tiempo en C : %.6f\n",tiempoAsm);

    inicio=clock();
    enmascararAssembler(buffer1,buffer2,buffermask,imagenSize);
    fin=clock();
    tiempoC = (double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("Imagen tamano: %d x %d\n",alto,ancho);
    printf("Tiempo en ASM : %.6f\n",tiempoC);
    ...
```

```
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
    FILE *archivo_C = fopen("salida.rgb","wb");
    fwrite(buff1,cant,1,archivo_C);
    fclose(archivo_C);    
}
```

```
void enmascararAssembler(unsigned char *a ,unsigned char *b ,unsigned char *mask,int cant)
{
    enmascarar_asm(a,b,mask,cant);

    FILE *archivo_Asm = fopen("salida2.rgb","wb");
    fwrite(a,cant,1,archivo_Asm);
    fclose(archivo_Asm);
}
```

### Ejemplos 🚀
_Nota: En algunos resultados puede no ser exactamente precisos y presentar errores de redondeo_ 
Para mas informacion:[Link](http://puntoflotante.org/errors/rounding/)
* **r positivo**<p>
![Screenshot](escalar2.png)
* **r negativo** <p>
![Screenshot](escalar1.png)

## Ejecucion 📦
Se puede notar en los ejemplos que para ejecutar los programas se hace uso de un archivo .sh , estos son ejecutables que contienen el codigo de compilacion de cada programa junto con su ejecuccion.

## Autor ✒️
- Martin Zavalla Gamarra.

