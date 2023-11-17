#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR    "\x1b[0m"
#define CYAN_F     "\x1b[46m"
#define NEGRO_T        "\x1b[30m"
#define ROJO_F     "\x1b[41m"

#include "menuPrincipal.h"
#include "usuarios.h"

void menuPrincipal(char archivoUsuarios[])
{
    int opcion;
    nodoListaUsuario* listaUsuarios = inicListaUsuario();
    inicio();

    printf("Ingresar una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");

    switch(opcion)
    {
        case 1:
            // Si el usuario ingresa la opción 1, ingresa.
            // Acá habría que hacer las funciones para buscar en la lista de usuarios si existe, sino existe, que aparezca un error. Si existe que ingrese.
            printf("Ha seleccionado la opcion 1.\n");
            break;
        case 2:
            // Si el usuario ingresa la opción 2, crea su cuenta.
            printf(" ---- REGISTRO ---- \n\n");
            cargarArchivoUsuarios(archivoUsuarios); // El usuario los carga en el archivo
            mostrarArchivoUsuarios(archivoUsuarios);   // (Mostramos para verificar que se cargan) - Testeo
            listaUsuarios = cargarUsuario(archivoUsuarios, listaUsuarios);  // Y del archivo que crea, los pasa a la lista de usuarios
            break;
        case 3:
            // Si el usuario ingresa la opción 3, sale del programa.
            despedida();
            break;
        default:
            defaulT();
    }
}

void defaulT()
{
    system("cls");
    printf("\n\n                                     Opcion no valida. Ingrese un numero del 1 al 3. \n");
    despedida();
}

void inicio()
{
    system("cls");
    printf("\n                                                 "CYAN_F NEGRO_T"BIENVENIDO/A A LA HEMEROTECA\n\n"RESET_COLOR);
    puts("\n\n");
    printf("                                                    1. INICIAR SESION");
    printf("\n\n\n");
    printf("                                                    2. CREAR CUENTA");
    printf("\n\n\n");
    printf("                                                    3. SALIR");
    printf("\n\n\n                                                    ");
}

void despedida()
{
    printf("\n\n\n                                                  "ROJO_F"VUELVA PRONTO!\n\n"RESET_COLOR);
    printf("                                            "ROJO_F"PRESIONE UNA TECLA PARA SALIR\n\n"RESET_COLOR);
    printf("\n\n\n                                                    ");
}
