#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

char BRAZIL[3] = "BRA";
char MAR_DEL_PLATA[3] = "MDQ";
char MENDOZA[3] = "MZA";
char BARILOCHE[3] = "BRC";

int IMPORTE_BRAZIL = 25000;
int IMPORTE_MAR_DEL_PLATA = 14000;
int IMPORTE_MENDOZA=  19000;
int IMPORTE_BARILOCHE = 23000;
int SEGURO_NINOS=  2000;
int RECARGO_TARJETA = 0.05;

int CAPACIDAD_MAXIMA = 60;

int COLUMNAS = 5;
int cant_pasajeros;

//ORDENA Y MUESTRA LISTA ORDENADA POR APELLIDO Y NOMBRE
void mostrar_lista_ordenada_por_apellido_nombre(char (*pasajeros)[5][50]){
    int i,j, pos_menor;
    char aux[50], menor[100], mayor[100];

    //COMPARA EL VALOR MENOR CON TODO LOS VALORES PARA DEFINIR CUAL ES EL MENOR
    for ( i = 0; i < cant_pasajeros - 1; i++)
    {
        pos_menor = i;
        for ( j = i+1; j < cant_pasajeros; j++)
        {
            strcpy(menor,pasajeros[pos_menor][1]);
            strcat(menor,pasajeros[pos_menor][2]);
            strcpy(mayor,pasajeros[j][1]);
            strcat(mayor,pasajeros[j][2]);
            if(strcasecmp(menor,mayor) > 0)
            {
                pos_menor = j;
            }
        }
        for ( j = 0; j < COLUMNAS; j++)
        {
            strcpy(aux, pasajeros[i][j]);
            strcpy(pasajeros[i][j],pasajeros[pos_menor][j]);
            strcpy(pasajeros[pos_menor][j],aux);
        }
    }
    
    
    //REMPLAZA EL VALOR MENOR EN LA POSICION DEL VALOR COMPARADO
    for ( i = 0; i < cant_pasajeros; i++)
    {
        printf("%s %s, DNI: %s, Edad: %s, Destino: %s\n", pasajeros[i][1], pasajeros[i][2],pasajeros[i][0],pasajeros[i][3],pasajeros[i][4]);
        printf("------------\n");
    }
}


//RECIBE UN ARRAY CON 4 VALORES Y DEVUELVE EL INDICE DEL MAYOR
int devolver_mayor(float (*arreglo)[4]){
    int i;
    int pos_mayor = 0;
    for ( i = 0; i < 4; i++)
    {
        if (arreglo[pos_mayor][0] < arreglo[i][0])
        {
            pos_mayor = i;
        }
    }
    return pos_mayor;
}


//RECIBE EL ARRAY CON LAS ESTADISTICAS Y LO MUESTRA
void mostrar(float (*estadisticas)[4], char *mayor){
    printf("El %.2f%% eligio Brazil como destino, y el %.2f%% es menor de 5 anos\n",
    estadisticas[0][2], estadisticas[0][3]);
    printf("El %.2f%% eligio Mar del Plata como destino, y el %.2f%% es menor de 5 anos\n",
    estadisticas[1][2], estadisticas[1][3]);
    printf("El %.2f%% eligio Mendoza como destino, y el %.2f%% es menor de 5 anos\n",
    estadisticas[2][2], estadisticas[2][3]);
    printf("El %.2f%% eligio Bariloche como destino, y el %.2f%% es menor de 5 anos\n",
    estadisticas[3][2], estadisticas[3][3]);

    printf("El destino mas seleccionado es %s", mayor);
}


//CALCULA ESTADISTICAS DE LOS PASAJEROS
void mostrar_estadisticas(char (*pasajeros)[5][50]){
    //ESTADISTICAS:
    //FILA 0: BRZ
    //FILA 1: MDQ
    //FILA 2: MZA
    // FILA 3: BRC

    //COLUMNA 0: CANTIDAD
    //COLUMNA 1: CANT. MENORES
    //COLUMNA 2: PORC. PERSONAS
    //CANTIAD 3: POR. DE MENORES

    float estadisticas[4][4] = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };
    int i;
    int pos_mayor;
    char mayor[14];
    
    
    
    //CALCULO PERSONAS X DESTINO
    for ( i = 0; i < cant_pasajeros; i++)
    {
        if (strcasecmp(pasajeros[i][4],"BRA") == 0)
        {
            estadisticas[0][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[0][1]++;
            }
        }
        if (strcasecmp(pasajeros[i][4],"MDQ") == 0)
        {
            
            estadisticas[1][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[1][1]++;
            }
        }
        if (strcasecmp(pasajeros[i][4],"MZA") == 0)
        {
          
            estadisticas[2][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[2][1]++;
            }
        }
        if (strcasecmp(pasajeros[i][4],"BRC") == 0)
        {
     
            estadisticas[3][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[3][1]++;
            }
        }
    }




    //OBTENGO EL INDICE DEL DESTINO CON MAS PERSONAS
    pos_mayor = devolver_mayor(estadisticas);
    switch (pos_mayor)
    {
    case 0:
        strcpy(mayor,"Brazil");
        break;
    case 1:
        strcpy(mayor,"Mar del Plata");
        break;
    case 2:
        strcpy(mayor,"Mendoza");
        break;
    case 3:
        strcpy(mayor,"Bariloche");
        break;
    }


    //CALCULO DE PORCENTAJE DE PASAJEROS Y PORCENTAJE DE MENORES
    for ( i = 0; i < 4; i++)
    {
        estadisticas[i][2] = (estadisticas[i][0] / cant_pasajeros)*100;
        estadisticas[i][3] = (estadisticas[i][1] / estadisticas[i][0])*100;
    }


    mostrar(estadisticas, mayor);
}


int main() {
    int opcion;
    printf("Ingrese la cantidad de pasajeros que va a ingresar\n");
    scanf("%d", &cant_pasajeros);
    //char pasajeros[cant_pasajeros][5][50];
    char pasajeros[cant_pasajeros][5][50];
    //cargar_pasajeros(pasajeros);
    do {
        printf("\nMenu de opciones:\n");
        printf("1. Mostrar lista de pasajeros ordenada por apellido y nombre\n");
        printf("2. Mostrar lista de pasajeros ordenada por Codigo Destino y Apellido - Nombre\n");
        printf("3. Mostrar lista de Destinos\n");
        printf("4. Buscar por pasajero\n");
        printf("5. Mostrar estadisticas\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                mostrar_lista_ordenada_por_apellido_nombre(pasajeros);
                break;
            case 2:
               // mostrar_lista_ordenada_por_destino(pasajeros);
                break;
            case 3:
                //mostrar_lista_de_destinos(pasajeros);
                break;
            case 4:
               // buscar_por_pasajero(pasajeros);
                break;
            case 5:
                mostrar_estadisticas(pasajeros);
                break;
            case 6:
                printf("Gracias por utilizar Viaje Mágico.\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);
    
    return 0;
}