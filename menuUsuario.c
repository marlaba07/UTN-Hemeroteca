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

nodoListaUsuario *menuUsuario(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *listaUsuarios, char archivoUsuarios[], char archivoRegistros[], char archivoAutores[])
{
    int opcion = 0;

    lista_de_listas *listaPrincipal = inicListaDelistas();
    listaPrincipal = archivo2ListaDeListas(archivoRegistros, listaPrincipal); // El archivo ya va a estar cargado con publicaciones. Se traen del archivo esos datos 1 vez.

    while (opcion != 12)
    {
        system("cls");
        // bienvenidaUsuario();
        opcionesMenuUsuario();

        printf("Seleccione una opcion del menu: ");
        fflush(stdin);
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
            char tituloABuscar[30];
            char palabraClaveABuscar[20];

            do
            {
                printf("Seleccione el criterio de busqueda: \n");
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
                    printf("Ingrese el titulo de la publicacion a buscar: ");
                    fflush(stdin);
                    fgets(tituloABuscar, sizeof(tituloABuscar), stdin);
                    tituloABuscar[strcspn(tituloABuscar, "\r\n")] = '\0';

                    mostrarPublicacionXTitulo(listaPrincipal, tituloABuscar);

                    break;
                }
                case 2:
                {
                    printf("Ingrese el nombre del autor a buscar: ");
                    fflush(stdin);
                    fgets(autorABuscar, sizeof(autorABuscar), stdin);
                    autorABuscar[strcspn(autorABuscar, "\r\n")] = '\0';

                    mostrarPublicacionXAutor(listaPrincipal, autorABuscar);

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

                    mostrarPublicacionXFecha(listaPrincipal, anio1, anio2);

                    break;
                }
                case 4:
                {
                    printf("Ingrese la palabra clave a buscar: ");
                    fflush(stdin);
                    fgets(palabraClaveABuscar, sizeof(palabraClaveABuscar), stdin);
                    palabraClaveABuscar[strcspn(palabraClaveABuscar, "\r\n")] = '\0';

                    mostrarPublicacionXPalabraClave(listaPrincipal, palabraClaveABuscar);

                    break;
                }
                case 5:
                {
                    animacionSaliendo();
                    break;
                }
                default:
                {
                    break;
                }
                }

                printf("Desea volver al menu de busqueda de publicacion? (s/n): \n");
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

            break;
        }
        case 4:
        {
            printf("" CYAN_F NEGRO_T "INFORMACION EN LISTA DE LISTAS: " RESET_COLOR);
            recorrerYmostrarListaDeListas(listaPrincipal); // Muestro la lista

            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            char tituloAActualizar[30];

            printf("Ingrese el titulo de la publicacion a actualizar: ");
            fflush(stdin);
            fgets(tituloAActualizar, sizeof(tituloAActualizar), stdin);
            tituloAActualizar[strcspn(tituloAActualizar, "\r\n")] = '\0';

            int posicion = buscarRegistro(archivoRegistros, tituloAActualizar); // Busca el registro en el archivo

            if (posicion != -1)
            {
                actualizarInformacionPublicacion(archivoRegistros, posicion);
                listaPrincipal = archivo2ListaDeListas(archivoRegistros, listaPrincipal);
            }
            else
            {
                printf("Publicacion no encontrada.\n");
                Sleep(800);
                system("cls");
            }
            break;
        }
        case 6:
        {
            nuevoAutor(archivoAutores);
            break;
        }
        case 7:
        {
            int case7Opt = 0;
            char continuar = 's';
            char autorAMostrar[20];
            char nacionalidadAutorAMostrar[30];

            do
            {
                printf("Seleccione el criterio de busqueda: ");
                printf("1. Por nombre. \n");
                printf("2. Por nacionalidad. \n");
                printf("3. Salir. \n");
                printf("\n");
                fflush(stdin);
                scanf("%i", &case7Opt);
                system("cls");

                switch (case7Opt)
                {
                case 1:
                {
                    printf("Ingrese el nombre del autor a mostrar: ");
                    fflush(stdin);
                    fgets(autorAMostrar, sizeof(autorAMostrar), stdin);
                    autorAMostrar[strcspn(autorAMostrar, "\r\n")] = '\0';

                    mostrarDatosAutorXNombre(archivoRegistros, autorAMostrar);

                    break;
                }
                case 2:
                {
                    printf("Ingrese la nacionalidad del autor a mostrar: ");
                    fflush(stdin);
                    fgets(nacionalidadAutorAMostrar, sizeof(nacionalidadAutorAMostrar), stdin);
                    nacionalidadAutorAMostrar[strcspn(nacionalidadAutorAMostrar, "\r\n")] = '\0';

                    mostrarDatosAutorXNacionalidad(archivoRegistros, nacionalidadAutorAMostrar);

                    break;
                }
                case 3:
                {
                    animacionSaliendo();
                    break;
                }
                default:
                {
                    break;
                }
                }

                printf("Desea volver al menu de busqueda de autor? (s/n): \n");
                fflush(stdin);
                scanf("%c", &continuar);
                printf("cls");

            } while ((continuar == 's') || (continuar == 'S'));

            break;
        }
        case 8:
        {
            char tituloAComentar[20];

            printf("Ingrese el titulo de la publicacion que desea comentar: ");
            fflush(stdin);
            fgets(tituloAComentar, sizeof(tituloAComentar), stdin);
            tituloAComentar[strcspn(tituloAComentar, "\r\n")] = '\0';

            buscarParaComentar(archivoRegistros, tituloAComentar);

            break;
        }
        case 9:
        {
            Pila pila;
            inicializarPila(&pila);

            mostrarPublicacionesPopulares(listaPrincipal, &pila);
            system("pause");
            system("cls");

            break;
        }
        case 10:
        {
            datosCadaPublicacion pubEnc;
            char emailUsuarioReserva[30];
            char publicacionAReservar[30];
            char genPublicacionAReservar[30];

            printf("Ingrese el genero y el titulo de la publicacion a reservar: \n");
            printf("Genero:");
            fflush(stdin);
            fgets(genPublicacionAReservar, sizeof(genPublicacionAReservar), stdin);
            genPublicacionAReservar[strcspn(genPublicacionAReservar, "\r\n")] = '\0';

            printf("Titulo:");
            fflush(stdin);
            fgets(publicacionAReservar, sizeof(publicacionAReservar), stdin);
            publicacionAReservar[strcspn(publicacionAReservar, "\r\n")] = '\0';

            int rta = reservarPublicacion(listaPrincipal, publicacionAReservar, genPublicacionAReservar, &pubEnc);

            if ((rta == 1) && (pubEnc.prestado == 0))
            {
                printf("Publicacion encontrada. ");
                Sleep(800);
                system("cls");
                printf("Ingrese su e-mail para validar la reserva: ");
                fflush(stdin);
                fgets(emailUsuarioReserva, sizeof(emailUsuarioReserva), stdin);
                emailUsuarioReserva[strcspn(emailUsuarioReserva, "\r\n")] = '\0';

                listaUsuarios = agregarPublicacionAHistorial(&listaPrincipal, listaUsuarios, emailUsuarioReserva, &pubEnc);
                mostrarListaDeUsuarios(listaUsuarios);
                system("pause");
                system("cls");
                recorrerYmostrarListaDeListas(listaPrincipal);
                system("pause");
                system("cls");
            }
            else if (rta == 0)
            {
                printf("Publicacion no encontrada. \n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Esta publicacion ya se encuentra reservada por otro usuario. \n");
                system("pause");
                system("cls");
            }

            break;
        }
        case 11:
        {
            obtenerRecomendaciones(listaPrincipal, usuarioEncontrado->datosLogin.generoPreferido);
            break;
        }
        case 12:
        {
            animacionSaliendo();
            break;
        }
        default:
        {
            defaultCaseMenuUsuario();
            break;
        }
        }
    }
    return listaUsuarios;
}