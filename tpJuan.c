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

char dni[CAPACIDAD_MAXIMA][9];
char apellido[CAPACIDAD_MAXIMA][50];
char nombre[CAPACIDAD_MAXIMA][50];
int edad[CAPACIDAD_MAXIMA];
char codigo_destino[CAPACIDAD_MAXIMA][4];
int cuposBRA = 0, cuposMDQ = 0, cuposMZA = 0, cuposBRC = 0;

int total_pasajeros;

int cant_pasajeros;

void ordenar_por_destino(char (*pasajeros)[5][50]);

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

void cargar_pasajeros(char (*pasajeros)[5][50]){
    
    for (int i = 0; i < cant_pasajeros; i++)
    {
        do
        {
            printf("Ingrese su DNI: ");
            scanf("%s", dni[i]);
            if (!validar_dni(dni[i]))
            {
                printf("El DNI es invalido, ingrese nuevamente. Recuerda, debe contener entre 7 y 8 dígitos y debe comenzar con 5, 6, y desde 10 hasta 60");
            }
            
        } while (!validar_dni(dni[i]));
        
        printf("Ingrese su apellido: ");
        scanf("%s",apellido[i]);

        printf("Ingrese su nombre: ");
        scanf("%s",nombre[i]);

        printf("Ingrese su edad: ");
        scanf("%i",edad[i]);

        printf("Ingrese Código de Destino (BRA, MDQ, MZA, BRC): ");
        scanf("%s", codigo_destino[i]);

        while (strcmp(codigo_destino[i], "BRA") != 0 && strcmp(codigo_destino[i], "MDQ") != 0 && strcmp(codigo_destino[i], "MZA") != 0 && strcmp(codigo_destino[i], "BRC") != 0) {
            printf("Codigo erroneo, ingrese de nuevo(BRA, MDQ, MZA, BRC): ");
            scanf("%s", codigo_destino[i]);
        }

        if ( strcmp(codigo_destino[i], "BRA") == 0 )
        {
            if (cuposBRA > 60)
            {
                printf("Capacidad maxima alcanzada para Brasil!");
            } 
            else {
                cuposBRA ++;
            }
        } else if (( strcmp(codigo_destino[i], "MDQ") == 0 ))
        {
            if (cuposMDQ > 60)
            {
                printf("Capacidad maxima alcanzada para Mar del Plata!");
            } 
            else {
                cuposMDQ ++;
            }
        } else if (( strcmp(codigo_destino[i], "MZA") == 0 ))
        {
            if (cuposMZA > 60)
            {
                printf("Capacidad maxima alcanzada para Mendoza!");
            } 
            else {
                cuposMZA ++;
            }
        } else if (( strcmp(codigo_destino[i], "BRC") == 0 ))
        {
            if (cuposBRC > 60)
            {
                printf("Capacidad maxima alcanzada para Bariloche!");
            } 
            else {
                cuposBRC ++;
            }
        }
        
        total_pasajeros++;
    }
    
}

void ordenar_por_destino(char (*pasajeros)[5][50]){
    int pos_menor;
    
    for (int i = 0; i < total_pasajeros - 1 ; i++)
    {
        pos_menor = i;

        for (int j = i + 1; i < total_pasajeros; i++)
        {
            if (strcmp(codigo_destino[i],codigo_destino[j] > 0 || strcmp(codigo_destino[i],codigo_destino[j] == 0 && strcmp(apellido[i], apellido[j]) > 0)))
            {
                // Intercambiar codigo_destino
                char aux[50];
                strcpy(aux, codigo_destino[i]); 
                strcpy(codigo_destino[i], codigo_destino[j]); 
                strcpy(codigo_destino[j], aux);

                // Intercambiar apellido
                strcpy(aux, apellido[i]); 
                strcpy(apellido[i], apellido[j]); 
                strcpy(apellido[j], aux); 

                // Intercambiar nombre
                strcpy(aux, nombre[i]); 
                strcpy(nombre[i], nombre[j]); 
                strcpy(nombre[j], aux);

                // Intercambiar dni
                strcpy(aux, dni[i]); 
                strcpy(dni[i], dni[j]); 
                strcpy(dni[j], aux); 

                // Intercambiar edad
                int auxEdad;
                auxEdad = edad[i]; 
                edad[i] = edad[j];
                edad[j] = auxEdad; 

            }
            
        }
        
    }

    
}
    

void mostrar_lista_ordenada_por_destino(char (*pasajeros)[5][50]) {
    for (int i = 0; i < total_pasajeros; i++) {
        printf("%s - %s %s - DNI: %s - Edad: %d\n", codigo_destino[i], apellido[i], nombre[i], dni[i], edad[i]);
    }
}