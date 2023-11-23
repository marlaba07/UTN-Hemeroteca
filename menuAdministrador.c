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

nodoListaUsuario *menuDeAdministradores(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *listaUsers, char archivoUsuarios[])
{
    int opcion = 0;
    char archivoRegistros[20] = "Registros.bin";

    nodo_arbol *arbol = inic_arbol();
    lista_de_listas *listaPrincipal = inicListaDelistas();

    while (opcion != 6)
    {
        system("cls");
        // bienvenidaAdmin();
        opcionesMenuAdmin();

        printf("Ingresar una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:
        {
            arbol = archivo2Arbol(archivoUsuarios, arbol);
            printf("" CYAN_F NEGRO_T "INFORMACION EN ARBOL:\n\n" RESET_COLOR);
            inOrder(arbol);
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            mostrarArchivoPublicacion(archivoRegistros);
            recorrerYmostrarListaDeListas(listaPrincipal);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            int case3Opt = 0;
            char continuar = 's';
            char autorABorrar[20];
            char tituloABorrar[30];

            do
            {
                printf("Seleccione el criterio de busqueda: \n");
                printf("1. Por autor. \n");
                printf("2. Por titulo. \n");
                printf("\n");
                fflush(stdin);
                scanf("%i", &case3Opt);
                system("cls");

                switch (case3Opt)
                {
                case 1:
                {
                    printf("Ingrese el nombre del autor a borrar: ");
                    fflush(stdin);
                    fgets(autorABorrar, sizeof(autorABorrar), stdin);
                    autorABorrar[strcspn(autorABorrar, "\r\n")] = '\0';

                    int rta = borrarUnaPublicacionXAutor(archivoRegistros, autorABorrar);

                    if (rta == 1)
                    {
                        printf("Publicacion borrada exitosamente. \n");
                    }
                    else
                    {
                        printf("Autor no encontrado. \n");
                    }

                    break;
                }
                case 2:
                {
                    printf("Ingrese el titulo de la publicacion a borrar: ");
                    fflush(stdin);
                    fgets(tituloABorrar, sizeof(tituloABorrar), stdin);
                    tituloABorrar[strcspn(tituloABorrar, "\r\n")] = '\0';

                    int rta2 = borrarUnaPublicacionXTitulo(archivoRegistros, tituloABorrar);

                    if (rta2 == 1)
                    {
                        printf("Publicacion borrada exitosamente. \n");
                    }
                    else
                    {
                        printf("Titulo no encontrado. \n");
                    }

                    break;
                }
                }

                printf("Desea volver al menu de eliminacion de publicacion? (s/n): ");
                fflush(stdin);
                scanf("%c", &continuar);
                system("cls");

            } while ((continuar == 's') || (continuar == 'S'));

            break;
        }
        case 4:
        {

            break;
        }
        case 5:
        {
            char tituloBuscar[50];

            printf("Ingrese el titulo de la publicacion a actualizar: ");
            fflush(stdin);
            fgets(tituloBuscar, sizeof(tituloBuscar), stdin);
            tituloBuscar[strcspn(tituloBuscar, "\r\n")] = '\0';

            int posicion = buscarRegistro(archivoRegistros, tituloBuscar); // Busca el registro en el archivo

            if (posicion != -1)
            {
                actualizarInformacionPublicacion(archivoRegistros, posicion);
                listaPrincipal = archivo2ListaDeListas(archivoRegistros, listaPrincipal);
                system("pause");
                system("cls");
            }
            else
            {
                printf("Publicacion no encontrada.\n");
                system("pause");
                system("cls");
            }

            break;
        }
        case 6:
        {
            animacionSaliendo();
            break;
        }
        default:
        {
            defaultCaseMenuAdmin();
            break;
        }
        }
    }
}
