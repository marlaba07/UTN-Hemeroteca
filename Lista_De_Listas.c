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

/// --- LISTA DE PUBLICACIONES --- ///
nodo_sublista_simple *inicSubLista()
{
    return NULL;
}

lista_de_listas *inicListaDelistas()
{
    return NULL;
}

// Funciones de inicializacion
nodo_sublista_simple *crearNodoSublista(datosCadaPublicacion data)
{
    nodo_sublista_simple *nuevoNodo = (nodo_sublista_simple *)malloc(sizeof(nodo_sublista_simple));

    if (nuevoNodo != NULL)
    {
        nuevoNodo->miRegistro = data;
        nuevoNodo->siguiente = NULL;
    }
    return nuevoNodo;
}

lista_de_listas *crearNodoListaPrincipal(char genero[])
{
    lista_de_listas *nuevoNodo = (lista_de_listas *)malloc(sizeof(lista_de_listas));

    if (nuevoNodo != NULL)
    {
        strcpy(nuevoNodo->genero, genero);
        nuevoNodo->listaDatosPublicaciones = NULL;
        nuevoNodo->siguiente = NULL;
    }
    return nuevoNodo;
}

nodo_sublista_simple *buscarYActualizarNodoTitulo(nodo_sublista_simple *listaDatosPublicaciones, char titulo[])
{
    nodo_sublista_simple *seg = listaDatosPublicaciones;

    int flag = 0;

    while ((seg != NULL) && (flag == 0))
    {
        if (strcmpi(seg->miRegistro.datosPublicacion.titulo, titulo) == 0)
        {
            seg->miRegistro.prestado = 1;
            seg->miRegistro.cantVecesLeida++;
            flag = 1;
        }
        seg = seg->siguiente;
    }
    return listaDatosPublicaciones;
}

nodo_sublista_simple *buscarNodoTitulo(nodo_sublista_simple *lista, char titulo[])
{
    nodo_sublista_simple *seg = lista;
    nodo_sublista_simple *tituloEncontrado = NULL;

    int flag = 0;

    while ((seg != NULL) && (flag == 0))
    {
        if (strcmp(seg->miRegistro.datosPublicacion.titulo, titulo) == 0)
        {
            tituloEncontrado = seg;
            flag = 1;
        }
        seg = seg->siguiente;
    }

    return tituloEncontrado; // No se encontro el genero
}

// Funcion para buscar un nodo por genero en la lista principal
lista_de_listas *buscarNodoGenero(lista_de_listas *lista, char genero[])
{
    lista_de_listas *seg = lista;
    lista_de_listas *genEncontrado = NULL;

    int flag = 0;

    while ((seg != NULL) && (flag == 0))
    {
        if (strcmp(seg->genero, genero) == 0)
        {
            genEncontrado = seg;
            flag = 1;
        }
        seg = seg->siguiente;
    }

    return genEncontrado; // No se encontro el genero
}

nodo_sublista_simple *agregarFinalDatosPublicacion(nodo_sublista_simple *sublista, nodo_sublista_simple *nuevaPublicacion)
{
    if (sublista == NULL)
    {
        sublista = nuevaPublicacion;
    }
    else
    {
        nodo_sublista_simple *seg = sublista;

        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }

        seg->siguiente = nuevaPublicacion;
    }

    return sublista;
}

// Funcion para agregar al principio de la lista general por genero
lista_de_listas *agregarPpioListaGeneral(lista_de_listas *lista, lista_de_listas *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

    return lista;
}

lista_de_listas *actualizarCantVecesLeidasYPrestamoDePublicacion(lista_de_listas *listaGeneros, char genero[], char titulo[])
{
    lista_de_listas *generoEncontrado = buscarNodoGenero(listaGeneros, genero);

    if (generoEncontrado != NULL)
    {
        generoEncontrado->listaDatosPublicaciones = buscarYActualizarNodoTitulo(generoEncontrado->listaDatosPublicaciones, titulo);
    }

    return listaGeneros;
}

lista_de_listas *alta(lista_de_listas *listaGeneros, nodo_sublista_simple *nuevaPublicacion)
{
    lista_de_listas *generoEncontrado = buscarNodoGenero(listaGeneros, nuevaPublicacion->miRegistro.datosPublicacion.genero);

    if (generoEncontrado == NULL)
    {
        lista_de_listas *aux = crearNodoListaPrincipal(nuevaPublicacion->miRegistro.datosPublicacion.genero);
        listaGeneros = agregarPpioListaGeneral(listaGeneros, aux);
        listaGeneros->listaDatosPublicaciones = agregarFinalDatosPublicacion(listaGeneros->listaDatosPublicaciones, nuevaPublicacion);
    }
    else
    {
        generoEncontrado->listaDatosPublicaciones = agregarFinalDatosPublicacion(generoEncontrado->listaDatosPublicaciones, nuevaPublicacion);
    }

    return listaGeneros;
}

lista_de_listas *archivo2ListaDeListas(char nombreArchivo[], lista_de_listas *lista)
{
    datosCadaPublicacion data;
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET); // Me ubico al inicio del archivo para su lectura.

        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo) != 0)
        {
            nodo_sublista_simple *aux = crearNodoSublista(data);
            lista = alta(lista, aux);
        }
        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }

    return lista;
}

// Funcion para mostrar los datos de una sola publicacion en la correspondiente sublista.
void imprimir(nodo_sublista_simple *lista, int i)
{
    printf("\n ------------------------------- \n");
    printf("   --- Publicacion Nro %i: ---\n\n", i);
    printf("- Titulo: %s\n", lista->miRegistro.datosPublicacion.titulo);
    printf("- Fecha de publicacion:  %02d/%02d/%04d\n\n", lista->miRegistro.datosPublicacion.dia, lista->miRegistro.datosPublicacion.mes, lista->miRegistro.datosPublicacion.anio);
    printf("- Descripcion: %s \n\n", lista->miRegistro.datosPublicacion.descripcion);
    printf("- Nombre completo del autor: %s\n", lista->miRegistro.datosAutor.nombreYapellido);
    printf("- Nacionalidad: %s \n", lista->miRegistro.datosAutor.nacionalidad);
    printf("- Biografia: %s \n\n", lista->miRegistro.datosAutor.biografia);
    printf("- Primer palabra clave: %s\n", lista->miRegistro.palabraClave1);
    printf("- Segunda palabra clave: %s\n", lista->miRegistro.palabraClave2);
    printf("- Prestado (1 = si | 0 = no): %d \n", lista->miRegistro.prestado);
    printf("- Fuente de informacion: %s \n", lista->miRegistro.fuente);
    printf("- Veces leidas: %d", lista->miRegistro.cantVecesLeida);
    printf("\n ------------------------------- \n");
}

// Funcion para recorrer y mostrar la lista de listas
void recorrerYmostrarListaDeListas(lista_de_listas *lista)
{
    lista_de_listas *seg = lista;

    while (seg != NULL)
    {
        int i = 0;
        printf("\n\nGENERO: %s", seg->genero);

        nodo_sublista_simple *segAux = seg->listaDatosPublicaciones;

        while (segAux != NULL)
        {
            imprimir(segAux, i + 1);
            segAux = segAux->siguiente;
            i++;
        }

        seg = seg->siguiente;
    }
}

/// --- LISTA DE USUARIOS --- ///

void generarInformesEstadisticas(lista_de_listas* lista)
{
    // Variables para almacenar las estadísticas
    int totalPublicaciones = 0;
    int totalVecesLeidas = 0;
    char autorMasDestacado[50] = "";
    int maxVecesLeidas = 0;

    // Recorrer la lista de listas
    lista_de_listas* seguidora = lista;
    while (seguidora != NULL)
    {
        // Recorrer la sublista de cada género
        nodo_sublista_simple *segPublicacion = seguidora->listaDatosPublicaciones;
        while (segPublicacion != NULL)
        {
            // Calcular estadísticas
            totalPublicaciones++;
            totalVecesLeidas += segPublicacion->miRegistro.cantVecesLeida;

            // Verifica si la publicación actual tiene más lecturas que el máximo registrado.
            if (segPublicacion->miRegistro.cantVecesLeida > maxVecesLeidas)
            {
                maxVecesLeidas = segPublicacion->miRegistro.cantVecesLeida;

                // Almacena el nombre del autor de la publicación actual como el autor más destacado.
                strcpy(autorMasDestacado, segPublicacion->miRegistro.datosAutor.nombreYapellido);
            }

            segPublicacion = segPublicacion->siguiente;
        }

        seguidora = seguidora->siguiente;
    }

    // Imprimir estadísticas
    printf("\n------ Informes y Estadísticas ------\n");
    printf("Total de publicaciones: %d\n", totalPublicaciones);
    printf("Total de veces leídas: %d\n", totalVecesLeidas);
    printf("Autor más destacado: %s\n", autorMasDestacado);
    printf("------------------------------------\n");
}

