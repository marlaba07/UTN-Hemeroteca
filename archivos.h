#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

// Usuario
Usuario usuario();
void cargarArchivoUsuarios(char nombreArchivo[20]);
void mostrarArchivoUsuarios(char nombreArchivo[20]);
void mostrarUnUsuario(Usuario dato);

// Registro
void cargarArchivoRegistro(char nombreArchivo[20]);
void mostrarArchivoRegistro(char nombreArchivo[20]);

#endif
