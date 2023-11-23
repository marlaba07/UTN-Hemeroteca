#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "publicacionMusical.h"
#include "Lista_De_Listas.h"

typedef struct
{
    int id;
    char nombreCompleto[30];
    char mail[30];
    char contrasenia[12];
    char generoPreferido[30];
} Usuario;

typedef struct nodoHistorial
{
    datosCadaPublicacion dato;
    struct nodoHistorial *sig;
} nodoHistorial;

typedef struct nodoListaUsuario
{
    Usuario datosLogin;
    nodoHistorial *listaHistorial;
    struct nodoListaUsuario *sig;
} nodoListaUsuario;

nodoHistorial *inicListaHistorial();
nodoListaUsuario *inicListaUsuario();
nodoHistorial *crearNodoHistorial(datosCadaPublicacion data);
nodoListaUsuario *crearNodoUsuario(Usuario dato);
nodoListaUsuario *agregarPrincipioUsuario(nodoListaUsuario *lista, nodoListaUsuario *nuevoNodo);
nodoListaUsuario *archivo2ListaDeListasUsuarios(char archivoUsuarios[], char archivoRegistros[], nodoListaUsuario *lista);
void copiaDeDatos(datosCadaPublicacion *destino, datosCadaPublicacion origen);
int reservarPublicacion(lista_de_listas *listaPublicaciones, char publicacionAReservar[], char genPublicacionAReservar[], datosCadaPublicacion *publicacionEncontrada);
void obtenerRecomendaciones(lista_de_listas *listaPublicaciones, char generoPreferido[]);
nodoListaUsuario *agregarPublicacionAHistorial(lista_de_listas **listaPublicaciones, nodoListaUsuario *listaUsuarios, char emailUsuario[], datosCadaPublicacion *nuevaPublicacion);
nodoListaUsuario *altaUsuario(char archivoRegistros[], nodoListaUsuario *lista, nodoListaUsuario *nuevoNodo);
nodoListaUsuario *buscarUsuarioXID(nodoListaUsuario *lista, int id);
nodoListaUsuario *buscarUsuarioXEmail(nodoListaUsuario *lista, char correo[]);
nodoHistorial *cargarDatosPublicacionesParaUsuario(char archivoRegistros[], nodoHistorial *nuevo);
nodoHistorial *agregarFinalHistorial(nodoHistorial *lista, nodoHistorial *nuevoNodo);
nodoListaUsuario *menuUsuario(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *lista, char archivoUsuarios[], char archivoRegistros[], char archivoAutores[]);
void mostrarHistorialDeUnUsuario(nodoHistorial *lista, char nombreUsuario[]);
void mostrarListaDeUsuarios(nodoListaUsuario *lista);

#endif
