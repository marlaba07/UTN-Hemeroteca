#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

// Usuario
Usuario cargarDatosUnUsuario();
void cargarArchivoUsuarios(char nombreArchivo[20]);
void mostrarArchivoUsuarios(char nombreArchivo[20]);
void mostrarUnUsuario(Usuario dato);

// Registro musical
datosCadaPublicacion pedirDatosRegistro();
void cargarArchivoPublicacion(char nombreArchivo[20]);
void mostrarUnaPublicacion(datosCadaPublicacion dato);
void mostrarArchivoPublicacion(char nombreArchivo[20]);

// Funciones de mostrado
int buscarPorTitulo(char archivoRegistros[], char tituloABuscar[], datosCadaPublicacion publicacionEncontrada);
void mostrarRegistro(datosCadaPublicacion registro);
void buscarYMostrarPorTitulo(char archivoRegistros[], char tituloABuscar[]);
void mostrarPublicacionXAutor(char archivoRegistros[], char autorABuscar[]);
void mostrarPublicacionXFecha(char registroArchivos[], int anio1, int anio2);
void buscarPorPalabraClave(char archivoRegistros[], char palabraClave[]);
void actualizarInformacionPublicacion(char nombreArchivo[], int posicion);
int buscarRegistro(char nombreArchivo[], char tituloBuscar[]);
void registrarNuevoAutor(char nombreArchivo[], autor nuevoAutor);
void nuevoAutor(char archivoAutores[]);
void imprimirAutor(datosCadaPublicacion autor);
void mostrarDatosAutorXNacionalidad(char archivoRegistros[], char nacionalidad[]);
void mostrarDatosAutorXNombre(char archivoRegistros[], char autorABuscar[]);
void borrarUnaPublicacionXAutor(char archivoRegistros[], char autorABorrar[]);
void borrarUnaPublicacionXTitulo(char archivoRegistros[], char tituloABorrar[]);
void agregarOpinion(datosCadaPublicacion registro);
void buscarParaComentar(char archivoRegistros[], char tituloBuscado[]);
void conocerOpiniones(datosCadaPublicacion registro);
#endif
