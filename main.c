#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char BRAZIL[4] = "BRA";
char MAR_DEL_PLATA[4] = "MDQ";
char MENDOZA[4] = "MZA";
char BARILOCHE[4] = "BRC";

int IMPORTE_BRAZIL = 25000;
int IMPORTE_MAR_DEL_PLATA = 14000;
int IMPORTE_MENDOZA = 19000;
int IMPORTE_BARILOCHE = 23000;
int SEGURO_NINOS = 2000;
float RECARGO_TARJETA = 0.05;

int CAPACIDAD_MAXIMA = 60;

int cant_pasajeros;


int main() {
    int opcion;
    printf("Ingrese la cantidad de pasajeros que va a ingresar\n");
    scanf("%d", &cant_pasajeros);

    // mostrar_tabla_destinos();

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
                // Implementación pendiente si se requiere
                printf("Funcionalidad no implementada.\n");
                break;
            case 2:
                // Implementación pendiente si se requiere
                printf("Funcionalidad no implementada.\n");
                break;
            case 3:
                // Implementación pendiente si se requiere
                printf("Destinos.\n");
                mostrar_tabla_destinos();
                break;
            case 4:
                // Implementación pendiente si se requiere
                printf("Funcionalidad no implementada.\n");
                break;
            case 5:
                // Implementación pendiente si se requiere
                printf("Funcionalidad no implementada.\n");
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

void mostrar_tabla_destinos() {
    printf("\nTabla de Códigos e Importes de Viaje:\n");
    printf("-------------------------------------\n");
    printf("Código\t| Destino\t\t| Importe\n");
    printf("-------------------------------------\n");
    printf("%s\t| %s\t\t| $%d\n", BRAZIL, "BRAZIL", IMPORTE_BRAZIL);
    printf("%s\t| %s\t\t| $%d\n", MAR_DEL_PLATA, "MAR DEL PLATA", IMPORTE_MAR_DEL_PLATA);
    printf("%s\t| %s\t\t| $%d\n", MENDOZA, "MENDOZA", IMPORTE_MENDOZA);
    printf("%s\t| %s\t\t| $%d\n", BARILOCHE, "BARILOCHE", IMPORTE_BARILOCHE);
    printf("-------------------------------------\n");
}
