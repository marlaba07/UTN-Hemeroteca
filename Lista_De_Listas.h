#ifndef LISTA_DE_LISTAS_H_INCLUDED
#define LISTA_DE_LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// ESTRUCTURAS DE LA LISTA DE LISTAS
typedef struct nodo_sublista_simple
{
    datosCadaPublicacion miRegistro;
    struct nodo_sublista_simple *siguiente;
} nodo_sublista_simple;

typedef struct lista_de_listas
{
    char genero[30];
    nodo_sublista_simple *listaDatosPublicaciones;
    struct lista_de_listas *siguiente;
} lista_de_listas;

nodo_sublista_simple *inicSubLista();
lista_de_listas *inicListaDelistas();
nodo_sublista_simple *crearNodoSublista(datosCadaPublicacion data);
lista_de_listas *crearNodoListaPrincipal(char genero[]);
nodo_sublista_simple *buscarYActualizarNodoTitulo(nodo_sublista_simple *listaDatosPublicaciones, char titulo[]);
nodo_sublista_simple *buscarNodoTitulo(nodo_sublista_simple *lista, char titulo[]);
lista_de_listas *buscarNodoGenero(lista_de_listas *lista, char genero[]);
nodo_sublista_simple *agregarFinalDatosPublicacion(nodo_sublista_simple *sublista, nodo_sublista_simple *nuevaPublicacion);
lista_de_listas *agregarPpioListaGeneral(lista_de_listas *lista, lista_de_listas *nuevoNodo);
lista_de_listas *actualizarCantVecesLeidasYPrestamoDePublicacion(lista_de_listas *listaGeneros, char genero[], char titulo[]);
lista_de_listas *alta(lista_de_listas *listaGeneros, nodo_sublista_simple *nuevaPublicacion);
lista_de_listas *archivo2ListaDeListas(char nombreArchivo[], lista_de_listas *lista);
void imprimir(nodo_sublista_simple *lista, int i);
void recorrerYmostrarListaDeListas(lista_de_listas *lista);

#endif // LISTA_DE_LISTAS_H_INCLUDED
