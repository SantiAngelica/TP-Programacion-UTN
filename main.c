#include <stdio.h>
#include <string.h>
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


int cant_pasajeros;

int Validad_DNI();



int main() {
    int opcion;
    printf("Ingrese la cantidad de pasajeros que va a ingresar\n");
    scanf("%d", &cant_pasajeros);
    char pasajeros[cant_pasajeros][5][50];

    cargar_pasajeros(pasajeros);
    do {
        printf("\nMenú de opciones:\n");
        printf("1. Mostrar lista de pasajeros ordenada por Apellido y Nombre\n");
        printf("2. Mostrar lista de pasajeros ordenada por Código Destino y Apellido - Nombre\n");
        printf("3. Mostrar lista de Destinos\n");
        printf("4. Buscar por pasajero\n");
        printf("5. Mostrar estadísticas\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                mostrar_lista_ordenada_por_apellido(pasajeros);
                break;
            case 2:
                mostrar_lista_ordenada_por_destino(pasajeros);
                break;
            case 3:
                mostrar_lista_de_destinos(pasajeros);
                break;
            case 4:
                buscar_por_pasajero(pasajeros);
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


int Valida_DNI(char *dni){
    int erroneo=0;
    int longi=strlen(dni);
    for (int i = 0; i < longi; i++)
    {
        if (!isdigit(dni[i]))
        {
            erroneo=1
        }
        
    }
    if (!(dni>=5000000 && dni<=6999999) || !(dni>=10000000 && dni<=59999999))
    {
        erroneo=1;
    }
    if (erroneo==1)
    {
        printf("Formato de DNI erroneo, ingrese un DNI valido");
    }
    
    return erroneo
}

void Mostrar_destinos(char *pasajeros,int cantPasaj){
    int sum_bra=0;
    int sum_BRC=0;
    int sum_MZA=0;
    int sum_MDQ=0;
    int cant_bra=0;
    int cant_BRC=0;
    int cant_MZA=0;
    int cant_MDQ=0;

    for (int i = 0; i < cantPasaj; i++)
    {
        if (pasajeros[i][5]=="BRA")
        {
            sum_bra=sum_bra+pasajeros[i][6];
            cant_bra++
        }
        else if (pasajeros[i][5]=="BRC")
        {
            sum_BRC=sum_BRC+pasajeros[i][6];
            cant_BRC++
        }
        else if (pasajeros[i][5]=="MZA")
        {
            sum_MZA=sum_MZA+pasajeros[i][6];
            cant_MZA++
        }
        else if (pasajeros[i][5]=="MDQ")
        {
            sum_MDQ=sum_MDQ+pasajeros[i][6];
            cant_MDQ++
        }
    }
    
    printf("Codigo de destino: BRA\nCantidad de pasajeros:%i\nimporte total:%i",cant_bra,sum_bra);
    printf("Codigo de destino: BRC\nCantidad de pasajeros:%i\nimporte total:%i",cant_BRC,sum_BRC);
    printf("Codigo de destino: MZA\nCantidad de pasajeros:%i\nimporte total:%i",cant_MZA,sum_MZA);
    printf("Codigo de destino: MDQ\nCantidad de pasajeros:%i\nimporte total:%i",cant_MDQ,sum_MDQ);
}