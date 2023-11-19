#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "publicacionMusical.h"

typedef struct
{
    int id;
    char nombreCompleto[30];
    char mail[50];
    char contrasenia[8];
} Usuario;

typedef struct
{
    registro dato;
    struct nodoHistorial* sig;
    struct nodoHistorial* ant;
} nodoHistorial;

typedef struct
{
    Usuario datosLogin;
    nodoHistorial* listaHistorial;
    struct nodoListaUsuario* sig;
} nodoListaUsuario;

nodoListaUsuario* inicListaUsuario();
nodoListaUsuario* crearNodoUsuario(Usuario dato);
nodoListaUsuario* agregarPrincipioUsuario(nodoListaUsuario* lista, nodoListaUsuario* nuevoNodo);
nodoListaUsuario* cargarUsuario(char nombreArchivo[30], nodoListaUsuario* lista);
nodoListaUsuario* altaUsuario(nodoListaUsuario* lista, Usuario dato);
nodoListaUsuario* buscarUsuario(nodoListaUsuario* lista, int id);
nodoListaUsuario* buscarUsuarioPorEmail(nodoListaUsuario* lista, char correo[30]);
nodoListaUsuario* menuUsuario(nodoListaUsuario* usuarioEncontrado, nodoListaUsuario* lista, char archivoUsuarios[]);

#endif
