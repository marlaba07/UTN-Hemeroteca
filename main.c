#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

#include "animaciones.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"
#include "Lista_De_Listas.h"
#include "arboles.h"
#include "menuPrincipal.h"

int main()
{
    // Constantes para los archivos
    char archivoUsuarios[20] = "Usuarios.bin";
    char archivoRegistros[20] = "Registros.bin";

    animacionCargando();
    menuPrincipal(archivoUsuarios);

    return 0;
}
