#include "menuPrincipal.h"
#include "usuarios.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

void menuPrincipal(char archivoUsuarios[])
{
    int opcion = 0;
    char continuar = 's';
    nodoListaUsuario *listaUsuarios = inicListaUsuario();

    do
    {
        inicio();
        printf("                                                      __________ \n");
        printf("                                                     |          |\n");
        printf("                                                     | OPCION:  |\n");
        printf("                                                     |__________|");
        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:
        {
            // Si el usuario ingresa la opci�n 1, ingresa.
            // Ac� habr�a que hacer las funciones para buscar en la lista de usuarios si existe, sino existe, que aparezca un error. Si existe que ingrese.
            printf("Ha seleccionado la opcion 1.\n");
            break;
        }
        case 2:
        {
            // Si el usuario ingresa la opci�n 2, crea su cuenta.
            printf(" ---- REGISTRO ---- \n\n");
            cargarArchivoUsuarios(archivoUsuarios);                        // El usuario los carga en el archivo
            mostrarArchivoUsuarios(archivoUsuarios);                       // (Mostramos para verificar que se cargan) - Testeo
            listaUsuarios = cargarUsuario(archivoUsuarios, listaUsuarios); // Y del archivo que crea, los pasa a la lista de usuarios
            registroExitoso();
            main();
            break;
        }
        case 3:
        {
            despedida();
            main();
            break;
        }
        default:
        {
            defaultCase();
            break;
        }
        }

        printf("Desea volver al menu principal?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);

    } while ((continuar == 's') || (continuar == 'S'));
}

int logo()
{
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                       :;+;;;;;;:                                                                                   ");
    printf("                   .+++++++;++++++;:                                                                                ");
    printf("                  ++++++++++++++++;;;;          .;;;;.                                                              ");
    printf("                 ++++++++++++++++++;;;;;+:.;;;;;;;;;;;;;:                                                           ");
    printf("                +++++++++++xxx++++;;;++;;;;;;;;;;;;;;;;;;;                                                          ");
    printf("              .+++++++++++&&&++++++;+++;;;;;;++;;;;;;;;;++                                                          ");
    printf("              ;+++++++++++&&&+++++++++;;++xxxxxx+;;;;;++++:     H E M E R O T E C A                                 ");
    printf("              xx++++++++++;x$+++++++++;+xXX$&&&XXx++++++++:     M U S I C A L               . .;.;;                 ");
    printf("              x+++++++++++;X$++++++++++xXX&&&&&&$XX+;xx;x++x;x+x+xxx+xxxxxxxxx+XX;X$X$$Xx&&:. .  .:&&;              ");
    printf("              x+++++++++++;x$+++++++;;+Xx&&&&&&&&&&Xx&$x&XX$+$X$X&$$x$$$&$&$$&x&$+$&$&&$x&&&&&&&&&&&&&              ");
    printf("              x+++++++++++;X$++++++++++xX+X$$&&&&$$xx$$x$XX$+$X&X&$$x$X$$X$XXX+XX+xxxxx+;&&:. :  :+&&.              ");
    printf("              xx++++++++++$&&+++++++++++xXxXX$XXXx++++x+++:                                .. .. :.                 ");
    printf("              ++++++++++++&&&++++++++++++++xXXx+++++++++++:                                                         ");
    printf("              :+++++++++++&&&+++++++++++++++++++++++++++++                                                          ");
    printf("               ++++++++++++++++++++++++++++++++++++++++++                                                           ");
    printf("                +++++++++++++++++++++++;...;+++++++++++.                                                            ");
    printf("                 ++++++++++++++++++++           ..:.                                                                ");
    printf("                  .+++xxxxxxxxxx++.                                                                                 ");
    printf("                     .;++++++;:                                                                                     ");
    printf("\n\n");
}

void defaultCase()
{
    system("cls");
    printf("\n\n                                     Error: opcion no valida. Ingrese un numero del 1 al 3. \n");
}

void inicio()
{
    system("cls");
    printf("                                      _______________________________________ \n");
    printf("                                     |                                       |\n");
    printf("                                     |              BIENVENIDO               |\n");
    printf("                                     |---------------------------------------|\n");
    printf("                                     |      Elija una de las opciones:       |\n");
    printf("                                     |---------------------------------------|\n");
    printf("                                     |            1. INICIAR SESION          |\n");
    printf("                                     |            2. REGISTRARSE             |\n");
    printf("                                     |            3. SALIR                   |\n");
    printf("                                     |      4. FUNCIONES DE ADMINISTRADOR    |\n");
    printf("                                     |_______________________________________|\n");
}

void despedida()
{
    printf("\n\n\n                                                  " ROJO_F "GRACIAS POR UTILIZAR NUESTRO SEFVICIO!\n\n" RESET_COLOR);
    printf("                                                              " ROJO_F "VUELVA PRONTO!\n\n" RESET_COLOR);

    system("pause");
}
