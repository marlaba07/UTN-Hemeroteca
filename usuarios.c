#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuarios.h"

// --- |LISTA DE USUARIOS| ---

nodoListaUsuario* inicListaUsuario()
{
    return NULL;
}

nodoListaUsuario* crearNodoUsuario(Usuario dato)
{
    nodoListaUsuario* aux = (nodoListaUsuario*)malloc(sizeof(nodoListaUsuario));
    aux->U = dato;
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






