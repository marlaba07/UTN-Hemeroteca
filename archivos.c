#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"

// --- USUARIO --- //

Usuario cargarDatosUnUsuario()
{
    Usuario aux;

    printf("Ingresar nombre completo: ");
    fflush(stdin);
    //fgets(aux.nombreCompleto, sizeof(aux.nombreCompleto), stdin);
    gets(aux.nombreCompleto);

    printf("Ingresar e-mail: ");
    fflush(stdin);
    //fgets(aux.mail, sizeof(aux.mail), stdin);
    gets(aux.mail);

    printf("Ingresar contrase%ca: ", 164);
    fflush(stdin);
    //fgets(aux.contrasenia, sizeof(aux.contrasenia), stdin);
    gets(aux.contrasenia);

    return aux;
}

void cargarArchivoUsuarios(char nombreArchivo[20])
{
    srand(time(NULL));

    Usuario aux;
    char seguir = 's';

    FILE *archivo = fopen(nombreArchivo, "ab");

    if (archivo != NULL)
    {
        while (seguir == 's')
        {
            aux = cargarDatosUnUsuario();

            /* // ID autoincremental
            fseek(archivo, 0, SEEK_END);
            int cant = ftell(archivo) / sizeof(Usuario);
            aux.id = cant + 1; */

            aux.id = rand() % 50 + 1;

            fseek(archivo, 0, SEEK_SET);
            fwrite(&aux, sizeof(Usuario), 1, archivo);

            printf("Desea seguir cargando usuarios? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarArchivoUsuarios(char nombreArchivo[20])
{
    Usuario auxiliar;

    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo != NULL)
    {
        while (fread(&auxiliar, sizeof(Usuario), 1, archivo) > 0)
        {
            mostrarUnUsuario(auxiliar);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarUnUsuario(Usuario dato)
{
    printf("\n ------------------------------- \n");
    printf(" ID: %d \n", dato.id);
    printf(" Nombre y apellido: %s", dato.nombreCompleto);
    printf(" E-mail: %s ", dato.mail);
    printf("\n ------------------------------- \n");
}

// --- PUBLICACION MUSICAL --- //

datosCadaPublicacion pedirDatosRegistro()
{
    datosCadaPublicacion nuevoRegistro;

    printf("---- Carga de Datos de la Publicacion: ----\n");

    printf("- Ingrese el titulo: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosPublicacion.titulo, sizeof(nuevoRegistro.datosPublicacion.titulo), stdin);

    printf("- Ingrese el genero: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosPublicacion.genero, sizeof(nuevoRegistro.datosPublicacion.genero), stdin);

    printf("- Ingrese el dia de publicacion: ");
    nuevoRegistro.datosPublicacion.dia = ingresarDia();

    printf("- Ingrese el mes de publicacion: ");
    nuevoRegistro.datosPublicacion.mes = ingresarMes();

    printf("- Ingrese el anio de publicacion: ");
    nuevoRegistro.datosPublicacion.anio = ingresarAnio();

    printf("- Ingrese el nombre y apellido del autor: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosAutor.nombreYapellido, sizeof(nuevoRegistro.datosAutor.nombreYapellido), stdin);

    printf("- Ingrese la nacionalidad del autor: ");
    fgets(nuevoRegistro.datosAutor.nacionalidad, sizeof(nuevoRegistro.datosAutor.nacionalidad), stdin);

    printf("\n- Ingrese la biografia del autor: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosAutor.biografia, sizeof(nuevoRegistro.datosAutor.biografia), stdin);

    printf("\n- Ingrese la descripcion: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosPublicacion.descripcion, sizeof(nuevoRegistro.datosPublicacion.descripcion), stdin);

    printf("\n- Ingrese la primera palabra clave: ");
    fflush(stdin);
    fgets(nuevoRegistro.palabraClave1, sizeof(nuevoRegistro.palabraClave1), stdin);

    printf("- Ingrese la segunda palabra clave: ");
    fflush(stdin);
    fgets(nuevoRegistro.palabraClave2, sizeof(nuevoRegistro.palabraClave2), stdin);

    // Inicializa otros campos si es necesario
    nuevoRegistro.opiniones = NULL; // Inicializa la lista de opiniones como vacia
    nuevoRegistro.prestado = 0;     // Por defecto, no prestado
    nuevoRegistro.cantVecesLeida = 0;
    strcpy(nuevoRegistro.fuente, "Hemeroteca");

    return nuevoRegistro;
}

void cargarArchivoPublicacion(char nombreArchivo[20])
{
    datosCadaPublicacion aux;
    char seguir = 's';

    FILE *archivo = fopen(nombreArchivo, "ab");

    if (archivo != NULL)
    {
        while (seguir == 's')
        {
            aux = pedirDatosRegistro();

            fwrite(&aux, sizeof(datosCadaPublicacion), 1, archivo);

            printf("\nDesea seguir cargando publicaciones? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarUnaPublicacion(datosCadaPublicacion dato)
{
    printf("\n ------------------------------- \n");
    printf("- Titulo: %s", dato.datosPublicacion.titulo);
    printf("- Genero: %s", dato.datosPublicacion.genero);
    mostrarFecha(dato);
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

void mostrarArchivoPublicacion(char nombreArchivo[20])
{
    datosCadaPublicacion aux;
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&aux, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            mostrarUnaPublicacion(aux);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void actualizarInformacionPublicacion(char nombreArchivo[20])
{
    int opcion;
    datosCadaPublicacion aux;
    char tituloBuscar[50];

    printf("Ingrese el titulo de la publicacion a actualizar: ");
    fflush(stdin);
    fgets(tituloBuscar, sizeof(tituloBuscar), stdin);

    int posicion = buscarRegistro(nombreArchivo, tituloBuscar);     // Busca el registro en el archivo

    if (posicion != -1)
    {
        FILE *archivo = fopen(nombreArchivo, "r+b");
        if (archivo != NULL)
        {
            fseek(archivo, posicion * sizeof(datosCadaPublicacion), SEEK_SET);  // Mueve el puntero al inicio del registro a actualizar
            fread(&aux, sizeof(datosCadaPublicacion), 1, archivo);              // Lee el registro actual

            printf("\n\nQue informacion desea actualizar? \n");
            printf("1. Titulo \n");
            printf("2. Autor \n");
            printf("3. Descripcion \n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                printf("Ingrese el nuevo titulo: ");
                fflush(stdin);
                fgets(aux.datosPublicacion.titulo, sizeof(aux.datosPublicacion.titulo), stdin);
                //gets( aux.datosPublicacion.titulo );
                break;
            case 2:
                printf("Ingrese la nueva descripcion: ");
                fflush(stdin);
                fgets(aux.datosAutor.nombreYapellido, sizeof(aux.datosAutor.nombreYapellido), stdin);
                //gets( aux.datosPublicacion.descripcion );
                break;
            case 3:
                printf("Ingrese el nuevo autor: ");
                fflush(stdin);
                fgets(aux.datosAutor.nombreYapellido, sizeof(aux.datosAutor.nombreYapellido), stdin);
                //gets( aux.datosAutor.nombreYapellido );
                break;
            default:
                printf("Opción no valida.\n");
                break;
            }

            fseek(archivo, posicion * sizeof(datosCadaPublicacion), SEEK_SET);  // Mover el puntero al inicio del registro a actualizar en el archivo
            fwrite(&aux, sizeof(datosCadaPublicacion), 1, archivo); // Escribir el registro actualizado en el archivo
            fclose(archivo);

            printf("Información de la publicación actualizada exitosamente. \n");
        }
        else
        {
            printf("Error: no se pudo abrir el archivo.\n");
        }
    }
    else
    {
        printf("Publicacion no encontrada.\n");
    }
}

int buscarRegistro(char nombreArchivo[20], char tituloBuscar[])
{
    datosCadaPublicacion aux;
    int posicion = 0;
    int flag = -1;

    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo != NULL)
    {
        while (fread(&aux, sizeof(datosCadaPublicacion), 1, archivo) == 1)
        {
            if (strcmpi(aux.datosPublicacion.titulo, tituloBuscar) == 0)
            {
                flag = posicion;
                break;
            }

            posicion++;
        }

        fclose(archivo);
    }

    return flag; // Retorna -1 si no se encontró el registro
}




