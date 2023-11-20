#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include "usuarios.h"

typedef struct nodo_arbol
{
    Usuario dato;
    struct nodo_arbol *derecha;
    struct nodo_arbol *izquierda;
} nodo_arbol;

nodo_arbol *inic_arbol();
nodo_arbol *crear_nodo_arbol(Usuario);
nodo_arbol *insertar_nodo_en_arbol(nodo_arbol *, nodo_arbol *);
nodo_arbol *archivo2Arbol(char archivoUsuarios[], nodo_arbol *arbol);
int buscar(nodo_arbol *, int);
nodo_arbol *borrar_nodo(nodo_arbol *, int);
void preOrder(nodo_arbol *);
void inOrder(nodo_arbol *);
void postOrder(nodo_arbol *);
int es_hoja(nodo_arbol *);
nodo_arbol *nodo_mas_derecha(nodo_arbol *);
nodo_arbol *nodo_mas_izquierda(nodo_arbol *);
nodo_arbol *borrar_nodo_arbol(nodo_arbol *, int);

#endif