#ifndef PUBLICACIONMUSICAL_H_INCLUDED
#define PUBLICACIONMUSICAL_H_INCLUDED

// INFORMACION QUE SE GUARDA EN ARCHIVO "REGISTROS.BIN"
typedef struct
{
    char nombreYapellido[20];
    char nacionalidad[30];
    char biografia[250];
} autor;

typedef struct
{
    char titulo[30];
    char genero[30];
    int dia;
    int mes;
    int anio;
    char descripcion[250];
} publicacionMusical;

typedef struct nodo_lista_comentarios
{
    char comentarios[250];
    int calificacion; // 0 to 5.
    struct nodo_lista_comentarios *siguiente;
} nodo_lista_comentarios;

typedef struct
{
    autor datosAutor;
    publicacionMusical datosPublicacion;
    char palabraClave1[20];
    char palabraClave2[20];
    int prestado;       // 0 o 1
    int cantVecesLeida; // contador de las veces leidas
    char fuente[30];
    nodo_lista_comentarios *opiniones;
} datosCadaPublicacion;

int esBisiesto(int anio);
int ingresarDia();
int ingresarMes();
int ingresarAnio();
void mostrarFecha(datosCadaPublicacion publicacion);

#endif
