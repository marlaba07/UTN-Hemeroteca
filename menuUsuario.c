#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"

nodoListaUsuario* menuUsuario(nodoListaUsuario* usuarioEncontrado, nodoListaUsuario* lista, char archivoPublicacion[])
{
    int opcion;
    nodoHistorial* historial = inicListaHistorial();

    char seguir = 's';

    while(seguir == 's')
    {
        system("cls");
        bienvenidaUsuario();
        opcionesMenuUsuario();

        printf("Seleccione una opcion del menu: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion)
        {
        case 1:
            cargarArchivoPublicacion(archivoPublicacion);

            break;
        case 2:
            break;
        case 3:
            mostrarArchivoPublicacion(archivoPublicacion);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
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
        case 16:
            break;
        case 17:
            break;
        case 18:
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
