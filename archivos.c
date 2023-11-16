#include "archivos.h"
#include "usuarios.h"

// --- USUARIO ---

void cargarArchivoUsuarios(char nombreArchivo[20])
{
    Usuario aux;
    char seguir = 's';

    FILE* archivo = fopen(nombreArchivo, "ab");
    if(archivo)
    {
        while(seguir == 's')
        {
            printf("Ingresar nombre completo: \n");
            fflush(stdin);
            gets(aux.nombreCompleto);

            printf("Ingresar e-mail: \n");
            fflush(stdin);
            gets(aux.mail);

            printf("Ingresar contrasenia: \n");
            fflush(stdin);
            gets(aux.contrasenia);

            // ID autoincremental
            fseek(archivo, 0, SEEK_END);
            int cant = ftell(archivo) / sizeof(Usuario);
            aux.id = cant;

            fseek(archi, 0, SEEK_SET);
            fwrite(&aux, sizeof(stUsuario), 1, archi);

            printf("Desea seguir cargando? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
        }

        fclose(archi);
    }
    else
        printf("No se pudo abrir elarchivo \n");
}
