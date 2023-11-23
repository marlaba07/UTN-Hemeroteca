#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Usuario
Usuario cargarDatosUnUsuario();
Usuario cargarDatosUnAdmin(char contraAdmin[]);
void cargarArchivoUsuarios(char archivoUsuarios[]);
int comprobarExistenciaIDUsuario(FILE *archivo, int i);
void cargarArchivoUsuariosAdmins(char archivoUsuarios[], char contraAdmin[]);
void mostrarArchivoUsuarios(char archivoUsuarios[]);
void mostrarUnUsuario(Usuario dato);

// Registro musical
datosCadaPublicacion pedirDatosRegistro();
void cargarArchivoPublicacion(char archivoRegistros[]);
void mostrarUnaPublicacion(datosCadaPublicacion dato);
void mostrarArchivoPublicacion(char archivoRegistros[]);

// Funciones de mostrado
int buscarPorTitulo(char archivoRegistros[], char tituloABuscar[], datosCadaPublicacion publicacionEncontrada);
void mostrarRegistro(datosCadaPublicacion registro);
void mostrarPublicacionXTitulo(lista_de_listas *listaPublicaciones, char tituloABuscar[]);
void mostrarPublicacionXAutor(lista_de_listas *listaPublicaciones, char autorABuscar[]);
void mostrarPublicacionXFecha(lista_de_listas *listaPublicaciones, int anio1, int anio2);
void mostrarPublicacionXPalabraClave(lista_de_listas *listaPublicaciones, char palabraClave[]);
void actualizarInformacionPublicacion(char nombreArchivo[], int posicion);
int buscarRegistro(char nombreArchivo[], char tituloBuscar[]);
void registrarNuevoAutor(char nombreArchivo[], autor nuevoAutor);
void nuevoAutor(char archivoAutores[]);
void imprimirAutor(datosCadaPublicacion autor);
void mostrarDatosAutorXNacionalidad(char archivoRegistros[], char nacionalidad[]);
void mostrarDatosAutorXNombre(char archivoRegistros[], char autorABuscar[]);
int borrarUnaPublicacionXAutor(char archivoRegistros[], char autorABorrar[]);
int borrarUnaPublicacionXTitulo(char archivoRegistros[], char tituloABorrar[]);
void agregarOpinion(datosCadaPublicacion registro);
void buscarParaComentar(char archivoRegistros[], char tituloBuscado[]);
void conocerOpiniones(datosCadaPublicacion registro);

#endif
