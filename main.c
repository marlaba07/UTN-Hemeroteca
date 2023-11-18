#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animaciones.h"
#include "menuPrincipal.h"
#include "usuarios.h"
#include "archivos.h"

// Constantes para los archivos
const char archivoUsuarios[] = "Usuarios.bin";

int main()
{
    animacionCargando();
    logo();
    system("pause");
    menuPrincipal(archivoUsuarios);

    return 0;
}
