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

nodoListaUsuario* menuDeAdministradores(nodoListaUsuario* usuarioEncontrado, nodoListaUsuario* listaUsers)
{
    int opcion = 0;
    char seguir = 's';
    nodo_arbol *arbol = inic_arbol();

    while(seguir == 's')
    {
        bienvenidaAdmin();

        printf("\n1. Ver todos los usuarios registrados ");
        printf("\n2. Ver todas las publicaciones ");
        printf("\n3. Eliminar publicacion de usuario "); // Eliminar publicaciones: Permite al usuario eliminar una publicación de la hemeroteca. [Opcional, ver que onda]
        printf("\n4. Generar informes y estadisticas "); // Generar informes: Genera informes y estadísticas sobre la hemeroteca musical, como las publicaciones más leídas, autores más destacados, etc.
        printf("\n5. Generar recomendaciones "); // Recomendaciones personalizadas: Basado en las preferencias y el historial de lectura de un usuario, el sistema puede proporcionar recomendaciones personalizadas de publicaciones musicales que podrían ser de su interés.
        printf("\n6. Actualizar informacion ");
        printf("\n7. salir\n");

        printf("\n\nIngresar una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");
        switch(opcion)
        {
        case 1:
            arbol = archivo2Arbol("Usuarios.bin", arbol);
            printf("" CYAN_F NEGRO_T "INFORMACION EN ARBOL:\n\n" RESET_COLOR);
            inOrder(arbol);
            break;
        case 2:
            mostrarArchivoPublicacion("Registros.bin");
            recorrerYmostrarListaDeListas(listaPrincipal);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            actualizarInformacionPublicacion("Registros.bin");
            listaPrincipal = archivo2ListaDeListas("Registros.bin", listaPrincipal);
            break;
        case 7:
            defaultCase();
            break;
        default:
            printf("Opcion incorrecta. ");
        }

        printf("Desea continuar? (s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);
    }
}





