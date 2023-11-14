#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR    "\x1b[0m"
#define CYAN_F     "\x1b[46m"
#define NEGRO_T        "\x1b[30m"
#define ROJO_F     "\x1b[41m"

#include "menuPrincipal.h"

void menuPrincipal()
{
    int opcion;

    inicio();

    printf("Ingresar una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    systemix();
    switch(opcion)
    {
        case 1:
            printf("Ha seleccionado la opcion 1.\n");
            break;
        case 2:
            printf("Ha seleccionado la opcion 2.\n");
            break;
        case 3:
            printf("Ha seleccionado la opcion 3.\n");
            break;
        default:
            printf("Opción no válida. Ingrese un número del 1 al 3.\n");
    }
}

void systemix()
{
    puts("");
    system("pause");
    system("cls");
}

void inicio()
{
    system("cls");
    printf("\n                                                      "CYAN_F NEGRO_T"HEMEROTECA\n\n"RESET_COLOR);
    puts("\n\n");
    printf("                                                    1. INICIAR SESION");
    printf("\n\n\n");
    printf("                                                    2. CREAR CUENTA");
    printf("\n\n\n");
    printf("                                                    3. SALIR");
    printf("\n\n\n                                                    ");
}
