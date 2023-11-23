#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "animaciones.h"
#include "arboles.h"
#include "archivos.h"
#include "Lista_De_Listas.h"
#include "menuAdministrador.h"
#include "menuPrincipal.h"
#include "menuUsuario.h"
#include "Pila_Con_Listas_PS.h"
#include "publicacionMusical.h"
#include "usuarios.h"

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

void menuPrincipal(char archivoUsuarios[], char archivoRegistros[], char archivoAutores[])
{
    char continuar = 's';
    char email[30], contra[12];
    char contraAdmin[12] = "admin";
    char contraAdminPrueba[12];
    int opcion, volver;

    nodoListaUsuario *listaUsuarios = inicListaUsuario();
    nodoListaUsuario *usuarioEncontrado = NULL;

    while (opcion != 3)
    {
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

            printf("Ingrese su e-mail: ");
            fflush(stdin);
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\r\n")] = '\0';

            listaUsuarios = archivo2ListaDeListasUsuarios(archivoUsuarios, archivoRegistros, listaUsuarios);
            usuarioEncontrado = buscarUsuarioXEmail(listaUsuarios, email);

            if (usuarioEncontrado != NULL)
            {
                for (int i = 0; i < 3; i++)
                {
                    printf("Ingrese su contrase%ca (%i intento de 3): ", 164, i + 1); // 164 = enie
                    fflush(stdin);
                    fgets(contra, sizeof(contra), stdin);
                    contra[strcspn(contra, "\r\n")] = '\0'; // Elimina caracteres adicionales generados al usar fgets.

                    if (strcmp(usuarioEncontrado->datosLogin.contrasenia, contra) == 0)
                    {
                        animacionCargando();
                        listaUsuarios = menuUsuario(usuarioEncontrado, listaUsuarios, archivoUsuarios, archivoRegistros, archivoAutores);
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
                        {
                            system("cls");
                        }
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
        case 4:
        {
            printf("Ingrese su e-mail: ");
            fflush(stdin);
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\r\n")] = '\0';

            listaUsuarios = archivo2ListaDeListasUsuarios(archivoUsuarios, archivoRegistros, listaUsuarios);
            usuarioEncontrado = buscarUsuarioXEmail(listaUsuarios, email); // admin@adm.com - admin

            if (usuarioEncontrado != NULL)
            {
                if (strcmp(usuarioEncontrado->datosLogin.contrasenia, contraAdmin) == 0)
                {
                    animacionCargando();
                    listaUsuarios = menuDeAdministradores(usuarioEncontrado, listaUsuarios, archivoUsuarios);
                }
                else
                {
                    printf("Error: este usuario no es un administrador. \n");
                }
            }
            else
            {
                system("cls");
                printf("Admin no registrado! \n");
                printf("Ingrese la contrase%ca del personal para registrarse como admin: ", 164);
                fflush(stdin);
                fgets(contraAdminPrueba, sizeof(contraAdminPrueba), stdin);
                contraAdminPrueba[strcspn(contraAdminPrueba, "\r\n")] = '\0';
                system("cls");

                if (strcmp(contraAdminPrueba, contraAdmin) != 0)
                {
                    printf("Error: contrase%ca incorrecta. Usted no es un admin. \n", 164);
                }
                else
                {
                    printf("Iniciando proceso de registro...\n");
                    Sleep(800);
                    system("cls");
                    cargarArchivoUsuariosAdmins(archivoUsuarios, contraAdmin);
                    listaUsuarios = archivo2ListaDeListasUsuarios(archivoUsuarios, archivoRegistros, listaUsuarios);
                    mostrarArchivoUsuarios(archivoUsuarios);
                    mostrarListaDeUsuarios(listaUsuarios);
                    system("pause");
                    registroExitoso();
                }
            }
            break;
        }
        default:
        {
            defaultCaseMenuPrincipal();
            break;
        }
        }
    }
}
