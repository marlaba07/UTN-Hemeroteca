#ifndef PUBLICACIONMUSICAL_H_INCLUDED
#define PUBLICACIONMUSICAL_H_INCLUDED

typedef struct
{
    char titulo[30];
    char genero[30];
    char fechaPublicacion[100];
    char nombreYapellidoAutor[20];
    char nacionalidad[30];
    char biografia[100];
} stRegistro;

typedef struct
{
    stRegistro registro;
    int idRegistro;
    char fuente[30];
    char descripcion[100];
    char etiquetado[20];
    int prestado;   // 1 (esta prestado) - 0 (no esta prestado)
} registro;



#endif
