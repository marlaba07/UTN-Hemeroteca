#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"

void defaultCase()
{
    system("cls");
    printf("\n\n                                     Opcion no valida. Ingrese un numero del 1 al 3. \n");
    despedida();
}

void inicio()
{
    system("cls");
    printf("\n                                                 " CYAN_F NEGRO_T "BIENVENIDO/A A LA HEMEROTECA\n\n" RESET_COLOR);
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
    printf("\n\n\n                                                  " ROJO_F "VUELVA PRONTO!\n\n" RESET_COLOR);
    printf("                                            " ROJO_F "PRESIONE UNA TECLA PARA SALIR\n\n" RESET_COLOR);
    printf("\n\n\n                                                    ");
    inicio();
}

void menuPrincipal(char archivoUsuarios[], char archivoRegistros[])
{
    char continuar = 's';
    char email[30], contra[30];
    char contraseniaAdmin[] = "admin";
    int opcion, volver;

    nodoListaUsuario *listaUsuarios = inicListaUsuario();
    nodoListaUsuario *usuarioEncontrado = NULL;

    inicio();

    printf("Ingresar una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");

    switch (opcion)
    {
    case 1:
    {
        // Si el usuario ingresa la opcion 1, ingresa.
        printf(" ---- LOGIN ---- \n\n");

        printf("\nIngrese su e-mail: ");
        fflush(stdin);
        fgets(email, sizeof(email), stdin);

        listaUsuarios = archivo2ListaDeListasUsuarios(archivoUsuarios, archivoRegistros, listaUsuarios);
        usuarioEncontrado = buscarUsuarioPorEmail(listaUsuarios, email);

        if (usuarioEncontrado != NULL)
        {
            for (int i = 0; i < 3; i++)
            {
                printf("\nIngrese su contrase%ca\n%i intento de 3\n", 164, i + 1); // 164 = �
                fflush(stdin);
                fgets(contra, sizeof(contra), stdin);

                if (strcmp(usuarioEncontrado->datosLogin.contrasenia, contra) == 0)
                {
                    animacionCargando();
                    listaUsuarios = menuUsuario(usuarioEncontrado, listaUsuarios);
                    i = 3;
                }
                else
                {
                    if (i != 2)
                    {
                        system("cls");
                        printf("Constrase%ca incorrecta, ingrese 1 para ingresar la constrase%ca nuevamente. \n", 164, 164);
                        scanf("%i", &volver);
                    }
                    else if (i == 2)
                    {
                        system("cls");
                        printf("Superaste el limites de intentos, seras redireccionado al menu principal... \n");
                        animacionCargando();
                    }
                    if (volver == 1)
                        system("cls");
                }
            }
        }
        else
        {
            errorRegistro();
        }
        break;
    }
    case 2:
    {
        // Si el usuario ingresa la opcion 2, crea su cuenta.
        printf(" ---- REGISTRO ---- \n\n");
        cargarArchivoUsuarios(archivoUsuarios);
        printf("" CYAN_F NEGRO_T "INFORMACION EN ARCHIVO DE USUARIOS: " RESET_COLOR);
        mostrarArchivoUsuarios(archivoUsuarios);

        system("pause");
        system("cls");

        listaUsuarios = archivo2ListaDeListasUsuarios(archivoUsuarios, archivoRegistros, listaUsuarios);
        printf("" CYAN_F NEGRO_T "INFORMACION EN LISTA DE USUARIOS: " RESET_COLOR);
        mostrarListaDeUsuarios(listaUsuarios);

        system("pause");
        system("cls");

        registroExitoso();
        main();
        break;
    }
    case 3:
    {
        // Si el usuario ingresa la opcion 3, sale del programa.
        despedida();
        break;
    }
    case 99:
    {
        printf("\nIngrese mail del administrador: ");
        fflush(stdin);
        fgets(email, sizeof(email), stdin);

        printf("\nIngrese constrase%ca del administrador: ", 164);
        fflush(stdin);
        fgets(email, sizeof(contraseniaAdmin), stdin);

        listaUsuarios = archivo2ListaDeListasUsuarios(archivoUsuarios, archivoRegistros, listaUsuarios);
        usuarioEncontrado = buscarUsuarioPorEmail(listaUsuarios, email); // admin@adm.com - admin

        if (usuarioEncontrado != NULL)
        {
            if (strcmp(usuarioEncontrado->datosLogin.contrasenia, contraseniaAdmin) == 0)
            {
                animacionCargando();
                // listaUsuarios = menuDeAdministradores(usuarioEncontrado, listaUsuarios, archivoUsuarios);
            }
        }
        else
        {
            system("cls");
            printf("\nAdmin no registrado! \n");
        }
        break;
    }
    default:
    {
        defaultCase();
        break;
    }
    }
}
