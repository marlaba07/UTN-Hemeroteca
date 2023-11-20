#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "animaciones.h"
#include "menuPrincipal.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "usuarios.h"
#include "archivos.h"
#include "publicacionMusical.h"

void animacionCargando()
{
    printf("\n\n\n                                                 Cargando");
    customSleep();
    printf("\n\n\n                                                 Cargando.");
    customSleep();
    printf("\n\n\n                                                 Cargando..");
    customSleep();
    printf("\n\n\n                                                 Cargando...");
    customSleep();
}

void customSleep()
{
    Sleep(300);
    system("cls");
}

void registroExitoso()
{
    system("cls");
    printf("\n\n\n");
    printf("                                           Usted se registro con exito! \n");
    Sleep(1500);
    system("cls");
    animacionCargando();
}

void bienvenidaUsuario()
{
    system("cls");
    printf("\nBienvenido al menu de usuario! \n");
    Sleep(1000);
}

void bienvenidaAdmin()
{
    system("cls");
    printf("\nbienvenido al menu de administrador...\n");
    Sleep(1000);
}

void cerrar()
{
    printf("Cerrando...\n");
    Sleep(2000);
}

void opcionIncorrecta()
{
    printf("Opcion incorrecta vuelva a intentarlo \n");
    Sleep(1000);
}

void errorRegistro()
{
    system("cls");
    printf("\n\n\n");
    printf("                                              Usted no se registro correctamente! ");
    Sleep(1500);
    system("cls");
    animacionCargando();
}

void opcionesMenuUsuario()
{
    printf("1. Registrar publicacion. \n");
    printf("2. Buscar publicacion. \n");
    printf("3. Mostrar detalle de publicacion. \n");
    printf("4. Clasificar por genero. \n");
    printf("5. Mostrar publicacion por fecha. \n");
    printf("6. Mostrar publicacion por fuente. \n");
    printf("7. Mostrar publicaciones mas populares. \n");
    printf("8. Actualizar informacion de publicaciones. \n");
    printf("9. Registro de autores. \n");
    printf("10. Busqueda de autores por nombre o nacionalidad. \n");
    printf("11. Mostrar detalles de un autor. \n");
    printf("12. Buscar por palabra clave \n");
    printf("13. Comentarios y clasificaciones. \n");
    printf("14. Reservar publicaciones. \n");
    printf("0.  Salir. \n");
}
