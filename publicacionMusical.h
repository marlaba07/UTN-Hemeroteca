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


stRegistro registroMusical();
void mostrarUnRegistro(stRegistro dato);

#endif
