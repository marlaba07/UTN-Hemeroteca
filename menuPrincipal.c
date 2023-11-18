#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

#include "menuPrincipal.h"
#include "usuarios.h"

void menuPrincipal(char archivoUsuarios[])
{
    int opcion;
    nodoListaUsuario *listaUsuarios = inicListaUsuario();
    inicio();

    printf("Ingresar una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");

    switch (opcion)
    {
    case 1:
        // Si el usuario ingresa la opci�n 1, ingresa.
        // Ac� habr�a que hacer las funciones para buscar en la lista de usuarios si existe, sino existe, que aparezca un error. Si existe que ingrese.
        printf("Ha seleccionado la opcion 1.\n");
        break;
    case 2:
        // Si el usuario ingresa la opci�n 2, crea su cuenta.
        printf(" ---- REGISTRO ---- \n\n");
        cargarArchivoUsuarios(archivoUsuarios);                        // El usuario los carga en el archivo
        mostrarArchivoUsuarios(archivoUsuarios);                       // (Mostramos para verificar que se cargan) - Testeo
        listaUsuarios = cargarUsuario(archivoUsuarios, listaUsuarios); // Y del archivo que crea, los pasa a la lista de usuarios
        registroExitoso();
        main();
        break;
    case 3:
        // Si el usuario ingresa la opci�n 3, sale del programa.
        despedida();
        break;
    case 99:
        // Podr�a ser una opcion secreta que no aparezca en el sistema, para que el admin se logee y haga la funcionalidad de admin.
        // [Chequear con el grupo]
    default:
        defaulT();
    }
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

void defaulT()
{
    system("cls");
    printf("\n\n                                     Opcion no valida. Ingrese un numero del 1 al 3. \n");
    despedida();
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
    printf("                                     |     4. FUNCIONES DE ADMINISTRADOR     |\n");
    printf("                                     |_______________________________________| ");
}

void despedida()
{
    printf("\n\n\n                                                  " ROJO_F "VUELVA PRONTO!\n\n" RESET_COLOR);
    printf("                                            " ROJO_F "PRESIONE UNA TECLA PARA SALIR\n\n" RESET_COLOR);

    system("pause");
}
