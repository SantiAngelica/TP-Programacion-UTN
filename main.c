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