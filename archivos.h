#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

// Usuario
Usuario usuario();
void cargarArchivoUsuarios(char nombreArchivo[20]);
void mostrarArchivoUsuarios(char nombreArchivo[20]);
void mostrarUnUsuario(Usuario dato);

// Registro musical
registro registroMusical();
void cargarArchivoPublicacion(char nombreArchivo[20]);
void mostrarArchivoPublicacion(char nombreArchivo[20]);
void mostrarUnaPublicacion(registro dato);

// Registro general:
stRegistro registroGeneral();
void cargarArchivoRegistro(char nombreArchivo[20]);
void mostrarArchivoRegistro(char nombreArchivo[20]);
void mostrarUnRegistro(stRegistro dato);

#endif
