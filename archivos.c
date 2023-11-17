#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuarios.h"
#include "archivos.h"

// --- USUARIO ---

Usuario usuario()
{
    Usuario aux;

    printf("Ingresar nombre completo: \n");
    fflush(stdin);
    gets(aux.nombreCompleto);

    printf("Ingresar e-mail: \n");
    fflush(stdin);
    gets(aux.mail);

    printf("Ingresar contrasenia: \n");
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
            aux.id = cant;

            fseek(archivo, 0, SEEK_SET);
            fwrite(&aux, sizeof(Usuario), 1, archivo);

            printf("Desea seguir cargando? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
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
    printf(" E-mail: %s \n", dato.mail);
    printf("\n ------------------------------- \n");
}





















