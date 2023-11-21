#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "publicacionMusical.h"
#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"

// --- LISTA DE USUARIOS (SIN HISTORIAL) --- //
nodoHistorial *inicListaHistorial()
{
    return NULL;
}

nodoListaUsuario *inicListaUsuario()
{
    return NULL;
}

nodoHistorial *crearNodoHistorial(datosCadaPublicacion data)
{
    nodoHistorial *aux = (nodoHistorial *)malloc(sizeof(nodoHistorial));

    if (aux != NULL)
    {
        aux->dato = data;
        aux->sig = NULL;
    }

    return aux;
}

nodoListaUsuario *crearNodoUsuario(Usuario dato)
{
    nodoListaUsuario *aux = (nodoListaUsuario *)malloc(sizeof(nodoListaUsuario));

    if (aux != NULL)
    {
        aux->datosLogin = dato;
        aux->listaHistorial = inicListaHistorial();
        aux->sig = NULL;
    }

    return aux;
}

nodoListaUsuario *agregarPrincipioUsuario(nodoListaUsuario *lista, nodoListaUsuario *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodoListaUsuario *buscarUsuario(nodoListaUsuario *lista, int id)
{
    nodoListaUsuario *seg = lista;
    nodoListaUsuario *usuarioEncontrado = NULL;

    int flag = 0;

    while ((seg != NULL) && (flag == 0))
    {
        if (seg->datosLogin.id == id)
        {
            usuarioEncontrado = seg;
            flag = 1;
        }

        seg = seg->sig;
    }

    printf("%i", flag);
    return usuarioEncontrado;
}

/*
nodoHistorial *cargarDatosPublicacionesParaUsuario(char archivoRegistros[], nodoHistorial *lista)
{
    datosCadaPublicacion data;

    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            nodoHistorial *nuevo = crearNodoHistorial(data);
            lista = agregarFinalHistorial(lista, nuevo);
        }
        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
    return lista;
}

nodoHistorial *agregarFinalHistorial(nodoHistorial *lista, nodoHistorial *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoHistorial *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }
        seg->sig = nuevoNodo;
    }
    return lista;
}

nodoListaUsuario *altaUsuario(char archivoRegistros[], nodoListaUsuario *lista, nodoListaUsuario *nuevoNodo)
{
    nodoListaUsuario *usuarioEncontrado = buscarUsuario(lista, nuevoNodo->datosLogin.id);

    if (usuarioEncontrado == NULL)
    {
        lista = agregarPrincipioUsuario(lista, nuevoNodo);
    }

    return lista;
}
*/

nodoListaUsuario *archivo2ListaDeListasUsuarios(char archivoUsuarios[], char archivoRegistros[], nodoListaUsuario *lista)
{
    Usuario data;

    FILE *archivo = fopen(archivoUsuarios, "rb");

    if (archivo != NULL)
    {
        while (fread(&data, sizeof(Usuario), 1, archivo) > 0)
        {
            nodoListaUsuario *aux = crearNodoUsuario(data);
            // aux->listaHistorial = inicListaHistorial();
            lista = agregarPrincipioUsuario(lista, aux);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo de usuarios. \n");
    }

    return lista;
}

nodoListaUsuario *buscarUsuarioPorEmail(nodoListaUsuario *lista, char correo[30])
{
    nodoListaUsuario *seg = lista;
    nodoListaUsuario *usuarioEncontrado = NULL;

    int flag = 0;

    while ((seg != NULL) && (flag == 0))
    {
        if (strcmp(seg->datosLogin.mail, correo) == 0)
        {
            usuarioEncontrado = seg;
            flag = 1;
        }

        seg = seg->sig;
    }

    return usuarioEncontrado;
}

// --- LISTA DE USUARIOS (CON HISTORIAL) --- //
void imprimirHistorialDeUnUsuario(datosCadaPublicacion dato)
{
    printf("\n ------------------------------- \n");
    printf("- Titulo: %s", dato.datosPublicacion.titulo);
    printf("- Genero: %s", dato.datosPublicacion.genero);
    printf("- Fecha ingresada (con barras): %02d/%02d/%04d\n\n", dato.datosPublicacion.dia, dato.datosPublicacion.mes, dato.datosPublicacion.anio);
    printf("- Descripcion: %s \n\n", dato.datosPublicacion.descripcion);
    printf("- Nombre completo del autor: %s", dato.datosAutor.nombreYapellido);
    printf("- Nacionalidad: %s \n", dato.datosAutor.nacionalidad);
    printf("- Biografia: %s \n\n", dato.datosAutor.biografia);
    printf("- Primer palabra clave: %s", dato.palabraClave1);
    printf("- Primer palabra clave: %s", dato.palabraClave2);
    printf("- Prestado (1 = si | 0 = no): %d \n", dato.prestado);
    printf("- Fuente de informacion: %s \n", dato.fuente);
    printf("- Veces leidas: %d", dato.cantVecesLeida);
    printf("\n ------------------------------- \n");
}

void mostrarHistorialDeUnUsuario(nodoHistorial *lista)
{
    nodoHistorial *seg = lista;

    if (seg != NULL)
    {
        while (seg != NULL)
        {
            imprimirHistorialDeUnUsuario(seg->dato);
            seg = seg->sig;
        }
    }
    else
    {
        printf("El usuario aun no ha a%cadido publicaciones a su historial.\n", 164);
    }
}

void mostrarListaDeUsuarios(nodoListaUsuario *lista)
{
    nodoListaUsuario *seg = lista;

    while (seg != NULL)
    {
        mostrarUnUsuario(seg->datosLogin);
        nodoHistorial *segAux = seg->listaHistorial;

        if (segAux == NULL)
        {
            printf("Historial de %s:\n", seg->datosLogin.nombreCompleto);
            printf("No se ha a%cadido ninguna publicacion. \n", 164);
        }
        else
        {
            printf("Historial de %s: ", seg->datosLogin.nombreCompleto);
            mostrarHistorialDeUnUsuario(segAux);
        }

        seg = seg->sig;
    }
}
