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


void animacionCargando()
{
    printf("\n\n\n                                                 Cargando");
    sleep();
    printf("\n\n\n                                                 Cargando.");
    sleep();
    printf("\n\n\n                                                 Cargando..");
    sleep();
    printf("\n\n\n                                                 Cargando...");
    sleep();
}

void sleep()
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
    inicio();
}

void opcionesMenuUsuario()
{
    printf("\n1. Registrar publicacion ");
    printf("\n2. Buscar publicacion ");
    printf("\n3. Mostrar detalle de publicacion ");
    printf("\n4. Clasificar por genero ");
    printf("\n5. Mostrar publicacion por fecha ");
    printf("\n5. Mostrar publicacion por fuente ");
    printf("\n6. Mostrar publicaciones mas populares ");
    printf("\n7. Guardar y cargar publicaciones ");
    printf("\n8. Actualizar informacion de publicaciones ");
    printf("\n9. Elimianr publicaciones ");
    printf("\n10. Registro de autores ");
    printf("\n11. Busqueda de autores ");
    printf("\n12. Mostrar detalles de un autor ");
    printf("\n13. Generar informes ");
    printf("\n14. Etiquetado de publicaciones ");
    printf("\n15. Comentarios y clasificaciones ");
    printf("\n16. Recomendaciones personalizadas ");
    printf("\n17. Reservar publicaciones ");
    printf("\n18. Gestion de prestamos ");
    printf("\n0 . Salir \n");
}








