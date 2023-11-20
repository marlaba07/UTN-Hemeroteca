#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

// Usuario
Usuario cargarDatosUnUsuario();
void cargarArchivoUsuarios(char nombreArchivo[20]);
void mostrarArchivoUsuarios(char nombreArchivo[20]);
void mostrarUnUsuario(Usuario dato);

// Registro musical
datosCadaPublicacion registroMusical();
void cargarArchivoPublicacion(char nombreArchivo[20]);
void mostrarUnaPublicacion(datosCadaPublicacion dato);
void mostrarArchivoPublicacion(char nombreArchivo[20]);
void actualizarInformacionPublicacion(char nombreArchivo[20]);
int buscarRegistro(char nombreArchivo[20], char tituloBuscar[50]);

#endif
