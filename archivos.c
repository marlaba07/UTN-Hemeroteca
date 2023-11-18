#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"

// --- USUARIO ---

Usuario usuario()
{
    Usuario aux;

    printf("Ingresar nombre completo: ");
    fflush(stdin);
    gets(aux.nombreCompleto);

    puts("");

    printf("Ingresar e-mail: ");
    fflush(stdin);
    gets(aux.mail);

    puts("");

    printf("Ingresar contrasenia: ");
    fflush(stdin);
    gets(aux.contrasenia);

    return aux;
}

void cargarArchivoUsuarios(char nombreArchivo[20])
{
    Usuario aux;
    char seguir = 's';

    FILE* archivo = fopen(nombreArchivo, "ab");
    if(archivo)
    {
        while(seguir == 's')
        {
            aux = usuario();

            // ID autoincremental
            fseek(archivo, 0, SEEK_END);
            int cant = ftell(archivo) / sizeof(Usuario);
            aux.id = cant + 1;

            fseek(archivo, 0, SEEK_SET);
            fwrite(&aux, sizeof(Usuario), 1, archivo);

            puts("");

            printf("Desea seguir cargando? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);

            puts("");
        }

        fclose(archivo);
    }
    else
        printf("No se pudo abrir elarchivo \n");
}

void mostrarArchivoUsuarios(char nombreArchivo[20])
{
    Usuario auxiliar;
    FILE* archivo = fopen(nombreArchivo, "rb");
    if(archivo)
    {
        while(fread(&auxiliar, sizeof(Usuario), 1, archivo) > 0)
        {
            mostrarUnUsuario(auxiliar);
        }

        fclose(archivo);
    }
}

void mostrarUnUsuario(Usuario dato)
{
    printf("\n ------------------------------- \n");
    printf(" ID: %d \n", dato.id);
    printf(" Nombre y apellido: %s \n", dato.nombreCompleto);
    printf(" E-mail: %s ", dato.mail);
    printf("\n ------------------------------- \n");
}

// --- PUBLICACION MUSICAL ---

stRegistro registroMusical()
{
    stRegistro aux;

    printf("Ingresar titulo: ");
    fflush(stdin);
    gets(aux.titulo);

    printf("Ingresar genero: ");
    fflush(stdin);
    gets(aux.genero);

    printf("Ingresar fecha de publicacion: ");
    fflush(stdin);
    gets(aux.fechaPublicacion);

    printf("\nIngresar nombre completo del autor: ");
    fflush(stdin);
    gets(aux.nombreYapellidoAutor);

    printf("Ingresar nacionalidad: ");
    fflush(stdin);
    gets(aux.nacionalidad);

    printf("Ingresar biografia: ");
    fflush(stdin);
    gets(aux.biografia);

    return aux;
}

void cargarArchivoRegistro(char nombreArchivo[20])
{
    stRegistro registro;
    char seguir = 's';

    FILE* archivo = fopen(nombreArchivo, "ab");
    if(archivo)
    {
        while(seguir == 's')
        {
            registro = registroMusical();

            fwrite(&registro, sizeof(stRegistro), 1, archivo);

            puts("");
            printf("Desea seguir cargando? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
            puts("");
        }

        fclose(archivo);
    }
    else
        printf("No se pudo abrir elarchivo \n");
}

void mostrarArchivoRegistro(char nombreArchivo[20])
{
    stRegistro registro;
    FILE* archivo = fopen(nombreArchivo, "rb");
    if(archivo)
    {
        while(fread(&registro, sizeof(stRegistro), 1, archivo) > 0)
        {
            mostrarUnRegistro(registro);
        }

        fclose(archivo);
    }
}

void mostrarUnRegistro(stRegistro dato)
{
    printf("\n ------------------------------- \n");
    printf(" Titulo: %s \n", dato.titulo);
    printf(" Genero: %s \n", dato.genero);
    printf(" Fecha publicacion: %s \n", dato.fechaPublicacion);
    printf(" Nombre completo autor: %s \n", dato.nombreYapellidoAutor);
    printf(" Nacionalidad: %s \n", dato.nacionalidad);
    printf(" Biografia: %s ", dato.biografia);
    printf("\n ------------------------------- \n");
}














