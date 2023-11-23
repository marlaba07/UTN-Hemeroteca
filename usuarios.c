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

// --- LISTA DE USUARIOS (SIN HISTORIAL) --- //
nodoHistorial *inicListaHistorial()
{
    return NULL;
}

nodoListaUsuario *inicListaUsuario()
{
    return NULL;
}

nodoHistorial *crearNodoHistorial(datosCadaPublicacion data)
{
    nodoHistorial *aux = (nodoHistorial *)malloc(sizeof(nodoHistorial));

    if (aux != NULL)
    {
        aux->dato = data;
        aux->sig = NULL;
    }

    return aux;
}

nodoListaUsuario *crearNodoUsuario(Usuario dato)
{
    nodoListaUsuario *aux = (nodoListaUsuario *)malloc(sizeof(nodoListaUsuario));

    if (aux != NULL)
    {
        aux->datosLogin = dato;
        aux->listaHistorial = inicListaHistorial();
        aux->sig = NULL;
    }

    return aux;
}

nodoListaUsuario *agregarPrincipioUsuario(nodoListaUsuario *lista, nodoListaUsuario *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodoListaUsuario *buscarUsuarioXID(nodoListaUsuario *lista, int id)
{
    nodoListaUsuario *seg = lista;
    nodoListaUsuario *usuarioEncontrado = NULL;

    int flag = 0;

    while ((seg != NULL) && (flag == 0))
    {
        if (seg->datosLogin.id == id)
        {
            usuarioEncontrado = seg;
            flag = 1;
        }

        seg = seg->sig;
    }

    printf("%i", flag);
    return usuarioEncontrado;
}

nodoListaUsuario *buscarUsuarioXEmail(nodoListaUsuario *lista, char correo[30])
{
    nodoListaUsuario *seg = lista;
    nodoListaUsuario *usuarioEncontrado = NULL;

    int flag = 0;

    while ((seg != NULL) && (flag == 0))
    {
        if (strcmp(seg->datosLogin.mail, correo) == 0)
        {
            usuarioEncontrado = seg;
            flag = 1;
        }

        seg = seg->sig;
    }

    return usuarioEncontrado;
}

nodoHistorial *agregarFinalHistorial(nodoHistorial *lista, nodoHistorial *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoHistorial *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }
        seg->sig = nuevoNodo;
    }
    return lista;
}

nodoListaUsuario *agregarPublicacionAHistorial(lista_de_listas **listaPublicaciones, nodoListaUsuario *listaUsuarios, char emailUsuario[], datosCadaPublicacion *nuevaPublicacion)
{
    nodoListaUsuario *usuarioEncontrado = buscarUsuarioXEmail(listaUsuarios, emailUsuario);

    if (usuarioEncontrado != NULL)
    {
        nodoHistorial *nuevoHistorial = crearNodoHistorial(*nuevaPublicacion);

        if (nuevoHistorial->dato.prestado == 0)
        {
            nuevoHistorial->dato.prestado = 1;
        }

        nuevoHistorial->dato.cantVecesLeida++;
        actualizarCantVecesLeidasYPrestamoDePublicacion(*listaPublicaciones, nuevoHistorial->dato.datosPublicacion.genero, nuevoHistorial->dato.datosPublicacion.titulo);

        usuarioEncontrado->listaHistorial = agregarFinalHistorial(usuarioEncontrado->listaHistorial, nuevoHistorial);
        printf("Publicacion agregada al historial de %s.\n", usuarioEncontrado->datosLogin.nombreCompleto);
        system("pause");
    }
    else
    {
        printf("El usuario con email %s no se ha encontrado. \n", emailUsuario);
        system("pause");
    }

    return listaUsuarios;
}

nodoListaUsuario *altaUsuario(char archivoRegistros[], nodoListaUsuario *lista, nodoListaUsuario *nuevoNodo)
{
    nodoListaUsuario *usuarioEncontrado = buscarUsuarioXID(lista, nuevoNodo->datosLogin.id);

    if (usuarioEncontrado == NULL)
    {
        lista = agregarPrincipioUsuario(lista, nuevoNodo);
    }

    return lista;
}

nodoListaUsuario *archivo2ListaDeListasUsuarios(char archivoUsuarios[], char archivoRegistros[], nodoListaUsuario *lista)
{
    Usuario data;

    FILE *archivo = fopen(archivoUsuarios, "rb");

    if (archivo != NULL)
    {
        while (fread(&data, sizeof(Usuario), 1, archivo) > 0)
        {
            nodoListaUsuario *aux = crearNodoUsuario(data);
            // aux->listaHistorial = inicListaHistorial();
            lista = agregarPrincipioUsuario(lista, aux);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo de usuarios. \n");
    }

    return lista;
}

// --- RESERVAR PUBLICACIONES --- //
void copiaDeDatos(datosCadaPublicacion *destino, datosCadaPublicacion origen)
{
    strcpy(destino->datosAutor.nombreYapellido, origen.datosAutor.nombreYapellido);
    strcpy(destino->datosAutor.nacionalidad, origen.datosAutor.nacionalidad);
    strcpy(destino->datosAutor.biografia, origen.datosAutor.biografia);
    strcpy(destino->datosPublicacion.titulo, origen.datosPublicacion.titulo);
    strcpy(destino->datosPublicacion.genero, origen.datosPublicacion.genero);
    destino->datosPublicacion.dia = origen.datosPublicacion.dia;
    destino->datosPublicacion.mes = origen.datosPublicacion.mes;
    destino->datosPublicacion.anio = origen.datosPublicacion.anio;
    strcpy(destino->datosPublicacion.descripcion, origen.datosPublicacion.descripcion);
    strcpy(destino->palabraClave1, origen.palabraClave1);
    strcpy(destino->palabraClave2, origen.palabraClave2);
    strcpy(destino->fuente, origen.fuente);
    destino->prestado = origen.prestado;
    destino->opiniones = origen.opiniones;
    destino->cantVecesLeida = origen.cantVecesLeida;
}

int reservarPublicacion(lista_de_listas *listaPublicaciones, char publicacionAReservar[], char genPublicacionAReservar[], datosCadaPublicacion *publicacionEncontrada)
{
    int rta = 0;
    lista_de_listas *genEncontrado = buscarNodoGenero(listaPublicaciones, genPublicacionAReservar);

    if (genEncontrado != NULL)
    {
        genEncontrado->listaDatosPublicaciones = buscarNodoTitulo(genEncontrado->listaDatosPublicaciones, publicacionAReservar);
        copiaDeDatos(publicacionEncontrada, genEncontrado->listaDatosPublicaciones->miRegistro);
        rta = 1;
    }

    return rta;
}

// --- OBTENER RECOMENDACIONES --- //
void obtenerRecomendaciones(lista_de_listas *listaPublicaciones, char generoPreferido[])
{
    lista_de_listas *seg = listaPublicaciones;

    while (seg != NULL)
    {
        nodo_sublista_simple *nodoActual = seg->listaDatosPublicaciones;

        while (nodoActual != NULL)
        {
            // Verificar si la publicacion coincide con las preferencias del usuario
            if (strcmpi(nodoActual->miRegistro.datosPublicacion.genero, generoPreferido) == 0)
            {
                // Mostrar la publicacion como recomendacion
                // printf("Recomendacion: %s\n", nodoActual->miRegistro.datosPublicacion.titulo);
                mostrarUnaPublicacion(nodoActual->miRegistro);
            }

            nodoActual = nodoActual->siguiente;
        }

        seg = seg->siguiente;
    }
}

// --- LISTA DE USUARIOS (CON HISTORIAL) --- //
void mostrarHistorialDeUnUsuario(nodoHistorial *lista, char nombreUsuario[])
{
    nodoHistorial *nodoActual = lista;

    printf("  " ROJO_F "\n Historial de %s: \n" RESET_COLOR, nombreUsuario);

    while (nodoActual != NULL)
    {
        mostrarUnaPublicacion(nodoActual->dato);
        nodoActual = nodoActual->sig;
    }

    printf(" Fin del historial.\n\n");
}

void mostrarListaDeUsuarios(nodoListaUsuario *lista)
{
    nodoListaUsuario *seg = lista;

    while (seg != NULL)
    {
        mostrarUnUsuario(seg->datosLogin);
        mostrarHistorialDeUnUsuario(seg->listaHistorial, seg->datosLogin.nombreCompleto); // Mostrar historial solo una vez

        seg = seg->sig;
    }
}
