#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"

// Constantes para los archivos
const char archivoUsuarios[] = "Usuarios.bin";
const char archivoRegistros[] = "Registros.bin";
const char archivoHistorial[] = "Historial.bin";

int main()
{
    cargarArchivoRegistro(archivoRegistros);
    mostrarArchivoRegistro(archivoRegistros);
    system("pause");
    animacionCargando();
    menuPrincipal(archivoUsuarios);

    return 0;
}
