#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuarios.h"
#include "archivos.h"

// --- |LISTA DE USUARIOS| ---

nodoListaUsuario* inicListaUsuario()
{
    return NULL;
}

nodoListaUsuario* crearNodoUsuario(Usuario dato)
{
    nodoListaUsuario* aux = (nodoListaUsuario*)malloc(sizeof(nodoListaUsuario));
    aux->datosLogin = dato;
    aux->sig = NULL;

    return aux;
}

nodoListaUsuario* agregarPrincipioUsuario(nodoListaUsuario* lista, nodoListaUsuario* nuevoNodo)
{
    if(lista == NULL)
        lista = nuevoNodo;
    else
    {
        nuevoNodo->sig = lista;
        lista= nuevoNodo;
    }
    return lista;
}

nodoListaUsuario* cargarUsuario(char nombreArchivo[30], nodoListaUsuario* lista)
{
    Usuario auxiliar;

    FILE* archivo = fopen(nombreArchivo, "rb");
    if(archivo)
    {
        while( fread(&auxiliar, sizeof(Usuario), 1, archivo) > 0)
        {
            lista = altaUsuario(lista, auxiliar);
        }

        fclose(archivo);
    }

    return lista;
}

nodoListaUsuario* altaUsuario(nodoListaUsuario* lista, Usuario dato)
{
    // Solo estoy dando de alta el usuario.
    nodoListaUsuario* usuarioEncontrado = buscarUsuario(lista, dato.id);

    if(usuarioEncontrado == NULL)
    {
        nodoListaUsuario* nuevoNodo = crearNodoUsuario(dato);
        lista = agregarPrincipioUsuario(lista, nuevoNodo);
    }

    return lista;
}

nodoListaUsuario* buscarUsuario(nodoListaUsuario* lista, int id)
{
    nodoListaUsuario* seguidora = lista;
    nodoListaUsuario* usuarioEncontrado = NULL;

    while(seguidora!= NULL)
    {
        if(seguidora->datosLogin.id == id)
        {
            usuarioEncontrado = seguidora;
        }

        seguidora = seguidora->sig;
    }

    return usuarioEncontrado;
}

nodoListaUsuario* buscarUsuarioPorEmail(nodoListaUsuario* lista, char correo[30])
{
    nodoListaUsuario* seguidora = lista;
    nodoListaUsuario* usuarioEncontrado = NULL;

    while(seguidora!= NULL )
    {
        if( strcmp(seguidora->datosLogin.mail, correo) == 0 )
        {
            usuarioEncontrado = seguidora;
        }

        seguidora = seguidora->sig;
    }

    return usuarioEncontrado;
}

void mostrarEstructura(nodoListaUsuario* lista)
{
    if(lista != NULL)
    {
        mostrarUnUsuario(lista->datosLogin);
        mostrarEstructura(lista->sig);
    }
}








