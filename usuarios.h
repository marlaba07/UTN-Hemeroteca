#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "publicacionMusical.h"

typedef struct
{
    int id;
    char nombreCompleto[30];
    char mail[50];
    char contrasenia[12];
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
nodoListaUsuario *altaUsuario(char archivoRegistros[], nodoListaUsuario *lista, nodoListaUsuario *nuevoNodo);
nodoListaUsuario *buscarUsuario(nodoListaUsuario *lista, int id);
nodoListaUsuario *buscarUsuarioPorEmail(nodoListaUsuario *lista, char correo[30]);
nodoHistorial *cargarDatosPublicacionesParaUsuario(char archivoRegistros[], nodoHistorial *nuevo);
nodoHistorial *agregarFinalHistorial(nodoHistorial *lista, nodoHistorial *nuevoNodo);
nodoListaUsuario *menuUsuario(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *lista);
void imprimirHistorialDeUnUsuario(datosCadaPublicacion dato);
void mostrarHistorialDeUnUsuario(nodoHistorial *lista);
void mostrarListaDeUsuarios(nodoListaUsuario *lista);

#endif
