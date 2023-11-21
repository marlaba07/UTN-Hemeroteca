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
#include "Lista_De_Listas.h"

nodoListaUsuario *menuUsuario(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *lista)
{
    int opcion = 0;
    char seguir = 's';
    char archivoRegistros[20] = "Registros.bin";

    lista_de_listas *listaPrincipal = inicListaDelistas();

    while (seguir == 's')
    {
        system("cls");
        bienvenidaUsuario();
        opcionesMenuUsuario();

        printf("Seleccione una opcion del menu: ");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:
        {
            cargarArchivoPublicacion(archivoRegistros);                               // Cargo en el archivo
            listaPrincipal = archivo2ListaDeListas(archivoRegistros, listaPrincipal); // Pasaje del archivo a la lista
            printf("\nLa(s) publicacion(es) se ha(n) cargado correctamente! \n");
            break;
        }
        case 2:
        {
            int case2Opt = 0;
            char continuar = 's';
            char autorABuscar[20];

            printf("Seleccione el criterio de busqueda: \n");

            do
            {
                printf("1. Por titulo. \n");
                printf("2. Por autor. \n");
                printf("3. Por fecha. \n");
                printf("4. Por palabra clave. \n");
                printf("5. Salir.");
                printf("\n");
                fflush(stdin);
                scanf("%i", &case2Opt);
                system("cls");

                switch (case2Opt)
                {
                case 1:
                {
                    break;
                }
                case 2:
                {
                    printf("Ingrese el nombre del autor a buscar: ");
                    fflush(stdin);
                    fgets(autorABuscar, sizeof(autorABuscar), stdin);

                    mostrarPublicacionXAutor(archivoRegistros, autorABuscar);

                    break;
                }
                case 3:
                {
                    int anio1 = 9999;
                    int anio2 = 9999;

                    printf("Ingrese un rango de fechas (a%cos): \n", 164);
                    printf("Fecha limite inferior: ");

                    while (anio1 > 2023)
                    {
                        fflush(stdin);
                        scanf("%i", &anio1);

                        if (anio1 > 2023)
                        {
                            printf("Error: salvo que venga del futuro, el a%co que ha ingresado no es valido. \n", 164);
                        }
                    }

                    printf("Fecha limite superior: ");

                    while (anio2 > 2023)
                    {
                        fflush(stdin);
                        scanf("%i", &anio2);

                        if (anio2 > 2023)
                        {
                            printf("Error: salvo que venga del futuro, el a%co que ha ingresado no es valido. \n", 164);
                        }
                    }

                    mostrarPublicacionXFecha(archivoRegistros, anio1, anio2);

                    break;
                }
                case 4:
                {
                    break;
                }
                default:
                {
                    break;
                }
                }

                printf("Desea volver al menu anterior? (s/n): \n");
                fflush(stdin);
                scanf("%c", &continuar);
                system("cls");

            } while ((continuar == 's') || (continuar == 'S'));

            break;
        }
        case 3:
        {
            printf("" CYAN_F NEGRO_T "INFORMACION EN ARCHIVO DE PUBLICACIONES: " RESET_COLOR);
            mostrarArchivoPublicacion(archivoRegistros); // Muestro el archivo para corroborar si se cargo

            system("pause");
            system("cls");

            printf("" CYAN_F NEGRO_T "INFORMACION EN LISTA DE LISTAS: " RESET_COLOR);
            recorrerYmostrarListaDeListas(listaPrincipal); // Muestro la lista

            system("pause");
            system("cls");

            break;
        }
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
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
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        default:
            break;
        }

        printf("Desea continuar? (s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    return lista;
}
