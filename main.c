#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

char BRAZIL[3] = "BRA";
char MAR_DEL_PLATA[3] = "MDQ";
char MENDOZA[3] = "MZA";
char BARILOCHE[3] = "BRC";

int IMPORTE_BRAZIL = 25000;
int IMPORTE_MAR_DEL_PLATA = 14000;
int IMPORTE_MENDOZA = 19000;
int IMPORTE_BARILOCHE = 23000;
int SEGURO_NINOS = 2000;
int RECARGO_TARJETA = 1.05;

int CAPACIDAD_MAXIMA = 60;

int COLUMNAS = 6;
int cant_pasajeros;



void escribirRenglon(){
    printf("-----------------------------------------------------------\n");
}





// PARTE SANTI

// ORDENA Y MUESTRA LISTA ORDENADA POR APELLIDO Y NOMBRE
void mostrar_lista_ordenada_por_apellido_nombre(char (*pasajeros)[COLUMNAS][50])
{
    int i, j, pos_menor;
    char aux[COLUMNAS][50];

    // COMPARA EL VALOR MENOR CON TODO LOS VALORES PARA DEFINIR CUAL ES EL MENOR
    for (i = 0; i < cant_pasajeros - 1; i++)
    {
        pos_menor = i;
        for (j = i + 1; j < cant_pasajeros; j++)
        {
            char menor[100], mayor[100];
            strcpy(menor, pasajeros[pos_menor][1]);
            strcat(menor, pasajeros[pos_menor][2]);
            strcpy(mayor, pasajeros[j][1]);
            strcat(mayor, pasajeros[j][2]);

            if (strcasecmp(menor, mayor) > 0)
            {
                pos_menor = j;
            }
        }

        // Intercambiar toda la fila de pasajeros[i] con pasajeros[pos_menor]
        for (j = 0; j < COLUMNAS; j++)
        {
            strcpy(aux[j], pasajeros[i][j]);
            strcpy(pasajeros[i][j], pasajeros[pos_menor][j]);
            strcpy(pasajeros[pos_menor][j], aux[j]);
        }
    }
    escribirRenglon();
    for (int i = 0; i < cant_pasajeros; i++)
    {
        printf("%s %s, DNI: %s, Edad: %s, Destino: %s, Importe: $%s\n",
               pasajeros[i][1], pasajeros[i][2], pasajeros[i][0], pasajeros[i][3], pasajeros[i][4], pasajeros[i][5]);
        escribirRenglon();
    }
}

// RECIBE UN ARRAY CON 4 VALORES Y DEVUELVE EL INDICE DEL MAYOR
int devolver_mayor(float (*arreglo)[4])
{
    int i;
    bool mayor_unico = true;
    int pos_mayor = 0;
    for (i = 0; i < 4; i++)
    {
        if (arreglo[pos_mayor][0] < arreglo[i][0])
        {
            pos_mayor = i;
            mayor_unico = true;
        }
        if (arreglo[pos_mayor][0] == arreglo[i][0])
        {
            mayor_unico = false;
        }
        
    }
    if (!mayor_unico)
    {
        pos_mayor = 4;
    }
    
    return pos_mayor;
}

// RECIBE EL ARRAY CON LAS ESTADISTICAS Y LO MUESTRA
void mostrar(float (*estadisticas)[4], char *mayor)
{
    escribirRenglon();
    printf("El %.2f%% eligio Brazil como destino, y el %.2f %% es menor de 5 anos\n",
           estadisticas[0][2], estadisticas[0][3]);
    escribirRenglon();
    printf("El %.2f%% eligio Mar del Plata como destino, y el %.2f %% es menor de 5 anos\n",
           estadisticas[1][2], estadisticas[1][3]);
    escribirRenglon();
    printf("El %.2f%% eligio Mendoza como destino, y el %.2f %% es menor de 5 anos\n",
           estadisticas[2][2], estadisticas[2][3]);
    escribirRenglon();
    printf("El %.2f%% eligio Bariloche como destino, y el %.2f %% es menor de 5 anos\n",
           estadisticas[3][2], estadisticas[3][3]);
    escribirRenglon();
    if (strcmp(mayor, "4") == 0)
    {
        printf("No hay un unico destino mas seleccionado\n");
    }
    else{
        printf("El destino mas seleccionado es %s\n", mayor);
    }
    escribirRenglon();
}

// CALCULA ESTADISTICAS DE LOS PASAJEROS
void mostrar_estadisticas(char (*pasajeros)[6][50])
{
    // ESTADISTICAS:
    // FILA 0:      BRA
    // FILA 1:      MDQ
    // FILA 2:      MZA
    // FILA 3:      BRC

    // COLUMNA 0:   CANTIDAD
    // COLUMNA 1:   CANT. MENORES
    // COLUMNA 2:   PORC. PERSONAS
    // COLUMNA 3:   POR. DE MENORES


    //        CANTIDAD      CANT. MENORES       PORC. PERSONAS       PORC. DE MENORES

    //BRA        0               0                    0                    0
 
    //MDQ        0               0                    0                    0

    //MZA        0               0                    0                    0

    //BRC        0               0                    0                    0

    float estadisticas[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    int i;
    int pos_mayor;
    char mayor[50];

    // CALCULO PERSONAS X DESTINO
    for (i = 0; i < cant_pasajeros; i++)
    {
        if (strcasecmp(pasajeros[i][4], "BRA") == 0)
        {
            estadisticas[0][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[0][1]++;
            }
        }
        if (strcasecmp(pasajeros[i][4], "MDQ") == 0)
        {

            estadisticas[1][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[1][1]++;
            }
        }
        if (strcasecmp(pasajeros[i][4], "MZA") == 0)
        {

            estadisticas[2][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[2][1]++;
            }
        }
        if (strcasecmp(pasajeros[i][4], "BRC") == 0)
        {

            estadisticas[3][0]++;
            if (atoi(pasajeros[i][3]) < 5)
            {
                estadisticas[3][1]++;
            }
        }
    }

    // OBTENGO EL INDICE DEL DESTINO CON MAS PERSONAS
    pos_mayor = devolver_mayor(estadisticas);
    switch (pos_mayor)
    {
    case 0:
        strcpy(mayor, "Brazil");
        break;
    case 1:
        strcpy(mayor, "Mar del Plata");
        break;
    case 2:
        strcpy(mayor, "Mendoza");
        break;
    case 3:
        strcpy(mayor, "Bariloche");
        break;
    case 4:
        strcpy(mayor, "4");
    }

    // CALCULO DE PORCENTAJE DE PASAJEROS Y PORCENTAJE DE MENORES
    for (i = 0; i < 4; i++)
    {

        estadisticas[i][2] = (estadisticas[i][0] / cant_pasajeros) * 100;
        if(estadisticas[i][0] > 0)
        {
            estadisticas[i][3] = (estadisticas[i][1] / estadisticas[i][0]) * 100;
        }
    }

    mostrar(estadisticas, mayor);
}








// PARTE EZEQUIEL

// Función para convertir una cadena a mayúsculas
void convertir_a_mayusculas(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

void mostrar_tabla_destinos()
{
    printf("\nTabla de Codigos e Importes de Viaje:\n");
    escribirRenglon();
    printf("Codigo\t| Destino\t\t| Importe\n");
    escribirRenglon();
    printf("BRA\t| %s\t\t| $%d\n", "BRAZIL", IMPORTE_BRAZIL);
    printf("MDQ\t| %s\t\t| $%d\n", "MAR DEL PLATA", IMPORTE_MAR_DEL_PLATA);
    printf("MZA\t| %s\t\t| $%d\n", "MENDOZA", IMPORTE_MENDOZA);
    printf("BRC\t| %s\t\t| $%d\n","BARILOCHE", IMPORTE_BARILOCHE);
    escribirRenglon();
}

void buscar_por_pasajero(char (*pasajeros)[6][50])
{
    int i = 0, indice_DNI;
    char dni[50];
    bool banderaDNI, encontrado;
    do
    {
        printf("Ingrese el DNI del pasajero que desea buscar\n");
        scanf("%s", dni);
        banderaDNI = Valida_DNI(dni);
    } while (banderaDNI == 1);
    do
    {
        if (strcmp(pasajeros[i][0], dni) == 0)
        {
            encontrado = true;
            indice_DNI = i;
        }
        else
        {
            encontrado = false;
        }
        i = i + 1;
    } while (!encontrado && i < cant_pasajeros);
    escribirRenglon();
    if (encontrado)
    {
        
        printf("Nombre y apellido: %s %s\nEdad: %s\nDestino: %s\nImporte:$%s\n",
               pasajeros[indice_DNI][2], pasajeros[indice_DNI][1], pasajeros[indice_DNI][3], pasajeros[indice_DNI][4], pasajeros[indice_DNI][5]);
        escribirRenglon();
    }

    if(!encontrado)
    {
        printf("Persona no encontrada");
        escribirRenglon();
    }
}







// PARTE FRANCO

int Valida_DNI(char *dni)
{
    int erroneo = 0;
    int longi = strlen(dni);
    int DNI = atoi(dni);
    for (int i = 0; i < longi; i++)
    {
        if (!isdigit(dni[i]))
        {
            erroneo = 1;
            
        }
    }
    if (!(DNI >= 5000000 && DNI <= 6999999) && !(DNI >= 10000000 && DNI <= 59999999))
    {
        erroneo = 1;
        
    }
    if (erroneo == 1)
    {
        escribirRenglon();
        printf("Formato de DNI erroneo, ingrese un DNI valido\n");
        escribirRenglon();
    }

    return erroneo;
}

void Mostrar_destinos(char (*pasajeros)[6][50], int cantPasaj)
{
    float sum_bra = 0;
    float sum_BRC = 0;
    float sum_MZA = 0;
    float sum_MDQ = 0;
    int cant_bra = 0;
    int cant_BRC = 0;
    int cant_MZA = 0;
    int cant_MDQ = 0;

    char endptr;
    float importeCopiado;





    for (int i = 0; i < cantPasaj; i++)
    {
        importeCopiado = strtof(pasajeros[i][5], endptr);
        printf("%s\n", pasajeros[i][5]);
        printf("%f", &importeCopiado);
        if (strcasecmp(pasajeros[i][4], "BRA") == 0)
        {
            sum_bra = sum_bra + importeCopiado;
            cant_bra++;
        }
        else if (strcasecmp(pasajeros[i][4], "BRC") == 0)
        {
            sum_BRC = sum_BRC + importeCopiado;
            cant_BRC++;
        }
        else if (strcasecmp(pasajeros[i][4], "MZA") == 0)
        {
            sum_MZA = sum_MZA + importeCopiado;
            cant_MZA++;
        }
        else if (strcasecmp(pasajeros[i][4], "MDQ") == 0)
        {
            sum_MDQ = sum_MDQ + importeCopiado;
            cant_MDQ++;
        }
    }
    mostrar_tabla_destinos();
    printf("Codigo de destino: BRA  |  Cantidad de pasajeros:%i   |   importe total:%.2f\n", cant_bra, sum_bra);
    escribirRenglon();
    printf("Codigo de destino: BRC  |  Cantidad de pasajeros:%i   |   importe total:%.2f\n", cant_BRC, sum_BRC);
    escribirRenglon();
    printf("Codigo de destino: MZA  |  Cantidad de pasajeros:%i   |   importe total:%.2f\n", cant_MZA, sum_MZA);
    escribirRenglon();
    printf("Codigo de destino: MDQ  |  Cantidad de pasajeros:%i   |   importe total:%.2f\n", cant_MDQ, sum_MDQ);
    escribirRenglon();
}






// PARTE JUAN

void cargar_pasajeros(char (*pasajeros)[6][50])
{
    int cuposBRA = 0, cuposMDQ = 0, cuposMZA = 0, cuposBRC = 0;
    int total_pasajeros;
    int banderaDNI;
    int formaPago;
    bool aprobado = true;
    float importe;
    escribirRenglon();
    for (int i = 0; i < cant_pasajeros; i++)
    {
        do
        {
            printf("Ingrese su DNI: ");
            scanf(" %s", pasajeros[i][0]);
            banderaDNI = Valida_DNI(pasajeros[i][0]);
        } while (banderaDNI == 1);

        printf("Ingrese su apellido: ");
        scanf(" %s", pasajeros[i][1]);

        printf("Ingrese su nombre: ");
        scanf(" %s", pasajeros[i][2]);

        printf("Ingrese su edad: ");
        scanf(" %s", pasajeros[i][3]);

        printf("Ingrese Codigo de Destino (BRA, MDQ, MZA, BRC): ");
        scanf(" %s", pasajeros[i][4]);

        while (strcmp(pasajeros[i][4], "BRA") != 0 && strcmp(pasajeros[i][4], "MDQ") != 0 && strcmp(pasajeros[i][4], "MZA") != 0 && strcmp(pasajeros[i][4], "BRC") != 0)
        {
            printf("Codigo erroneo, ingrese de nuevo(BRA, MDQ, MZA, BRC): ");
            scanf(" %s", pasajeros[i][4]);
        }

        if (strcmp(pasajeros[i][4], "BRA") == 0)
        {
            if (cuposBRA > 60)
            {
                printf("Capacidad maxima alcanzada para Brasil!");
                aprobado = false;
            }
            else
            {
                importe = IMPORTE_BRAZIL;
                cuposBRA++;
            }
        }
        else if ((strcmp(pasajeros[i][4], "MDQ") == 0))
        {
            if (cuposMDQ > 60)
            {
                printf("Capacidad maxima alcanzada para Mar del Plata!");
                aprobado = false;
            }
            else
            {
                importe = IMPORTE_MAR_DEL_PLATA;
                cuposMDQ++;
            }
        }
        else if ((strcmp(pasajeros[i][4], "MZA") == 0))
        {
            if (cuposMZA > 60)
            {
                printf("Capacidad maxima alcanzada para Mendoza!");
                aprobado = false;
            }
            else
            {
                importe = IMPORTE_MENDOZA;
                cuposMZA++;
            }
        }
        else if ((strcmp(pasajeros[i][4], "BRC") == 0))
        {
            if (cuposBRC > 60)
            {
                printf("Capacidad maxima alcanzada para Bariloche!");
                aprobado = false;
            }
            else
            {
                importe = IMPORTE_BARILOCHE;
                cuposBRC++;
            }
        }

        if (aprobado)
        {
            do
            {
                printf("Forma de pago:\n1 - Tarjeta de credito(5%% de recargo)\n2 - Efectivo\n");
                scanf("%d", &formaPago);
                if (formaPago<1 || formaPago>2)
                {
                    printf("ERROR, ingrese una de las opciones\n");
                }
            } while (formaPago<1 || formaPago>2);
           
            if (atoi(pasajeros[i][3]) < 5)
            {
                importe = importe + SEGURO_NINOS;
            }

            if (formaPago == 1)
            {

                importe = importe + (importe * 0.05);
            }

            sprintf(pasajeros[i][5], "%.2f", importe);
            printf("El importe que debe pagar es de: $%s\n", pasajeros[i][5]);
            escribirRenglon();
        }
        





        total_pasajeros++;
    }
}

void ordenar_por_destino(char (*pasajeros)[COLUMNAS][50])
{
    int pos_menor, i, j;
    char menor[200], mayor[200], aux[COLUMNAS][50];

    for (i = 0; i < cant_pasajeros - 1; i++)
    {
        pos_menor = i;

        for (j = i + 1; j < cant_pasajeros; j++)
        {
            strcpy(menor, pasajeros[pos_menor][4]); 
            strcat(menor, pasajeros[pos_menor][1]); 
            strcat(menor, pasajeros[pos_menor][2]); 

            strcpy(mayor, pasajeros[j][4]); 
            strcat(mayor, pasajeros[j][1]); 
            strcat(mayor, pasajeros[j][2]); 
            if (strcasecmp(menor, mayor) > 0)
            {
                pos_menor = j; 
            }
        }

        for (j = 0; j < COLUMNAS; j++)
        {
            strcpy(aux[j], pasajeros[i][j]);
            strcpy(pasajeros[i][j], pasajeros[pos_menor][j]);
            strcpy(pasajeros[pos_menor][j], aux[j]);
        }
    }
    escribirRenglon();
    for (i = 0; i < cant_pasajeros; i++)
    {
        printf("Codigo destino: %s, Apellido y nombre: %s %s, DNI: %s, Edad: %s, Importe: $%s\n",
               pasajeros[i][4], pasajeros[i][1], pasajeros[i][2], pasajeros[i][0], pasajeros[i][3], pasajeros[i][5]);
        escribirRenglon();
    }
}

int main()
{
    int opcion;
    printf("Ingrese la cantidad de pasajeros que va a ingresar\n");
    scanf("%d", &cant_pasajeros);

    char pasajeros[cant_pasajeros][6][50];
    cargar_pasajeros(pasajeros);
    // {
    //     {"45490269", "Perez", "Juan", "4", "MDQ", },
    //     {"87654321", "Gomez", "Ana", "3", "MDQ"},
    //     {"23456789", "Martinez", "Carlos", "2", "MZA"},
    //     {"98765432", "Lopez", "Maria", "1", "BRC"},
    //     {"34567890", "Garcia", "Lucia", "22", "BRA"},
    //     {"87654322", "Sanchez", "Miguel", "27", "MDQ"},
    //     {"45678901", "Fernandez", "Sofia", "32", "MZA"},
    //     {"98765431", "Rodriguez", "Luis", "40", "BRC"},
    //     {"56789012", "Gonzalez", "Laura", "26", "BRA"},
    //     {"87654320", "Hernandez", "Jorge", "29", "MDQ"},
    //     {"67890123", "Ramirez", "Elena", "33", "MZA"},
    //     {"98765430", "Torres", "Pablo", "31", "BRC"},
    //     {"78901234", "Ruiz", "Marta", "21", "BRA"},
    //     {"87654319", "Morales", "Diego", "34", "MDQ"},
    //     {"89012345", "Ortiz", "Camila", "24", "MZA"},
    //     {"98765429", "Silva", "Ricardo", "38", "BRC"},
    //     {"90123456", "Castro", "Natalia", "27", "BRA"},
    //     {"87654318", "Mendez", "Alejandro", "29", "MDQ"},
    //     {"01234567", "Vega", "Julia", "26", "MZA"},
    //     {"98765428", "Rojas", "Marcos", "36", "BRC"},
    //     {"12345679", "Reyes", "Sandra", "23", "BRA"},
    //     {"87654317", "Vargas", "Victor", "37", "MDQ"},
    //     {"23456780", "Medina", "Paula", "22", "MZA"},
    //     {"98765427", "Cruz", "Sergio", "35", "BRC"},
    //     {"34567891", "Pena", "Valeria", "30", "BRA"},
    //     {"87654316", "Herrera", "Adrian", "28", "MDQ"},
    //     {"45678912", "Molina", "Lorena", "34", "MZA"},
    //     {"98765426", "Campos", "Eduardo", "33", "BRC"},
    //     {"56789023", "Nunez", "Gabriela", "31", "BRA"},
    //     {"87654315", "Roman", "Nicolas", "25", "MDQ"}};

    do
    {
        printf("\nMenu de opciones:\n");
        printf("1. Mostrar lista de pasajeros ordenada por apellido y nombre\n");
        printf("2. Mostrar lista de pasajeros ordenada por Codigo Destino y Apellido - Nombre\n");
        printf("3. Mostrar lista de Destinos\n");
        printf("4. Buscar por pasajero\n");
        printf("5. Mostrar estadisticas\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            mostrar_lista_ordenada_por_apellido_nombre(pasajeros);
            break;
        case 2:
            ordenar_por_destino(pasajeros);
            break;
        case 3:
            Mostrar_destinos(pasajeros, cant_pasajeros);
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