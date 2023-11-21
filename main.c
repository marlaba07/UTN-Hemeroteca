#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char archivoRegistros[20] = "Registros.bin";
    char archivoUsuarios[20] = "Usuarios.bin";

    animacionCargando();
    // logos();
    // logo6();
    system("pause");
    system("cls");
    menuPrincipal(archivoUsuarios, archivoRegistros);

    return 0;
}
