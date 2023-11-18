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

/*
nodoListaUsuario* menuDeAdministradores(nodoListaUsuario* usuarioEncontrado, nodoListaUsuario* listaUsers, char archivoUsuarios[])
{
    int opcion = 0;

    while(opcion!=7)
    {
        system("cls");
        printf("\n1. listados");
        printf("\n2. alta");
        printf("\n3. baja");
        printf("\n4. modificacion");
        printf("\n5. consulta");
        printf("\n6. listado peliculas");
        printf("\n7. salir\n");

        scanf("%i",&opcion);

        do
        {
            switch(opcion)
            {
            case 1:
                ;
                system("cls");
                printf("listados\n");
                Sleep(1000);
                listados(archivoUsers);
                break;
            case 2:
                ;
                system("cls");
                printf("alta\n");
                Sleep(1000);
                listaUsers = altaUsuarioAdmin(listaUsers,archivoUsers);
                break;
            case 3:
                ;
                system("cls");
                printf("baja\n");
                Sleep(1000);
                listaUsers = bajaUsuarioAdmin(listaUsers,archivoUsers);
                break;
            case 4:
                ;
                system("cls");
                printf("modificacion\n");
                Sleep(1000);
                listaUsers = modificarPerfilAdmin(listaUsers,archivoUsers);
                break;
            case 5:
                ;
                system("cls");
                printf("consulta\n");
                Sleep(1000);
                consulta(listaUsers,archivoUsers);
                break;
            case 6:
                ;
                system("cls");
                menuPelisAdmin(archivo);
                break;
            }
        }
        while(opcion <1 && opcion > 6);
    }
}
*/




