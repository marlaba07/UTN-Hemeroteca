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

registro registroMusical()
{
    registro aux;

    printf(" ---- De la publicacion ---- \n");
    printf("Ingresar titulo: ");
    fflush(stdin);
    gets(aux.registro.titulo);

    printf("Ingresar fecha de publicacion: ");
    fflush(stdin);
    gets(aux.registro.fechaPublicacion);

    printf("Ingresar genero: ");
    fflush(stdin);
    gets(aux.registro.genero);

    puts("");

    printf(" ---- Del autor ---- \n");
    printf("\nIngresar nombre completo del autor: ");
    fflush(stdin);
    gets(aux.registro.nombreYapellidoAutor);

    printf("\nIngresar nacionalidad del autor: ");
    fflush(stdin);
    gets(aux.registro.nacionalidad);

    printf("\nIngresar una breve biografia del autor: ");
    fflush(stdin);
    gets(aux.registro.biografia);

    puts("");

    printf(" ---- Adicional ---- \n");
    printf("\nFuente de informacion: ");
    fflush(stdin);
    gets(aux.fuente);

    printf("\nBreve descripcion de la publicacion: ");
    fflush(stdin);
    gets(aux.descripcion);

    printf("\nPalabra clave para facilitar la busqueda: ");
    fflush(stdin);
    gets(aux.etiquetado);

    return aux;
}

void cargarArchivoPublicacion(char nombreArchivo[20])
{
    registro aux;
    char seguir = 's';

    FILE* archivo = fopen(nombreArchivo, "ab");
    if(archivo)
    {
        while(seguir == 's')
        {
            aux = registroMusical();

            // ID autoincremental
            fseek(archivo, 0, SEEK_END);
            int cant = ftell(archivo) / sizeof(registro);
            aux.idRegistro = cant + 1;

            fwrite(&aux, sizeof(registro), 1, archivo);

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

void mostrarArchivoPublicacion(char nombreArchivo[20])
{
    registro aux;
    FILE* archivo = fopen(nombreArchivo, "rb");
    if(archivo)
    {
        while(fread(&aux, sizeof(registro), 1, archivo) > 0)
        {
            mostrarUnaPublicacion(aux);
        }

        fclose(archivo);
    }
}

void mostrarUnaPublicacion(registro dato)
{
    printf("\n ------------------------------- \n");
    printf(" Titulo: %s \n", dato.registro.titulo);
    printf(" Genero: %s \n", dato.registro.genero);
    printf(" Fecha publicacion: %s \n", dato.registro.fechaPublicacion);
    puts("");
    printf(" Nombre completo autor: %s \n", dato.registro.nombreYapellidoAutor);
    printf(" Nacionalidad: %s \n", dato.registro.nacionalidad);
    printf(" Biografia: %s ", dato.registro.biografia);
    puts("");
    printf(" ID Registro: %d \n", dato.idRegistro );
    printf(" Descripcion: %s \n", dato.descripcion );
    printf(" Etiquetado: %s ", dato.etiquetado);
    printf(" Fuenta de informacion: %s ", dato.fuente);
    printf("\n ------------------------------- \n");
}

// --- REGISTRO GENERAL ---

stRegistro registroGeneral()
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

    printf("\n");

    printf("Ingresar nombre completo del autor: ");
    fflush(stdin);
    gets(aux.nombreYapellidoAutor);

    printf("Ingresar nacionalidad del autor: ");
    fflush(stdin);
    gets(aux.nacionalidad);

    printf("Ingresar una breve biografia del autor: ");
    fflush(stdin);
    gets(aux.biografia);

    return aux;
}

void cargarArchivoRegistro(char nombreArchivo[20])
{
    stRegistro aux;
    char seguir = 's';

    FILE* archivo = fopen(nombreArchivo, "ab");
    if(archivo)
    {
        while(seguir == 's')
        {
            aux = registroGeneral();

            fwrite(&aux, sizeof(stRegistro), 1, archivo);

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
    stRegistro aux;
    FILE* archivo = fopen(nombreArchivo, "rb");
    if(archivo)
    {
        while(fread(&aux, sizeof(stRegistro), 1, archivo) > 0)
        {
            mostrarUnRegistro(aux);
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







