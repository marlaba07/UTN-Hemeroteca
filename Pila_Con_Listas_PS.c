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

void inicializarPila(Pila *pila)
{
    pila->tope = NULL;
}

void apilar(Pila *pila, datosCadaPublicacion valor)
{
    nodo_lista_simple_en_pila_PS *nuevo = (nodo_lista_simple_en_pila_PS *)malloc(sizeof(nodo_lista_simple_en_pila_PS));

    nuevo->dato = valor;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
}

int pilavacia(Pila *pila)
{
    return pila->tope == NULL;
}

datosCadaPublicacion desapilar(Pila *pila)
{
    datosCadaPublicacion valor;

    if (pilavacia(pila))
    {
        printf("La pila esta vacia. \n");
    }
    else
    {
        valor = pila->tope->dato;
        nodo_lista_simple_en_pila_PS *temp = pila->tope;
        pila->tope = pila->tope->siguiente;
        free(temp);
    }

    return valor;
}

void mostrar(Pila *pila)
{
    nodo_lista_simple_en_pila_PS *actual = pila->tope;

    printf("Contenido de la pila:\n");

    while (actual != NULL)
    {

        mostrarUnaPublicacion(actual->dato);

        actual = actual->siguiente;
    }
}

// Funcion para mostrar las publicaciones mas populares usando una pila
void mostrarPublicacionesPopulares(lista_de_listas *listaPublicaciones, Pila *pila)
{
    Pila aux = inicializarPila();
    lista_de_listas *seg = listaPublicaciones;

    while (seg != NULL)
    {
        nodo_sublista_simple *nodoActual = seg->listaDatosPublicaciones;

        while (nodoActual != NULL)
        {
            if (pila->tope == NULL || nodoActual->miRegistro.cantVecesLeida > pila->tope->dato.cantVecesLeida)
            {
                // Si la pila está vacía o la publicación actual tiene más lecturas que la superior de la pila, se apila
                apilar(pila, nodoActual->miRegistro);
            }
            else
            {
                while (!pilavacia(pila))
                {
                    // Se desapilan todas las anteriores (en caso de múltiples publicaciones igualmente populares)
                    datosCadaPublicacion temp = desapilar(pila);
                    apilar(pila, temp->dato);
                }
            }

            nodoActual = nodoActual->siguiente;
        }

        seg = seg->siguiente;
    }

    // Muestra las publicaciones desde la pila en el orden correcto
    while (!pilavacia(pila))
    {
        datosCadaPublicacion temp = desapilar(pila);
        mostrarUnaPublicacion(temp);
    }
}
