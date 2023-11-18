#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

typedef struct
{
    int id;
    int categoria; //1 - Personal, 2 - Usuario normal. Dependiendo del tipo de usuario, se concederan unos u otros permisos. [Preguntar si es necesario]
    // Para mi en categoria deberiamos decir que un solo usuario en particular es de categoria 1 [personal/administrador] y el resto son de usuario 2.
    char nombreCompleto[30];
    char mail[50];
    char contrasenia[8];
} Usuario;

typedef struct
{
    // Preguntar que se tiene que guardar en el historial.
    // [Agregue campos por agregar, pueden ser otros tranquilamente]
    int idLibro;
    char nombreLibro[20];
    char genero[20];
    char descripcion[100];
} Historial;

typedef struct
{
    Historial registros;
    struct nodoHistorial* sig;
    struct nodoHistorial* ant;
} nodoHistorial;    // Deberian pasarse informacion relevante como libros, o lo que sea que se quiera guardar en el historial.

typedef struct
{
    // Hice la lista de usuarios como lista simple pero podría hacerse como lista doble qsya
    Usuario datosLogin;
    nodoHistorial* listaHistorial;
    struct nodoListaUsuario* sig;
} nodoListaUsuario;

nodoListaUsuario* inicListaUsuario();
nodoListaUsuario* crearNodoUsuario(Usuario dato);
nodoListaUsuario* agregarPrincipioUsuario(nodoListaUsuario* lista, nodoListaUsuario* nuevoNodo);
nodoListaUsuario* cargarUsuario(char nombreArchivo[30], nodoListaUsuario* lista);
nodoListaUsuario* altaUsuario(nodoListaUsuario* lista, Usuario dato);
nodoListaUsuario* buscarUsuario(nodoListaUsuario* lista, int id);
nodoListaUsuario* buscarUsuarioPorEmail(nodoListaUsuario* lista, char correo[30]);
nodoListaUsuario* menuUsuario(nodoListaUsuario* usuarioEncontrado, nodoListaUsuario* lista, char archivoUsuarios[]);

#endif
