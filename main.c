//-------------------------------------Made by Edward Duarte, Juliana Toro, David Orozco, M. O.-----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define longitud 80
#define TRUE  1
#define FALSE 0
//Declaración variables
FILE * fp;
int zonaInteres; //Variable para seleccionar la zona donde el cliente desea comprar
float suma=0;
float suma1=0;

const int zona1 = 50;
const int zona2 = 80;
const int zona3 = 80;
const int zona4 = 80;
const int zona5 = 40;
const int zona6 = 76;
int x,y,boleteria[15][29];
float precio [6] = {198000,159000,93000,71000,110000,46000};
float nuevoPrecio;
float dineroUsuario = 0;
double capacidad [6] = {50,80,80,80,40,76};
char nombreUsuario [100];
int sillaGlobal;
int sillas [20];
char contraseniaC[longitud+1];
char contraseniaActual[longitud+1]= {'9','8','7','6'};
int numeroBoletas;
int entrarAdministrador = 0;
int zonaModificar;
int volverComprar = 0;
int menu;
int menuAdmin;
float vueltos;

void contrasenia (char x[longitud])/*vec1[longitud]*/
{
    /*for(int i=0; i<longitud; i++) //Se recorre el vector  y se va asignando al apuntador cada posición
        {
        contraseniaC[i]=*(vec1+i);
        }*/
    if(strcmp(x,contraseniaActual)==0)
    {
        printf("Bienvenido administrador\n");
        entrarAdministrador = 1;
    }
    else
    {
        printf("\nContre%ca incorrecta\n", 164);
        int entrarAdministrador = 0;
    }
}
int interfazInicio(int a) //Función que imprime el menú inicial
{
    printf("__________________________________________\n");
    printf("| NUMERO |           INTERFAZ            |\n");
    printf("|________|_______________________________|\n");
    printf("|   1    |           Administrador       |\n");
    printf("|--------|-------------------------------|\n");
    printf("|   2    |           Usuario             |\n");
    printf("|--------|-------------------------------|\n");
    printf("|   3    |           Salir               |\n");
    printf("|________|_______________________________|\n\n");
}
int interfazAdminstrador(int a) //Función que imprime el menú para el administrador
{
    printf("__________________________________________________\n");
    printf("| NUMERO |               INTERFAZ                 |\n");
    printf("|________|________________________________________|\n");
    printf("|   1    |  Cambiar Precio                        |\n");
    printf("|--------|----------------------------------------|\n");
    printf("|   2    |  Reporte                               |\n");
    printf("|--------|----------------------------------------|\n");
    printf("|   3    |  Cambiar Clave                         |\n");
    printf("|--------|----------------------------------------|\n");
    printf("|   4    |  Salir                                 |\n");
    printf("|--------|----------------------------------------|\n");
}
int visualizacionZonas() //Función que permite visualizar cada silla por zona
{
    printf("              |--------------- Zona5 -----------------|     |--------------------------------- Zona6 -----------------------------------|\n");
    printf("               ___ ___ ___ ___ ___ ___ ___ ___ ___ ___       ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___        \n");
    printf("              |E1-|E2-|E3-|E4-|E5-|E6-|E7-|E8-|E9-|E10|     |F1-|F2-|F3-|F4-|F5-|F6-|F7-|F8-|F9-|F10|F11|F12|F13|F14|F15|F16|F17|F18|F19|       \n");
    printf("              |---|---|---|---|---|---|---|---|---|---|     |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|       \n");
    printf("              |E11|E12|E13|E14|E15|E16|E17|E18|E19|E20|     |F20|F21|F22|F23|F24|F25|F26|F27|F28|F29|F30|F31|F32|F33|F34|F35|F36|F37|F38|       \n");
    printf("        ___   |---|---|---|---|---|---|---|---|---|---|     |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|       \n");
    printf("       |   |   ___ ___ ___ ___ ___   ___ ___ ___ ___ ___ ___ ___ ___   ___ ___ ___ ___ ___ ___ ___ ___   ___ ___ ___ ___ ___ ___ ___ ___        \n");
    printf("       | E |  |A1-|A2-|A3-|A4-|A5-| |B1-|B2-|B3-|B4-|B5-|B6-|B7-|B8-| |C1-|C2-|C3-|C4-|C5-|C6-|C7-|C8-| |D1-|D2-|D3-|D4-|D5-|D6-|D7-|D8-|       \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | S |  |A6-|A7-|A8-|A9-|A10| |B9-|B10|B11|B12|B13|B14|B15|B16| |C9-|C10|C11|C12|C13|C14|C15|C16| |D9-|D10|D11|D12|D13|D14|D15|D16|       \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | C |  |A11|A12|A13|A14|A15| |B17|B18|B19|B20|B21|B22|B23|B24| |C17|C18|C19|C20|C21|C22|C23|C24| |D17|D18|D19|D20|D21|D22|D23|D24|       \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | E |  |A16|A17|A18|A19|A20| |B25|B26|B27|B28|B29|B30|B31|B32| |C25|C26|C27|C28|C29|C30|C31|C32| |D25|D26|D27|D28|D29|D30|D31|D32|       \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | N |  |A21|A22|A23|A24|A25| |B33|B34|B35|B36|B37|B38|B39|B40| |C33|C34|C35|C36|C37|C38|C39|C40| |D33|D34|D35|D36|D37|D38|D39|D40|       \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | A |  |A26|A27|A28|A29|A30| |B41|B42|B43|B44|B45|B46|B47|B48| |C41|C42|C43|C44|C45|C46|C47|C48| |D41|D42|D43|D44|D45|D46|D47|D48|       \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | R |  |A31|A32|A33|A34|A35| |B49|B50|B51|B52|B53|B54|B55|B56| |C49|C50|C51|C52|C53|C54|C55|C56| |D49|D50|D51|D52|D53|D54|D55|D56|        \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | I |  |A36|A37|A38|A39|A40| |B57|B58|B59|B60|B61|B62|B63|B64| |C57|C58|C59|C60|C61|C62|C63|C64| |D57|D58|D59|D60|D61|D62|D63|D64|       \n");
    printf("       |   |  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|       \n");
    printf("       | O |  |A41|A42|A43|A44|A45| |B65|B66|B67|B68|B69|B70|B71|B72| |C65|C66|C67|C68|C69|C70|C71|C72| |D65|D66|D67|D68|D69|D70|D71|D72|       \n");
    printf("       |___|  |---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---| |---|---|---|---|---|---|---|---|\n");
    printf("               ------ Zona1 ------   ------------ Zona2 ------------   ------------ Zona3 ------------   ------------ Zona4 ------------ \n");
    printf("               ___ ___ ___ ___ ___ ___ ___ ___ ___ ___       ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___        \n");
    printf("              |E21|E22|E23|E24|E25|E26|E27|E28|E29|E30|     |F39|F40|F41|F42|F43|F44|F45|F46|F47|F48|F49|F50|F51|F52|F53|F54|F55|F56|F57|       \n");
    printf("              |---|---|---|---|---|---|---|---|---|---|     |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|       \n");
    printf("              |E31|E32|E33|E34|E35|E36|E37|E38|E39|E40|     |F58|F59|F60|F61|F62|F63|F64|F65|F66|F67|F68|F69|F70|F71|F72|F73|F74|F75|F76|       \n");
    printf("              |---|---|---|---|---|---|---|---|---|---|     |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|       \n");
    printf("               -------------- Zona5 ------------------       --------------------------------- Zona6 ----------------------------------- \n");
}
void interfazCostoBoletas() //Función que muestra los precios por zona; recorre la matriz precio e imprime el valor correspondiente a cada posición
{
    printf("Los precios de cada zona son:\n");
    printf("               _______________________________\n");
    for(int x = 0 ;x < 6    ;x ++)
    {
        printf("              | Zona %d",(x+1));
        printf(" |");
        printf(" Costo | ");
        printf("$ %.3f", precio[x]);
        printf("\n");
        printf("              |_______________________________|\n");
    }
}
void cambiarPrecio (int *zonaModificar,float *nuevoPrecio)//Función que permite la opción del administrador de modificar los precios de las boletas
{
    int pos = *zonaModificar - 1;
    precio[pos] = *nuevoPrecio; //Se aplica la modificación del preció; el valor ingresado se igual a la posición de la matriz, a esta se le resta una unidad para que corresponda a la posición escogida por el usuario
    printf("Cambio realizado con %cxito. El nuevo precio de la zona %d es $ %.3f\n",130,*zonaModificar,*nuevoPrecio); //Se imprime el nuevo precio
    interfazCostoBoletas();
}
int recorridoSillas1(int a, int b, int c, int d, int e) //Función para contabilizar las sillas disponibles y ocupadas de las zonas 1, 2, 3, 4
{
    int contadorSillasLibres     = 0;
    int contadorSillasOcupadas   = 0;
    //Se hace el recorrido de las pocisiones de la matriz correspondientes a la zona, definidas en las variable 'a','b','c','d' cuyas pocisiones se definen en el llamado dentro del caso correspondiente a cada zona
    for(int x=a;x<b;x++)
    {
        for(int y=c;y<d;y++)
        {
            if(boleteria[x][y] == 0)
                contadorSillasLibres += 1;
            else
                contadorSillasOcupadas += 1;
        }
    }
    printf("|           %d                     %d",contadorSillasLibres,contadorSillasOcupadas);
}
int recorridoSillas2(int a, int b, int c, int d, int f, int g, int h, int i, int e) //Función para contabilizar las sillas disponibles y ocupadas de las zonas 5 y 6, estas zonas se dividen en dos partes (superior e inferior) por lo que se le hacen dos recorridos a la matriz
{
    int contadorSillasLibres     = 0;
    int contadorSillasOcupadas   = 0;
    //Se hace el recorrido de las pocisiones de la matriz correspondientes a la parte 1 (superior), de la zona, definidas en las variable 'a','b','c','d' cuyas pocisiones se definen en el llamado dentro del caso correspondiente a esta zona
    for(int x=a;x<b;x++)
    {
        for(int y=c;y<d;y++)
        {
            if(boleteria[x][y] == 0)
                contadorSillasLibres += 1;
            else
                contadorSillasOcupadas += 1;
        }
    }
    //Se hace el recorrido de las pocisiones de la matriz correspondientes a la parte 2 (inferior), de la zona, definidas en las variable 'a','b','c','d' cuyas pocisiones se definen en el llamado dentro del caso correspondiente a esta zona
    for(int x=f;x<g;x++)
    {
        for(int y=h;y<i;y++)
        {
            if(boleteria[x][y] == 0)
                contadorSillasLibres += 1;
            else
                contadorSillasOcupadas += 1;
        }
    }
    printf("|           %d                     %d",contadorSillasLibres,contadorSillasOcupadas);
}
float recorridoSillasValor1(int a, int b, int c, int d, int e) //Función que muestra el valor de la boleta de las sillas vendidas de las zonas 1, 2, 3, 4
{
    float valorVendido = 0;
    //Se hace el recorrido de las pocisiones de la matriz correspondientes a la zona, definidas en las variable 'a','b','c','d' cuyas pocisiones se definen en el llamado dentro del caso correspondiente a cada zona
    for(int x=a;x<b;x++)
    {
        for(int y=c;y<d;y++)
        {
            if(boleteria[x][y] == 1)
                valorVendido += precio[e];
        }
    }
    printf("                    %.3f                   \n",valorVendido);
}
float recorridoSillasValor2(int a, int b, int c, int d, int f, int g, int h, int i, int e) //Función que muestra el valor de la boleta de las sillas vendidas de las zonas 5 y 6, estas zonas se dividen en dos partes (superior e inferior) por lo que se le hacen dos recorridos a la matriz
{
    float valorVendido = 0;
    //Se hace el recorrido de las pocisiones de la matriz correspondientes a la parte 1 (superior), de la zona, definidas en las variable 'a','b','c','d' cuyas pocisiones se definen en el llamado dentro del caso correspondiente a esta zona
    for(int x=a;x<b;x++)
    {
        for(int y=c;y<d;y++)
        {
            if(boleteria[x][y] == 1)
                valorVendido += precio[e];
        }
    }
    //Se hace el recorrido de las pocisiones de la matriz correspondientes a la parte 2 (inferior), de la zona, definidas en las variable 'f','g','h','i' cuyas pocisiones se definen en el llamado dentro del caso correspondiente a esta zona
    for(int x=f;x<g;x++)
    {
        for(int y=h;y<i;y++)
        {
            if(boleteria[x][y] == 1)
                valorVendido += precio[e];
        }
    }
    printf("                    %.3f                   \n",valorVendido);
}
int reporte () //Función que imprime el reporte para cada zona
{
    int zonaReporte;
    printf("Por favor indique la zona de la que quiere sacar el reporte:\n");
    scanf("%d",&zonaReporte);
    distribucionZonas(zonaReporte);
    switch(zonaReporte)
        //Elección zona que de la que se desee ver el reporte, en cada caso se imprime el valor de las sillas disponibles, ocupadas y el valor vendido, haciendo el llamado a las funciones 'recorridoSillas' y 'recorridoSillasValor'
    {
        case(1):
        {
            printf("\n\nA Continuaci%cn se muestra un reporte del n%cmero de sillas disponibles, ocupadas, y el valor total de ventas:\n",162,163);
            printf("________________________________________________________________________\n");
            printf("|                                  ZONA %d                              |\n",zonaReporte);
            printf("|----------------------------------------------------------------------|\n");
            printf("|  Sillas Disponibles  |   Sillas Ocupadas    |       Valor Vendido    |\n");
            printf("|----------------------------------------------------------------------|\n");
            recorridoSillas1(2,11,0,5,0);
            recorridoSillasValor1(2,11,0,5,0);
            printf("|______________________________________________________________________|\n");
            break;
        }
        case(2):
        {
            printf("\n\nA Continuaci%cn se muestra un reporte del n%cmero de sillas disponibles, ocupadas, y el valor total de ventas:\n",162,163);
            printf("________________________________________________________________________\n");
            printf("|                                  ZONA %d                              |\n",zonaReporte);
            printf("|----------------------------------------------------------------------|\n");
            printf("|  Sillas Disponibles  |   Sillas Ocupadas    |       Valor Vendido    |\n");
            printf("|----------------------------------------------------------------------|\n");
            recorridoSillas1(2,11,5,13,1);
            recorridoSillasValor1(2,11,5,13,1);
            printf("|______________________________________________________________________|\n");
            break;
        }
        case(3):
        {
            printf("\n\nA Continuaci%cn se muestra un reporte del n%cmero de sillas disponibles, ocupadas, y el valor total de ventas:\n",162,163);
            printf("________________________________________________________________________\n");
            printf("|                                  ZONA %d                              |\n",zonaReporte);
            printf("|----------------------------------------------------------------------|\n");
            printf("|  Sillas Disponibles  |   Sillas Ocupadas    |       Valor Vendido    |\n");
            printf("|----------------------------------------------------------------------|\n");
            recorridoSillas1(2,11,13,21,2);
            recorridoSillasValor1(2,11,13,21,2);
            printf("|______________________________________________________________________|\n");
            break;
        }
        case(4):
        {
            printf("\n\nA Continuaci%cn se muestra un reporte del n%cmero de sillas disponibles, ocupadas, y el valor total de ventas:\n",162,163);
            printf("________________________________________________________________________\n");
            printf("|                                  ZONA %d                              |\n",zonaReporte);
            printf("|----------------------------------------------------------------------|\n");
            printf("|  Sillas Disponibles  |   Sillas Ocupadas    |       Valor Vendido    |\n");
            printf("|----------------------------------------------------------------------|\n");
            recorridoSillas1(2,11,21,29,3);
            recorridoSillasValor1(2,11,21,29,3);
            printf("|______________________________________________________________________|\n");
            break;
        }
        case(5):
        {
            printf("\n\nA Continuaci%cn se muestra un reporte del n%cmero de sillas disponibles, ocupadas, y el valor total de ventas:\n",162,163);
            printf("________________________________________________________________________\n");
            printf("|                                  ZONA %d                              |\n",zonaReporte);
            printf("|----------------------------------------------------------------------|\n");
            printf("|  Sillas Disponibles  |   Sillas Ocupadas    |       Valor Vendido    |\n");
            printf("|----------------------------------------------------------------------|\n");
            recorridoSillas2(0,2,0,10,13,15,0,10,4);
            recorridoSillasValor2(0,2,0,10,13,15,0,10,4);
            printf("|______________________________________________________________________|\n");
            break;
        }
        case(6):
        {
            printf("\n\nA Continuaci%cn se muestra un reporte del n%cmero de sillas disponibles, ocupadas, y el valor total de ventas:\n",162,163);
            printf("________________________________________________________________________\n");
            printf("|                                  ZONA %d                              |\n",zonaReporte);
            printf("|----------------------------------------------------------------------|\n");
            printf("|  Sillas Disponibles  |   Sillas Ocupadas    |       Valor Vendido    |\n");
            printf("|----------------------------------------------------------------------|\n");
            recorridoSillas2(0,2,10,29,13,15,10,29,5);
            recorridoSillasValor2(0,2,10,29,13,15,10,29,5);
            printf("|______________________________________________________________________|\n");
            break;
        }
    }
}
void cambioClave(char x[longitud]) //Función para establecer un cambio de la contraseña
{
    char nuevaContrasenia[longitud];
    if(strcmp(x,contraseniaActual)==0)
    {
        printf("Ingrese la nueva contrase%ca:\n",164);
        gets(nuevaContrasenia);
        strcpy(contraseniaActual, nuevaContrasenia);;
        printf("Su nueva contrase%ca es: %s\n" ,164,contraseniaActual);
    }
    else
    {
        printf("\nContrase%ca incorrecta\n",164);
    }
}
void nombreUsuarios() //Función que da el mensaje de bienvenida con el nombre a cada usuario
{

    printf("Por favor ingrese su nombre completo: \n");
    fgets(nombreUsuario,sizeof(nombreUsuario),stdin);
    fgets(nombreUsuario,sizeof(nombreUsuario),stdin);
    printf("Bienvenido ");
    fp = fopen( "Factura.txt", "a"); //Se abre y se imprime en el archivo de factura la variable correspondiente
    fprintf(fp,"                              %s                          \n", nombreUsuario);
    fclose(fp);
    puts(nombreUsuario);
}
void distribucionZonas (int zonaDeseada) //Función para mostrar la distribución de  los asientos por zona
{
    if(zonaDeseada == 1) //Zona 1
    {
        int contador = 0;
        int conteo = 0;
        printf("  ____   ____   ____   ____   ____ \n");
        for(int x=2;x<11;x++)
        {
            for(int y=0;y<5;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0) //Condicional que define la disponibilidad de los asientos, si hay sillas disponibles:
                {
                    if(conteo < 10) //Si el número correspondiente a la enumeración de la silla solo tiene unidades (menor que 10) se imprime un espacio de más
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else //Si dicho número tiene décimas (no es menor que 10) se imprime sin espacio
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0) //Si no hay sillas disponibles:
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador += 1;
                if(contador == 5 && x!=10)
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____ \n");
                }
            }
        }
    }
    else if(zonaDeseada == 2) //Zona 2; se lleva a cabo el mismo proceso que el la primera
    {
        int conteo = 0;
        int contador = 0;
        printf("  ____   ____   ____   ____   ____   ____   ____   ____ \n");
        for(int x=2;x<11;x++)
        {
            for(int y=5;y<13;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0)
                {
                    if(conteo < 10)
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0)
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador += 1;
                if(contador == 8 && x!=10 )
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____   ____   ____   ____ \n");
                }
            }
        }
    }
    else if(zonaDeseada == 3) //Zona 3; se lleva a cabo el mismo proceso que el la primera
    {
        int conteo = 0;
        int contador = 0;
        printf("  ____   ____   ____   ____   ____   ____   ____   ____ \n");
        for(int x=2;x<11;x++)
        {
            for(int y=13;y<21;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0)
                {
                    if(conteo < 10)
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0)
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador += 1;
                if(contador == 8 && x!=10 )
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____   ____   ____   ____ \n");
                }
            }
        }
    }
    else if(zonaDeseada == 4) //Zona 4; se lleva a cabo el mismo proceso que el la primera
    {
        int conteo = 0;
        int contador = 0;
        printf("  ____   ____   ____   ____   ____   ____   ____   ____ \n");
        for(int x=2;x<11;x++)
        {
            for(int y=21;y<29;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0)
                {
                    if(conteo < 10)
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0)
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador += 1;
                if(contador == 8 && x!=10 )
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____   ____   ____   ____ \n");
                }
            }
        }
    }
    else if(zonaDeseada == 5) //Zona 5; se lleva a cabo el mismo proceso que el la primera
    {
        int conteo = 0;
        int contador = 0;
        printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
        for(int x=0;x<2;x++)
        {
            for(int y=0;y<10;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0)
                {
                    if(conteo < 10)
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0)
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador += 1;
                if(contador == 10 && x!=1 )
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
                }
            }
        }
        printf("\n\n\n\n");
        int contador2 = 0;
        printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
        for(int x=13;x<15;x++)
        {
            for(int y=0;y<10;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0)
                {
                    if(conteo < 10)
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0)
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador2 += 1;
                if(contador2 == 10 && x!=14 )
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
                }
            }
        }
    }
    else if(zonaDeseada == 6) //Zona 6; se lleva a cabo el mismo proceso que el la primera
    {
        int conteo = 0;
        int contador = 0;
        printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
        for(int x=0;x<2;x++)
        {
            for(int y=10;y<29;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0)
                {
                    if(conteo < 10)
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0)
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador += 1;
                if(contador == 19 && x!=1 )
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
                }
            }
        }
        printf("\n\n\n\n");
        int contador2 = 0;
        printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
        for(int x=13;x<15;x++)
        {
            for(int y=10;y<29;y++)
            {
                conteo += 1;
                printf(" |");
                if(boleteria[x][y] == 0)
                {
                    if(conteo < 10)
                    {
                        printf("%d  L",conteo);
                        printf("|");
                    }
                    else
                    {
                        printf("%d L",conteo);
                        printf("|");
                    }
                }
                else if(conteo < 10 && boleteria[x][y] != 0)
                {
                    printf("%d  V",conteo);
                    printf("|");
                }
                else
                {
                    printf("%d V",conteo);
                    printf("|");
                }
                contador2 += 1;
                if(contador2 == 19 && x!=14 )
                {
                    contador = 0;
                    printf("\n");
                    printf("  ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____   ____ \n");
                }
            }
        }
    }
}
int comprarBoleta () //Función que establece el número de boletas que el usuario desee comprar
{
    int continuar = 2;
    while (continuar == 2)
    {
        puts(nombreUsuario);
        printf("Escriba el n%cmero de boletas a comprar: ",163);
        scanf("%d",&numeroBoletas);
        fp = fopen( "Factura.txt", "a");
        fprintf(fp,"       *     Cantidad de boletas:            %d         *\n",numeroBoletas); //Se imprime en el archivo de factura la variable correspondiente
        fclose(fp);
        printf("El n%cmero de boletas es: %d.\nDesea continuar?\n",163,numeroBoletas);
        printf("S%c ----> 1\n",161);
        printf("No ----> 2\n");
        scanf("%d", &continuar);
    }
}
void recorridoZona1(int a, int b, int c, int d, int e) //Función que realiza la compra que se desee en las zonas 1, 2, 3, 4
{
    int contador = 0;
    //Se hace el recorrido de las pocisiones de la matriz correspondientes a la zona, definidas en las variable 'a', 'b', 'c', 'd' cuyas pocisiones se definen en el llamado dentro del caso correspondiente a esta zona
    for(int x=a;x<b;x++)
    {
        for(int y=c;y<d;y++)
        {
            contador+=1;
            if(contador == sillaGlobal)
            {
                if(boleteria[x][y] == 0) //Condicional que evalúa la disponibilidad de la silla seleccionada
                {
                    printf("La silla seleccionada fue la n%cmero %d y se encuentra disponible\n",163,contador);
                    printf("El valor de la compra es de $ %.3f\n", precio[e]);
                    float precio_total=(float)numeroBoletas*precio[e];
                    printf("Por favor ingrese el dinero con el que va a realizar el pago\n");
                    scanf ("%f",&dineroUsuario);
                    suma=suma+dineroUsuario;
                    fp = fopen( "Factura.txt", "a"); //Se abre y se imprime en el archivo de factura la variable correspondiente
                    fprintf(fp,"       *     precio por unidad:           %.3f           \n", precio[e]);
                    fprintf(fp,"       *     precio total:                %.3f           \n", precio_total);
                    fprintf(fp,"       *     Dinero entregado:            %.3f           \n", suma);
                    fclose(fp);
                    if(dineroUsuario < precio[e]) //Condición que evalúa si la cantidad del dinero del usuario corresponde al precio de la silla; si el dinero del usuario es menor:
                    {
                        float dineroFaltante = precio[e] - dineroUsuario;
                        printf("Le hace falta: $ %.3f\n",dineroFaltante);
                    }
                    else //Si el dinero del usuario es mayor o igual:
                    {
                        vueltos = dineroUsuario - precio[e];
                        volverComprar = 1;
                        boleteria[x][y] = 1;
                        printf("\nBoleta vendida con %cxito\n",130);
                        printf("Sus vueltos son $ %.3f\n",vueltos);
                        suma1=suma1+vueltos;
                        fp = fopen( "Factura.txt", "a"); //Se abre y se imprime en el archivo de factura la variable correspondiente
                        fprintf(fp,"       *     Cambio:                      %.3f           \n", suma1);
                        fprintf(fp,"       *************************************************\n");
                        fclose(fp);
                        //GenerarFactura(zonaInteres,e,dineroUsuario,vueltos); //Llamado a función para hacer factura
                    }
                }
                else
                {
                    printf("Error, la posici%cn indicada ya se encuentra vendida.\n",162);
                    break;
                    break;
                }
            }
        }
    }
}
void recorridoZona2(int a, int b, int c, int d, int e, int f, int g, int h, int i) //Función que realiza la compra que se desee en las zonas 5 y 6, estas zonas se dividen en dos partes (superior e inferior) por lo que se le hacen dos recorridos a la matriz
{
    int contador = 0;
    //Recorrido zona parte 1 (superior), se ejecuta de igual manera que en la función 'recorridoZona1'
    for(int x=a;x<b;x++)
    {
        for(int y=c;y<d;y++)
        {
            contador+=1;
            if(contador == sillaGlobal)
            {
                if(boleteria[x][y] == 0)
                {
                    printf("La silla seleccionada fue la n%cumero %d y se encuentra disponible\n",163,contador);
                    printf("El valor de la compra es de $ %.3f\n", precio[e]);
                    float precio_total=(float)numeroBoletas*precio[e];
                    printf("Por favor ingrese el dinero con el que va a realizar el pago\n");
                    scanf ("%f",&dineroUsuario);
                    suma=suma+dineroUsuario;
                    fp = fopen( "Factura.txt", "a");
                    fprintf(fp,"       *     precio por unidad:           %.3f           \n", precio[e]);
                    fprintf(fp,"       *     precio total:                %.3f           \n", precio_total);
                    fprintf(fp,"       *     Dinero entregado:            %.3f           \n", suma);
                    fclose(fp);
                    if(dineroUsuario < precio[e])
                    {
                        volverComprar = 0;
                        float dineroFaltante = precio[e] - dineroUsuario;
                        printf("Le hace falta: $ %.3f\n",dineroFaltante);
                    }
                    else
                    {
                        vueltos = dineroUsuario - precio[e];
                        volverComprar = 1;
                        boleteria[x][y] = 1;
                        printf("\nBoleta vendida con %cxito\n",130);
                        printf("Sus vueltos son $ %.3f\n",vueltos);
                        suma1=suma1+vueltos;
                        fp = fopen( "Factura.txt", "a");
                        fprintf(fp,"       *     Cambio:                      %.3f           \n", suma1);
                        fprintf(fp,"       *************************************************\n");
                        fclose(fp);
                        //GenerarFactura(zonaInteres,e,dineroUsuario,vueltos); //Llamado a función para hacer factura
                    }
                }
                else
                {
                    printf("Error, la posici%cn indicada ya se encuentra vendida.\n",162);
                    break;
                    break;
                }
            }
        }
    }
    //Recorrido zona parte 2 (inferior), se ejecuta de igual manera que en la función 'recorridoZona1'
    for(int x=f;x<g;x++)
    {
        for(int y=h;y<i;y++)
        {
            contador+=1;
            if(contador == sillaGlobal)
            {
                if(boleteria[x][y] == 0)
                {
                    printf("La silla seleccionada fue la n%cmero %d y se encuentra disponible\n",163,contador);
                    printf("El valor de la compra es de $ %.3f\n", precio[e]);
                    float precio_total=(float)numeroBoletas*precio[e];
                    printf("Por favor ingrese el dinero con el que va a realizar el pago\n");
                    scanf ("%f",&dineroUsuario);
                    suma=suma+dineroUsuario;
                    fp = fopen( "Factura.txt", "a");
                    fprintf(fp,"       *     precio por unidad:           %.3f           \n", precio[e]);
                    fprintf(fp,"       *     precio total:                %.3f           \n", precio_total);
                    fprintf(fp,"       *     Dinero entregado:            %.3f           \n", suma);
                    fclose(fp);
                    if(dineroUsuario < precio[e])
                    {
                        volverComprar = 0;
                        float dineroFaltante = precio[e] - dineroUsuario;
                        printf("Le hace falta: $ %.3f:",dineroFaltante);
                    }
                    else
                    {
                        vueltos = dineroUsuario - precio[e];
                        volverComprar = 1;
                        boleteria[x][y] = 1;
                        printf("\nBoleta vendida con %cxito\n",130);
                        printf("Sus vueltos son $ %.3f\n",vueltos);
                        suma1=suma1+vueltos;
                        fp = fopen( "Factura.txt", "a");
                        fprintf(fp,"       *     Cambio:                      %.3f           \n", suma1);
                        fprintf(fp,"       *************************************************\n");
                        fclose(fp);
                        //GenerarFactura(zonaInteres,e,dineroUsuario,vueltos); //Llamado a función para hacer factura
                    }
                }
                else
                {
                    printf("Error, la posici%cn indicada ya se encuentra vendida.\n",162);
                    break;
                    break;
                }
            }
        }
    }
}
/*void GenerarFactura(int zonaInteres,int e,float dineroUsuario, float vueltos) //Función que genera la factura de compra y crea un archivo
{


//Se crea el archivo.txt y en función de writer
fp = fopen ("Factura.txt","w");
//Se hace uso de la función fprintf para escribir en el documento
fprintf (fp,"|-----------------Recibo de pago----------------|\n");
fprintf (fp,"|-----------------------------------------------|\n");
fprintf (fp,"\t\tCliente: ");
for(int i=0;i<8;i++){
    fprintf(fp,"%c",nombreUsuario[i]);
}
fprintf (fp,"\n|-----------------------------------------------|");
fprintf (fp,"\n|Cantidad de boletas compradas:\t|\t %d\t|",numeroBoletas);
fprintf (fp,"\n|-----------------------------------------------|");
fprintf (fp,"\n|Zona de las boletas:\t\t|\t %d\t|",zonaInteres);
fprintf (fp,"\n|-----------------------------------------------|");
fprintf (fp,"\n|Precio por unidad:\t\t|\t %.3f\t|",precio[e]);
fprintf (fp,"\n|-----------------------------------------------|");
fprintf (fp,"\n|Precio total:\t\t\t|\t %d\t|",precio_total);
fprintf (fp,"\n|-----------------------------------------------|");
fprintf (fp,"\n|Total pagado:\t\t\t|\t %.3f\t|",dineroUsuario);
fprintf (fp,"\n|-----------------------------------------------|");
fprintf (fp,"\n|Cambio:\t\t\t|\t %.3f\t|",vueltos);
fprintf (fp,"\n|-----------------------------------------------|");
fclose (fp);//Se cierra el documento
}*/
int main() //Función principal, estructura del programa
{
    fp = fopen( "Factura.txt", "a"); //Se abre el archivo y se empieza a escribir la factura
    fprintf(fp,"\n\n       *************************************************\n");
    fprintf(fp,"       *                    FACTURA                    *\n");
    fprintf(fp,"       *************************************************\n");
    fclose(fp);
    while(TRUE)
    {
        menu=0;
        entrarAdministrador =0;
        interfazInicio(menu);
        printf("Ingrese el n%cmero del men%c al que desea acceder:\n",163,163);
        scanf("%d", &menu);
        switch (menu)
            //Selección menú inicial
        {
            case (1): //Opción administrador
            {

                getchar();
                printf("Por favor ingrese la contrase%ca de administrador:\n",164);
                gets(contraseniaC);
                contrasenia(contraseniaC);
                if(entrarAdministrador == 1)
                {
                    interfazAdminstrador(menu);
                    printf("Ingrese el n%cmero del men%c al que desea acceder:\n",163,163);
                    int menu1;
                    scanf("%d", &menu1);
                    switch(menu1)
                        //Selección menú administrador
                    {
                        case(1):
                            interfazCostoBoletas(); //Llamado a la función que muestra los precios por zona
                            printf("Por favor ingrese la zona que desea modificar:\n"); //Se pregunta la zona a modificar
                            scanf("%d", &zonaModificar);
                            printf("Por favor ingrese el nuevo valor de la zona %d:\n",zonaModificar); //Se pregunta el nuevo valor que se quiere
                            scanf("%f", &nuevoPrecio);
                            cambiarPrecio(&zonaModificar,&nuevoPrecio); //Se llama a la función que ejecuta la acción de cambiar los precios
                            break;
                        case(2):
                            reporte(); //Se llama a la función que ejecuta la acción de mostrar el reporte
                            break;
                        case(3):
                            getchar();
                            printf("Ingrese la contrase%ca actual\n",164);
                            gets(contraseniaC);
                            cambioClave(contraseniaC); //Se llama a la función que ejecuta la acción de cambiar la contraseña
                            break;
                        case(4):
                            break;
                        default:
                            break;
                    }
                }

            }
                break;
            case (2): //Opción usuario
            {
                int zonaInteres;
                volverComprar = 0;
                nombreUsuarios();
                suma=0;
                suma1=0;
                dineroUsuario=0;
                vueltos=0;
                while(volverComprar == 0)
                {
                    interfazCostoBoletas();
                    sleep(5);
                    printf("\nLa distribuci%cn de zonas es la siguiente: \n\n",162);
                    visualizacionZonas (); //Llamado a la función que permite ver la ubicación de los asientos por zona
                    comprarBoleta(); //Llamado a la función que ejecuta la compra de alguna bolet
                    printf("Digite la zona de su gusto\n");
                    scanf("%d",&zonaInteres);
                    fp = fopen( "Factura.txt", "a");
                    fprintf(fp,"       *     zona de compra:                 %d         *\n",zonaInteres);
                    fclose(fp);

                    printf("A continuaci%cn se muestran la disponibilidad de las sillas. V es vendida y L libre\n",162);
                    if(numeroBoletas!=1) //Si el usuario desea comprar más de una boleta:
                    {
                        distribucionZonas(zonaInteres); //Se llama a la función que mustra la distrubución de los asientos por cada zona
                        int silla;
                        int suma;
                        for(int i = 0; i<numeroBoletas; i++)
                        {
                            silla += 1;
                            printf("\n\nSilla %d:Por favor ingrese %cnicamente el n%cmero de boleta\n",silla,163,163);
                            scanf("%d",&sillaGlobal);
                            switch(zonaInteres) //Selección zona que desee el cliente
                            {
                                case(1):
                                    recorridoZona1(2,11,0,5,0);
                                    break;
                                case(2):
                                    recorridoZona1(2,11,5,13,1);
                                    break;
                                case(3):
                                    recorridoZona1(2,11,13,21,2);
                                    break;
                                case(4):
                                    recorridoZona1(2,11,21,29,3);
                                    break;
                                case(5):
                                    recorridoZona2(0,2,0,10,4,13,15,0,10);
                                    break;
                                case(6):
                                    recorridoZona2(0,2,10,29,5,13,15,10,29);
                                    break;
                            }
                        }
                    }
                    else //Si el usuario desea comprar una boleta:
                    {
                        distribucionZonas(zonaInteres);
                        printf("\n\n");
                        puts(nombreUsuario);
                        printf("Por favor ingrese %cnicamente el n%cmero de la silla que desea comprar:\n",163,163);
                        scanf("%d",&sillaGlobal);
                        switch(zonaInteres) //Selección zona que desee el cliente
                        {
                            case(1):
                                recorridoZona1(2,11,0,5,0);
                                break;
                            case(2):
                                recorridoZona1(2,11,5,13,1);
                                break;
                            case(3):
                                recorridoZona1(2,11,13,21,2);
                                break;
                            case(4):
                                recorridoZona1(2,11,21,29,3);
                                break;
                            case(5):
                                recorridoZona2(0,2,0,10,4,13,15,0,10);
                                break;
                            case(6):
                                recorridoZona2(0,2,10,29,5,13,15,10,29);
                                break;
                        }
                    }
                }
                break;
            }
                break;
            case (3): //Opción salir
                return(0);
            default:
                printf("\nD%cgito inv%clido\n",164,160);
                break;
        }
    }
}
