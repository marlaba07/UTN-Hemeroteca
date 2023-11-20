#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

#include "animaciones.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"
#include "Lista_De_Listas.h"
#include "arboles.h"
#include "menuPrincipal.h"

int main()
{
    // Constantes para los archivos
    char archivoUsuarios[20] = "Usuarios.bin";
    char archivoRegistros[20] = "Registros.bin";

    /*
    lista_de_listas *listaPrincipal = inicListaDelistas();

    // cargarArchivoUsuarios(archivoUsuarios);
    printf("" CYAN_F NEGRO_T "INFORMACION EN ARCHIVO DE USUARIOS: " RESET_COLOR);
    mostrarArchivoUsuarios(archivoUsuarios);
    system("pause");

    system("cls");

    // cargarArchivoPublicacion(archivoRegistros);
    printf("" CYAN_F NEGRO_T "INFORMACION EN ARCHIVO DE PUBLICACIONES: " RESET_COLOR);
    mostrarArchivoPublicacion(archivoRegistros);
    system("pause");

    system("cls");

    listaPrincipal = archivo2ListaDeListas(archivoRegistros, listaPrincipal);
    printf("" CYAN_F NEGRO_T "INFORMACION EN LISTA DE LISTAS: " RESET_COLOR);
    recorrerYmostrarListaDeListas(listaPrincipal);
    system("pause");

    system("cls");

    nodo_arbol *arbol = inic_arbol();
    arbol = archivo2Arbol(archivoUsuarios, arbol);
    printf("" CYAN_F NEGRO_T "INFORMACION EN ARBOL:\n\n" RESET_COLOR);
    inOrder(arbol);
    system("pause");

    system("cls");
    */

    animacionCargando();
    menuPrincipal(archivoUsuarios);

    return 0;
}
