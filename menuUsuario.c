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
#include "Lista_De_Listas.h"

nodoListaUsuario* menuUsuario(nodoListaUsuario* usuarioEncontrado, nodoListaUsuario* lista)
{
    int opcion;
    char seguir = 's';

    lista_de_listas *listaPrincipal = inicListaDelistas();

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
            cargarArchivoPublicacion("Registros.bin");  // Cargo en el archivo
            listaPrincipal = archivo2ListaDeListas("Registros.bin", listaPrincipal);  // Pasaje del archivo a la lista
            printf("\nLa publicacion se cargo correctamente! \n");
            break;
        case 2:
            break;
        case 3:
            mostrarArchivoPublicacion("Registros.bin"); // Muestro el archivo para corroborar si se cargo
            recorrerYmostrarListaDeListas(listaPrincipal);  // Muestro la lista
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
            actualizarInformacionPublicacion("Registros.bin");
            listaPrincipal = archivo2ListaDeListas("Registros.bin", listaPrincipal);
            system("pause");
            system("cls");
            printf("Lista modificada: \n");
            recorrerYmostrarListaDeListas(listaPrincipal);
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
        default:
            break;
        }

        printf("Desea continuar? (s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    return lista;
}
