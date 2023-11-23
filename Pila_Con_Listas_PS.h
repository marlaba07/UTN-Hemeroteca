#ifndef PILA_CON_LISTAS_PS_H_INCLUDED
#define PILA_CON_LISTAS_PS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "Lista_De_Listas.h"
#include "publicacionMusical.h"

typedef struct nodo_lista_simple_en_pila_PS
{
    datosCadaPublicacion dato;
    struct nodo_lista_simple_en_pila_PS *siguiente;
} nodo_lista_simple_en_pila_PS;

typedef struct
{
    nodo_lista_simple_en_pila_PS *tope;
} Pila;

void inicializarPila(Pila *pila);
void apilar(Pila *pila, datosCadaPublicacion valor);
datosCadaPublicacion desapilar(Pila *pila);
int pilavacia(Pila *pila);
void mostrar(Pila *pila);
void mostrarPublicacionesPopulares(lista_de_listas *listaPublicaciones, Pila *pila);

#endif