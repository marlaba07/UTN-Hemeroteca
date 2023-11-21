#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#include "arboles.h"
#include "Lista_De_Listas.h"

nodoListaUsuario *menuDeAdministradores(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *listaUsers)
{
    int opcion = 0;
    char archivoUsuarios[20] = "Usuarios.bin";
    char archivoRegistros[20] = "Registros.bin";

    nodo_arbol *arbol = inic_arbol();
    lista_de_listas *listaPrincipal = inicListaDelistas();

    while (opcion != 7)
    {
        bienvenidaAdmin();
        system("cls");

        printf("1. Ver todos los usuarios registrados. \n");
        printf("2. Ver todas las publicaciones. \n");
        printf("3. Eliminar publicacion de usuario. \n");             // Eliminar publicaciones: Permite al usuario eliminar una publicaci�n de la hemeroteca. [Opcional, ver que onda]
        printf("4. Generar informes y estadisticas. \n");             // Generar informes: Genera informes y estad�sticas sobre la hemeroteca musical, como las publicaciones m�s le�das, autores m�s destacados, etc.
        printf("5. Generar recomendaciones. \n");                     // Recomendaciones personalizadas: Basado en las preferencias y el historial de lectura de un usuario, el sistema puede proporcionar recomendaciones personalizadas de publicaciones musicales que podr�an ser de su inter�s.
        printf("6. Proporcionar recomendaciones personalizadas. \n"); // Recomendaciones personalizadas: Basado en las preferencias y el historial de lectura de un usuario, el sistema puede proporcionar recomendaciones personalizadas de publicaciones musicales que podr�an ser de su inter�s.
        printf("7. Salir. \n");

        printf("Ingresar una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        system("cls");

        do
        {
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

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
            {
                char tituloBuscar[50];

                printf("Ingrese el titulo de la publicacion a actualizar: ");
                fflush(stdin);
                fgets(tituloBuscar, sizeof(tituloBuscar), stdin);

                int posicion = buscarRegistro(archivoRegistros, tituloBuscar); // Busca el registro en el archivo

                if (posicion != -1)
                {
                    actualizarInformacionPublicacion(archivoRegistros, posicion);
                    listaPrincipal = archivo2ListaDeListas(archivoRegistros, listaPrincipal);
                }
                else
                {
                    printf("Publicacion no encontrada.\n");
                }

                break;
            }
            case 7:
            {
                defaultCase();
                break;
            }
            default:
            {
                printf("Opcion incorrecta. ");
                break;
            }
            }
        } while (opcion < 1 && opcion > 6);
    }
}
