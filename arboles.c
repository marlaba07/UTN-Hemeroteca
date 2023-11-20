#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

#include "arboles.h"
#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"

// INICIALIZAR ARBOL
nodo_arbol *inic_arbol()
{
    return NULL;
}

// FUNCIONES PARA AGREGAR
nodo_arbol *crear_nodo_arbol(Usuario data)
{
    nodo_arbol *aux = (nodo_arbol *)malloc(sizeof(nodo_arbol));

    if (aux != NULL)
    {
        aux->dato = data;
        aux->derecha = inic_arbol();
        aux->izquierda = inic_arbol();
    }

    return aux;
}

nodo_arbol *insertar_nodo_en_arbol(nodo_arbol *arbol, nodo_arbol *nuevo_nodo)
{
    if (arbol == NULL)
    {
        arbol = nuevo_nodo;
    }
    else
    {
        if (nuevo_nodo->dato.id < arbol->dato.id)
        {
            arbol->izquierda = insertar_nodo_en_arbol(arbol->izquierda, nuevo_nodo);
        }
        else if (nuevo_nodo->dato.id > arbol->dato.id)
        {
            arbol->derecha = insertar_nodo_en_arbol(arbol->derecha, nuevo_nodo);
        }
        else
        {
            printf("Error: este ID de usuario ya existe. \n");
        }
    }
    return arbol;
}

nodo_arbol *archivo2Arbol(char archivoUsuarios[], nodo_arbol *arbol)
{
    Usuario data;
    char continuar = 's';
    FILE *archivo = fopen(archivoUsuarios, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&data, sizeof(Usuario), 1, archivo))
        {
            nodo_arbol *aux = crear_nodo_arbol(data);
            arbol = insertar_nodo_en_arbol(arbol, aux);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }

    return arbol;
}

int buscar(nodo_arbol *arbol, int dato)
{
    int rta = 0;
    if (arbol != NULL)
    {
        if (arbol->dato.id == dato)
            rta = 1;
        else if (arbol->dato.id < dato)
            rta = buscar(arbol->derecha, dato);
        else
            rta = buscar(arbol->izquierda, dato);
    }
    return rta;
}

// FUNCIONES PARA MOSTRAR
void imprimirDatosArbol(nodo_arbol *arbol)
{
    printf("\n ------------------------------- \n");
    printf(" ID: %d \n", arbol->dato.id);
    printf(" Nombre y apellido: %s \n", arbol->dato.nombreCompleto);
    printf(" E-mail: %s \n", arbol->dato.mail);
    printf(" Contrase%ca: %s", 164, arbol->dato.contrasenia);
    printf("\n ------------------------------- \n");
}

void preOrder(nodo_arbol *arbol)
{
    if (arbol != NULL)
    {
        imprimirDatosArbol(arbol);
        preOrder(arbol->izquierda);
        preOrder(arbol->derecha);
    }
}

void inOrder(nodo_arbol *arbol)
{
    if (arbol != NULL)
    {
        inOrder(arbol->izquierda);
        imprimirDatosArbol(arbol);
        inOrder(arbol->derecha);
    }
}

void postOrder(nodo_arbol *arbol)
{
    if (arbol != NULL)
    {
        inOrder(arbol->izquierda);
        inOrder(arbol->derecha);
        imprimirDatosArbol(arbol);
    }
}

// FUNCIONES PARA BORRAR
int es_hoja(nodo_arbol *arbol)
{
    int rta = -1;
    if ((arbol->derecha == NULL) && (arbol->izquierda == NULL))
    {
        rta = 1;
    }
    else
    {
        rta = 0;
    }
    return rta;
}

nodo_arbol *nodo_mas_derecha(nodo_arbol *arbol)
{
    if (arbol->derecha != NULL)
    {
        arbol = nodo_mas_derecha(arbol->derecha);
    }
    return arbol;
}

nodo_arbol *nodo_mas_izquierda(nodo_arbol *arbol)
{
    if (arbol->izquierda != NULL)
    {
        arbol = nodo_mas_izquierda(arbol->izquierda);
    }
    return arbol;
}

nodo_arbol *borrar_nodo_arbol(nodo_arbol *arbol, int dato)
{
    if (arbol != NULL)
    {
        if (arbol->dato.id == dato)
        {
            if (es_hoja(arbol) == 1)
            {
                free(arbol);
                arbol = NULL;
            }
            else if (arbol->izquierda != NULL)
            {
                nodo_arbol *nodo_derecha = nodo_mas_derecha(arbol->izquierda);
                arbol->dato.id = nodo_derecha->dato.id;
                arbol->izquierda = borrar_nodo_arbol(arbol->izquierda, nodo_derecha->dato.id);
            }
            else if (arbol->derecha != NULL)
            {
                nodo_arbol *nodo_izquierda = nodo_mas_izquierda(arbol->derecha);
                arbol->dato.id = nodo_izquierda->dato.id;
                arbol->derecha = borrar_nodo_arbol(arbol->derecha, nodo_izquierda->dato.id);
            }
        }
        else if (arbol->dato.id > dato)
        {
            arbol->izquierda = borrar_nodo_arbol(arbol->izquierda, dato);
        }
        else
        {
            arbol->derecha = borrar_nodo_arbol(arbol->derecha, dato);
        }
    }
    return arbol;
}



