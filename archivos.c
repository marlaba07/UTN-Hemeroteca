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

    printf("Ingrese su nombre completo: ");
    fflush(stdin);
    fgets(aux.nombreCompleto, sizeof(aux.nombreCompleto), stdin);

    printf("Ingrese su e-mail: ");
    fflush(stdin);
    fgets(aux.mail, sizeof(aux.mail), stdin);

    printf("Ingrese su contrase%ca: ", 164);
    fflush(stdin);
    fgets(aux.contrasenia, sizeof(aux.contrasenia), stdin);

    return aux;
}

void cargarArchivoUsuarios(char archivoUsuarios[])
{
    Usuario aux;
    char seguir = 's';

    FILE *archivo = fopen(archivoUsuarios, "ab");

    if (archivo != NULL)
    {
        while (seguir == 's')
        {
            aux = cargarDatosUnUsuario();
            fflush(stdin);
            aux.id = (rand() % 100) + 1;

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

void mostrarUnUsuario(Usuario dato)
{
    printf("\n ------------------------------- \n");
    printf(" ID: %d \n", dato.id);
    printf(" Nombre y apellido: %s", dato.nombreCompleto);
    printf(" E-mail: %s ", dato.mail);
    printf("\n ------------------------------- \n");
}

void mostrarArchivoUsuarios(char archivoUsuarios[])
{
    Usuario auxiliar;

    FILE *archivo = fopen(archivoUsuarios, "rb");

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

void cargarArchivoPublicacion(char archivoRegistros[])
{
    datosCadaPublicacion aux;
    char seguir = 's';

    FILE *archivo = fopen(archivoRegistros, "ab");

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

// --- FUNCIONES DE MOSTRADO --- //
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

void mostrarArchivoPublicacion(char archivoRegistros[])
{
    datosCadaPublicacion aux;
    FILE *archivo = fopen(archivoRegistros, "rb");

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

// --- FUNCIONES DE BUSQUEDA --- //
// Funcion para buscar por titulo en el archivo
int buscarPorTitulo(char archivoRegistros[], char tituloABuscar[], datosCadaPublicacion publicacionEncontrada)
{
    FILE *archivo;
    int encontrado = 0;

    // Abre el archivo en modo lectura binaria
    archivo = fopen(archivoRegistros, "rb");

    // Verifica si el archivo se abrio correctamente
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
    }

    // Leer cada registro del archivo
    while (fread(&publicacionEncontrada, sizeof(datosCadaPublicacion), 1, archivo) == 1)
    {
        // Compara el titulo del registro actual con el totulo buscado
        if (strcmp(publicacionEncontrada.datosPublicacion.titulo, tituloABuscar) == 0)
        {
            encontrado = 1;
            break; // Si se encuentra, se sale del bucle
        }
    }

    // Cierra el archivo despues de usarlo
    fclose(archivo);

    return encontrado; // Devuelve 1 si se encontro, 0 si no se encontro
}

// Funcion para mostrar el registro encontrado
void mostrarRegistro(datosCadaPublicacion registro)
{
    printf("Registro encontrado:\n");
    printf("Titulo: %s\n", registro.datosPublicacion.titulo);
    printf("Autor: %s\n", registro.datosAutor.nombreYapellido);
    printf("\n");
}

// Funcion principal que busca y muestra un registro por titulo
void buscarYMostrarPorTitulo(char archivoRegistros[], char tituloABuscar[])
{
    datosCadaPublicacion publicacionEncontrada;

    // Llama a la funcion para buscar por titulo
    if (buscarPorTitulo(archivoRegistros, tituloABuscar, publicacionEncontrada))
    {
        // Si se encontro, muestra el registro
        mostrarRegistro(publicacionEncontrada);
    }
    else
    {
        // Si no se encontro, muestra un mensaje
        printf("Registro no encontrado.\n");
    }
}

// Funcion para buscar por autor en el archivo
void mostrarPublicacionXAutor(char archivoRegistros[], char autorABuscar[])
{
    int cantVL = 0;
    datosCadaPublicacion data;

    FILE *archivo = fopen(archivoRegistros, "r+b");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        // Leer todos los datos y almacenarlos en una lista
        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(data.datosAutor.nombreYapellido, autorABuscar) == 0)
            {
                mostrarUnaPublicacion(data);
                cantVL++;
                printf("\n");

                printf("\n");
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// Funcion para buscar por fecha en el archivo
void mostrarPublicacionXFecha(char registroArchivos[], int anio1, int anio2)
{
    int cantVL = 0;
    datosCadaPublicacion data;

    FILE *archivo = fopen(registroArchivos, "r+b");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if ((data.datosPublicacion.anio > anio1) && (data.datosPublicacion.anio < anio2))
            {
                mostrarUnaPublicacion(data);
                cantVL++;
                printf("\n");
            }
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// Funcion para buscar por palabra calve en el archivo
void buscarPorPalabraClave(char archivoRegistros[], char palabraClave[])
{
    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
    }

    // Leer registros del archivo
    datosCadaPublicacion registro;

    while (fread(&registro, sizeof(datosCadaPublicacion), 1, archivo) == 1)
    {
        // Realizar la comparacion de la palabra clave con las palabras clave en la estructura
        if (((strstr(registro.palabraClave1, palabraClave) != NULL) || (strstr(registro.palabraClave2, palabraClave) != NULL)))
        {
            // Mostrar o realizar acciones con el registro que contiene la palabra clave
            printf("Palabra clave encontrada en:\n");
            printf("Titulo: %s\n", registro.datosPublicacion.titulo);
            printf("Autor: %s\n", registro.datosAutor.nombreYapellido);
            printf("\n");
        }
    }
}

// Funciones para actualizar informacion en el archivo
int buscarRegistro(char nombreArchivo[], char tituloBuscar[])
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

    return flag; // Retorna -1 si no se encontro el registro
}

void actualizarInformacionPublicacion(char nombreArchivo[], int posicion)
{
    int opcion = 0;
    datosCadaPublicacion aux;
    FILE *archivo = fopen(nombreArchivo, "r+b");

    if (archivo != NULL)
    {
        fseek(archivo, posicion * sizeof(datosCadaPublicacion), SEEK_SET); // Mueve el puntero al inicio del registro a actualizar
        fread(&aux, sizeof(datosCadaPublicacion), 1, archivo);             // Lee el registro actual

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
            break;
        case 2:
            printf("Ingrese la nueva descripcion: ");
            fflush(stdin);
            fgets(aux.datosAutor.nombreYapellido, sizeof(aux.datosAutor.nombreYapellido), stdin);
            break;
        case 3:
            printf("Ingrese el nuevo autor: ");
            fflush(stdin);
            fgets(aux.datosAutor.nombreYapellido, sizeof(aux.datosAutor.nombreYapellido), stdin);
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }

        fseek(archivo, posicion * sizeof(datosCadaPublicacion), SEEK_SET); // Mover el puntero al inicio del registro a actualizar en el archivo
        fwrite(&aux, sizeof(datosCadaPublicacion), 1, archivo);            // Escribir el registro actualizado en el archivo
        fclose(archivo);

        printf("Informacion de la publicacion actualizada exitosamente. \n");
    }
    else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }
}

///// --- FUNCIONES PARA UN AUTOR --- /////

/// --- FUNCIONES PARA AGREGAR UN AUTOR --- ///

// Funcion para registrar un nuevo autor en el archivo
void registrarNuevoAutor(char nombreArchivo[], autor nuevoAutor)
{
    // Abrir el archivo de autores en modo de escritura binaria
    FILE *archivoAutores = fopen(nombreArchivo, "ab");

    if (archivoAutores == NULL)
    {
        printf("No se pudo abrir el archivo de autores.\n");
    }

    // Buscar el autor en el archivo
    autor autorExistente;
    int encontrado = 0;

    while (fread(&autorExistente, sizeof(autor), 1, archivoAutores) == 1)
    {
        // Comparar nombres para verificar si el autor ya existe
        if (strcmp(autorExistente.nombreYapellido, nuevoAutor.nombreYapellido) == 0)
        {
            printf("El autor ya existe en el archivo.\n");
            encontrado = 1;
            break;
        }
    }

    // Si el autor no existe, agregar un nuevo registro al archivo
    if (!encontrado)
    {
        // Posicionarse al final del archivo para agregar un nuevo registro
        fseek(archivoAutores, 0, SEEK_END);

        // Escribir el nuevo autor en el archivo
        fwrite(&nuevoAutor, sizeof(autor), 1, archivoAutores);

        printf("Nuevo autor registrado con exito.\n");
    }

    // Cerrar el archivo
    fclose(archivoAutores);
}

void nuevoAutor(char archivoAutores[])
{
    autor nuevoAutor;

    // Solicitar informacion al usuario
    printf("Ingrese el nombre y apellido del nuevo autor: ");
    gets(nuevoAutor.nombreYapellido);

    printf("Ingrese la nacionalidad del nuevo autor: ");
    gets(nuevoAutor.nacionalidad);

    printf("Ingrese la biografia del nuevo autor: ");
    gets(nuevoAutor.biografia);

    // Llamar a la funcion para registrar el nuevo autor
    registrarNuevoAutor(archivoAutores, nuevoAutor);
}

/// --- FUNCIONES PARA MOSTRAR UN AUTOR --- ///

void imprimirAutor(datosCadaPublicacion autor)
{
    printf("Nombre: %s", autor.datosAutor.nombreYapellido);
    printf("Nacionalidad: %s", autor.datosAutor.nacionalidad);
    printf("Biografia: %s", autor.datosAutor.biografia);
    printf("Publicacion(es): %s", autor.datosPublicacion.titulo);
    printf("\n");
}

// Funcion de buscar un autor por nacionalidad
void mostrarDatosAutorXNacionalidad(char archivoRegistros[], char nacionalidad[])
{
    datosCadaPublicacion data;

    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(data.datosAutor.nacionalidad, nacionalidad) == 0)
            {
                imprimirAutor(data);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// Funcion de buscar un autor por nombre
void mostrarDatosAutorXNombre(char archivoRegistros[], char autorABuscar[])
{
    datosCadaPublicacion data;

    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo))
        {
            if (strcmpi(data.datosAutor.nombreYapellido, autorABuscar) == 0)
            {
                imprimirAutor(data);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// --- FUNCIONES PARA BORRAR UNA PUBLICACION --- //
// Funcion para borrar una publicacion por el nombre del autor
void borrarUnaPublicacionXAutor(char archivoRegistros[], char autorABorrar[])
{
    datosCadaPublicacion dataAux;
    FILE *archivo = fopen(archivoRegistros, "rb");
    FILE *archAux = fopen("copiaArchRegistros.bin", "wb");

    if (archivo != NULL && archAux != NULL)
    {
        while (fread(&dataAux, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(dataAux.datosAutor.nombreYapellido, autorABorrar) == 0)
            {
                fwrite(&dataAux, sizeof(datosCadaPublicacion), 1, archAux);
            }
        }

        fclose(archivo);
        fclose(archAux);

        remove(archivoRegistros);                           // Se borra el archivo viejo
        rename("copiaArchRegistros.bin", archivoRegistros); // Se renombra al nuevo archivo como al archivo original pero conservando los datos sin borrar
    }
    else
    {
        printf("Error: no se pudieron abrir los archivos. \n");
    }
}

// Funcion para borrar una publicacion por el nombre del titulo de la misma
void borrarUnaPublicacionXTitulo(char archivoRegistros[], char tituloABorrar[])
{
    datosCadaPublicacion dataAux;
    FILE *archivo = fopen(archivoRegistros, "rb");
    FILE *archAux = fopen("copiaArchRegistros.bin", "wb");

    if (archivo != NULL && archAux != NULL)
    {
        while (fread(&dataAux, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(dataAux.datosPublicacion.titulo, tituloABorrar) == 0)
            {
                fwrite(&dataAux, sizeof(datosCadaPublicacion), 1, archAux);
            }
        }

        fclose(archivo);
        fclose(archAux);

        remove(archivoRegistros);                           // Se borra el archivo viejo
        rename("copiaArchRegistros.bin", archivoRegistros); // Se renombra al nuevo archivo como al archivo original pero conservando los datos sin borrar
    }
    else
    {
        printf("Error: no se pudieron abrir los archivos. \n");
    }
}

// --- AGREGAR OPINIONES Y COMENTARIOS --- //
// Funcion para que los usuarios agreguen comentarios y calificaciones
void agregarOpinion(datosCadaPublicacion registro)
{
    // Verificar si la lista de opiniones esta inicializada
    if (registro.opiniones == NULL)
    {
        // Inicializar la lista de opiniones si no esta inicializada
        registro.opiniones = (nodo_lista_comentarios *)malloc(sizeof(nodo_lista_comentarios));
        registro.opiniones->siguiente = NULL;
    }
    else
    {
        // Agregar una nueva opinion al final de la lista
        nodo_lista_comentarios *nuevaOpinion = (nodo_lista_comentarios *)malloc(sizeof(nodo_lista_comentarios));
        nuevaOpinion->siguiente = NULL;

        // Solicitar comentarios y calificaciones al usuario
        printf("Ingrese sus comentarios: ");
        scanf(" %[^\n]", nuevaOpinion->comentarios);

        printf("Ingrese su calificacion (0 to 5): ");
        scanf("%d", &nuevaOpinion->calificacion);

        // Mostrar mensaje de exito
        printf("Opinion agregada con exito.\n");

        // Enlazar la nueva opinion al final de la lista
        nodo_lista_comentarios *actual = registro.opiniones;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevaOpinion;
    }
}

// Funcion para buscar un registro en particular por titulo
void buscarParaComentar(char archivoRegistros[], char tituloBuscado[])
{
    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
    }

    // Leer registros del archivo
    datosCadaPublicacion registro;
    int encontrado = 0;

    while (fread(&registro, sizeof(datosCadaPublicacion), 1, archivo) == 1)
    {
        // Realizar la comparacion de titulos
        if (strcmp(registro.datosPublicacion.titulo, tituloBuscado) == 0)
        {
            // Mostrar o realizar acciones con el registro encontrado
            printf("Registro encontrado:\n");
            printf("Titulo: %s\n", registro.datosPublicacion.titulo);
            printf("Autor: %s\n", registro.datosAutor.nombreYapellido);

            printf("\n");

            encontrado = 1;

            // Llamar a la funcion para agregar opiniones
            agregarOpinion(registro);

            // Salir del bucle despues de encontrar el registro
            break;
        }
    }

    if (!encontrado)
    {
        printf("Registro no encontrado.\n");
    }

    fclose(archivo);
}

// --- MOSTRAR OPINIONES --- //
//  Funcion para que los usuarios conozcan las opiniones de la comunidad
void conocerOpiniones(datosCadaPublicacion registro)
{
    // Verificar si hay opiniones
    if (registro.opiniones == NULL)
    {
        printf("No hay opiniones disponibles para esta publicacion.\n");
    }

    // Mostrar comentarios y calificaciones
    printf("Opiniones de la comunidad:\n");

    nodo_lista_comentarios *actual = registro.opiniones;

    while (actual != NULL)
    {
        printf("Comentarios: %s\n", actual->comentarios);
        printf("Calificacion: %d\n", actual->calificacion);
        printf("\n");

        actual = actual->siguiente;
    }
}