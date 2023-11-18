#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR    "\x1b[0m"
#define CYAN_F     "\x1b[46m"
#define NEGRO_T        "\x1b[30m"
#define ROJO_F     "\x1b[41m"

#include "menuPrincipal.h"
#include "usuarios.h"
#include "menuUsuario.h"

void menuPrincipal(char archivoUsuarios[])
{
    char email[30], contra[30];
    int opcion, volver;
    nodoListaUsuario* listaUsuarios = inicListaUsuario();
    nodoListaUsuario* usuarioEncontrado = NULL;

    inicio();

    printf("Ingresar una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");

    switch(opcion)
    {
    case 1:
        // Si el usuario ingresa la opción 1, ingresa.
        printf(" ---- LOGIN ---- \n\n");
        printf("\nIngrese su mail: ");
        fflush(stdin);
        gets(email);

        listaUsuarios = cargarUsuario(archivoUsuarios, listaUsuarios);
        usuarioEncontrado = buscarUsuarioPorEmail(listaUsuarios, email);
        if(usuarioEncontrado != NULL)
        {
            for( int i=0; i<3; i++ )
            {
                printf("\nIngrese su contrase%ca\n%i intento de 3\n", 164, i+1); // 164 = ñ
                fflush(stdin);
                gets(contra);

                if( strcmpi(usuarioEncontrado->datosLogin.contrasenia, contra) == 0 )
                {
                    animacionCargando();
                    listaUsuarios = menuUsuario(usuarioEncontrado, listaUsuarios, archivoUsuarios);
                    i = 3;
                }
                else
                {
                    if(i != 2)
                    {
                        system("cls");
                        printf("Constrase%ca incorrecta, ingrese 1 para ingresar la constrase%ca nuevamente. \n", 164, 164);
                        scanf("%i", &volver);
                    }
                    else if(i == 2)
                    {
                        system("cls");
                        printf("Superaste el limites de intentos, seras redireccionado al menu principal... \n");
                        animacionCargando();
                    }
                    if(volver == 1)
                        system("cls");
                }
            }
        }
        else
            errorRegistro();

        break;
    case 2:
        // Si el usuario ingresa la opción 2, crea su cuenta.
        printf(" ---- REGISTRO ---- \n\n");
        cargarArchivoUsuarios(archivoUsuarios);
        listaUsuarios = cargarUsuario(archivoUsuarios, listaUsuarios);
        registroExitoso();
        main();
        break;
    case 3:
        // Si el usuario ingresa la opción 3, sale del programa.
        despedida();
        break;
    case 99:
        // Podría ser una opcion secreta que no aparezca en el sistema, para que el admin se logee y haga la funcionalidad de admin.
        printf("Login ADM");
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
