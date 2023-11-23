#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "animaciones.h"
#include "arboles.h"
#include "archivos.h"
#include "Lista_De_Listas.h"
#include "menuAdministrador.h"
#include "menuPrincipal.h"
#include "menuUsuario.h"
#include "Pila_Con_Listas_PS.h"
#include "publicacionMusical.h"
#include "usuarios.h"

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

void customSleep()
{
    Sleep(300);
    system("cls");
}

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

void animacionSaliendo()
{
    printf("\n\n\n                                                 Saliendo");
    customSleep();
    printf("\n\n\n                                                 Saliendo.");
    customSleep();
    printf("\n\n\n                                                 Saliendo..");
    customSleep();
    printf("\n\n\n                                                 Saliendo...");
    customSleep();
}

void registroExitoso()
{
    system("cls");
    printf("\n\n\n");
    printf("                                           Usted se ha registrado con exito! \n");
    Sleep(1500);
    system("cls");
    animacionCargando();
}

void bienvenidaUsuario()
{
    system("cls");
    printf("\nBienvenido al menu de Usuario! \n");
    Sleep(1000);
}

void bienvenidaAdmin()
{
    system("cls");
    printf("\nBienvenido al menu de Administrador! \n");
    Sleep(1000);
}

void cerrar()
{
    printf("Cerrando...\n");
    Sleep(2000);
}

void opcionIncorrecta()
{
    printf("Opcion incorrecta. Vuelva a intentarlo. \n");
    Sleep(1000);
}

void errorRegistro()
{
    system("cls");
    printf("\n\n\n");
    printf("                                              Error: registro NO completado con exito. ");
    Sleep(1500);
    system("cls");
    animacionCargando();
}

void defaultCaseMenuPrincipal()
{
    system("cls");
    printf("\n\n                                     Opcion no valida. Debe ingresar un numero del 1 al 4. \n");
    system("pause");
    system("cls");
}

void defaultCaseMenuUsuario()
{
    system("cls");
    printf("\n\n                                     Opcion no valida. Debe ingresar un numero del 1 al 12. \n");
    system("pause");
    system("cls");
}

void defaultCaseMenuAdmin()
{
    system("cls");
    printf("\n\n                                     Opcion no valida. Debe ingresar un numero del 1 al 6. \n");
    system("pause");
    system("cls");
}

void despedida()
{
    printf("\n\n\n                                        " ROJO_F "GRACIAS POR UTILIZAR NUESTRO SERVICIO!\n" RESET_COLOR);
    printf("\n\n\n                                                  " ROJO_F "VUELVA PRONTO!\n\n" RESET_COLOR);
    system("pause");
    system("cls");
    animacionSaliendo();
}

void inicio()
{
    system("cls");
    printf("                                      _______________________________________ \n");
    printf("                                     |                                       |\n");
    printf("                                     |              BIENVENIDO               |\n");
    printf("                                     |---------------------------------------|\n");
    printf("                                     |      Elija una de las opciones:       |\n");
    printf("                                     |---------------------------------------|\n");
    printf("                                     |            1. INICIAR SESION          |\n");
    printf("                                     |            2. REGISTRARSE             |\n");
    printf("                                     |            3. SALIR                   |\n");
    printf("                                     |     4. FUNCIONES DE ADMINISTRADOR     |\n");
    printf("                                     |_______________________________________|\n");
    printf("\n\n");
}

void opcionesMenuUsuario()
{
    printf("                                      ___________________________________________________________ \n");
    printf("                                     |                                                           |\n");
    printf("                                     |                     MENU DE USUARIO                       |\n");
    printf("                                     |-----------------------------------------------------------|\n");
    printf("                                     |                 ELIJA UNA DE LAS OPCIONES                 |\n");
    printf("                                     |-----------------------------------------------------------|\n");
    printf("                                     |         1. Registrar publicacion(es).                     |\n");
    printf("                                     |         2. Buscar publicacion(es).                        |\n");
    printf("                                     |         3. Ver todas las publicaciones.                   |\n");
    printf("                                     |         4. Clasificar publicaciones por genero.           |\n");
    printf("                                     |         5. Actualizar informacion de publicacion(es).     |\n");
    printf("                                     |         6. Registro de autores.                           |\n");
    printf("                                     |         7. Busqueda de autores por nombre o nacionalidad. |\n");
    printf("                                     |         8. Comentarios y clasificaciones.                 |\n");
    printf("                                     |         9. Ver ranking de publicaciones.                  |\n");
    printf("                                     |         10. Reservar publicaciones.                       |\n");
    printf("                                     |         11. Generar recomendaciones                       |\n");
    printf("                                     |         12. Salir.                                        |\n");
    printf("                                     |___________________________________________________________|\n");
    printf("\n\n");
}

void opcionesMenuAdmin()
{
    printf("                                      ___________________________________________________________ \n");
    printf("                                     |                                                           |\n");
    printf("                                     |                  MENU DE ADMINISTRADOR                    |\n");
    printf("                                     |-----------------------------------------------------------|\n");
    printf("                                     |                ELIJA UNA DE LAS OPCIONES                  |\n");
    printf("                                     |-----------------------------------------------------------|\n");
    printf("                                     |         1. Ver todos los usuarios registrados.            |\n");
    printf("                                     |         2. Ver todas las publicaciones.                   |\n");
    printf("                                     |         3. Eliminar publicacion de usuario.               |\n");
    printf("                                     |         4. Generar informes y estadisticas.               |\n");
    printf("                                     |         5. Actualizar informacion de publicacion(es).     |\n");
    printf("                                     |         6. Salir.                                         |\n");
    printf("                                     |___________________________________________________________|");
    printf("\n\n");
}

void logo()
{
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                       :;+;;;;;;:                                                                                   ");
    printf("                   .+++++++;++++++;:                                                                                ");
    printf("                  ++++++++++++++++;;;;          .;;;;.                                                              ");
    printf("                 ++++++++++++++++++;;;;;+:.;;;;;;;;;;;;;:                                                           ");
    printf("                +++++++++++xxx++++;;;++;;;;;;;;;;;;;;;;;;;                                                          ");
    printf("              .+++++++++++&&&++++++;+++;;;;;;++;;;;;;;;;++                                                          ");
    printf("              ;+++++++++++&&&+++++++++;;++xxxxxx+;;;;;++++:     H E M E R O T E C A                                 ");
    printf("              xx++++++++++;x$+++++++++;+xXX$&&&XXx++++++++:     M U S I C A L               . .;.;;                 ");
    printf("              x+++++++++++;X$++++++++++xXX&&&&&&$XX+;xx;x++x;x+x+xxx+xxxxxxxxx+XX;X$X$$Xx&&:. .  .:&&;              ");
    printf("              x+++++++++++;x$+++++++;;+Xx&&&&&&&&&&Xx&$x&XX$+$X$X&$$x$$$&$&$$&x&$+$&$&&$x&&&&&&&&&&&&&              ");
    printf("              x+++++++++++;X$++++++++++xX+X$$&&&&$$xx$$x$XX$+$X&X&$$x$X$$X$XXX+XX+xxxxx+;&&:. :  :+&&.              ");
    printf("              xx++++++++++$&&+++++++++++xXxXX$XXXx++++x+++:                                .. .. :.                 ");
    printf("              ++++++++++++&&&++++++++++++++xXXx+++++++++++:                                                         ");
    printf("              :+++++++++++&&&+++++++++++++++++++++++++++++                                                          ");
    printf("               ++++++++++++++++++++++++++++++++++++++++++                                                           ");
    printf("                +++++++++++++++++++++++;...;+++++++++++.                                                            ");
    printf("                 ++++++++++++++++++++           ..:.                                                                ");
    printf("                  .+++xxxxxxxxxx++.                                                                                 ");
    printf("                     .;++++++;:                                                                                     ");
    printf("\n\n");
}

void logo2()
{
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                       :;+;;;;;;:                                                                                   ");
    printf("                   .+++++++;++++++;:                          _                                                     ");
    printf("                  ++++++++++++++++;;;;          .;;;;.       | |                                                    ");
    printf("                 ++++++++++++++++++;;;;;+:.;;;;;;;;;;;;;:   o  o                                                    ");
    printf("                +++++++++++xxx++++;;;++;;;;;;;;;;;;;;;;;;;                                                          ");
    printf("              .+++++++++++&&&++++++;+++;;;;;;++;;;;;;;;;++                                                          ");
    printf("              ;+++++++++++&&&+++++++++;;++xxxxxx+;;;;;++++:     H E M E R O T E C A                                 ");
    printf("              xx++++++++++;x$+++++++++;+xXX$&&&XXx++++++++:     M U S I C A L               . .;.;;                 ");
    printf("              x+++++++++++;X$++++++++++xXX&&&&&&$XX+;xx;x++x;x+x+xxx+xxxxxxxxx+XX;X$X$$Xx&&:. .  .:&&;              ");
    printf("              x+++++++++++;x$+++++++;;+Xx&&&&&&&&&&Xx&$x&XX$+$X$X&$$x$$$&$&$$&x&$+$&$&&$x&&&&&&&&&&&&&              ");
    printf("              x+++++++++++;X$++++++++++xX+X$$&&&&$$xx$$x$XX$+$X&X&$$x$X$$X$XXX+XX+xxxxx+;&&:. :  :+&&.              ");
    printf("              xx++++++++++$&&+++++++++++xXxXX$XXXx++++x+++:                                .. .. :.                 ");
    printf("              ++++++++++++&&&++++++++++++++xXXx+++++++++++:                                                         ");
    printf("              :+++++++++++&&&+++++++++++++++++++++++++++++                                                          ");
    printf("               ++++++++++++++++++++++++++++++++++++++++++                                                           ");
    printf("                +++++++++++++++++++++++;...;+++++++++++.                                                            ");
    printf("                 ++++++++++++++++++++           ..:.                                                                ");
    printf("                  .+++xxxxxxxxxx++.                                                                                 ");
    printf("                     .;++++++;:                                                                                     ");
    printf("\n\n");
}

void logo3()
{
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                     ||                                             ");
    printf("                                                                    |                                               ");
    printf("                       :;+;;;;;;:                                  o                                                ");
    printf("                   .+++++++;++++++;:                                                                                ");
    printf("                  ++++++++++++++++;;;;          .;;;;.                                                              ");
    printf("                 ++++++++++++++++++;;;;;+:.;;;;;;;;;;;;;:                                                           ");
    printf("                +++++++++++xxx++++;;;++;;;;;;;;;;;;;;;;;;;                                                          ");
    printf("              .+++++++++++&&&++++++;+++;;;;;;++;;;;;;;;;++                                                          ");
    printf("              ;+++++++++++&&&+++++++++;;++xxxxxx+;;;;;++++:     H E M E R O T E C A                                 ");
    printf("              xx++++++++++;x$+++++++++;+xXX$&&&XXx++++++++:     M U S I C A L               . .;.;;                 ");
    printf("              x+++++++++++;X$++++++++++xXX&&&&&&$XX+;xx;x++x;x+x+xxx+xxxxxxxxx+XX;X$X$$Xx&&:. .  .:&&;              ");
    printf("              x+++++++++++;x$+++++++;;+Xx&&&&&&&&&&Xx&$x&XX$+$X$X&$$x$$$&$&$$&x&$+$&$&&$x&&&&&&&&&&&&&              ");
    printf("              x+++++++++++;X$++++++++++xX+X$$&&&&$$xx$$x$XX$+$X&X&$$x$X$$X$XXX+XX+xxxxx+;&&:. :  :+&&.              ");
    printf("              xx++++++++++$&&+++++++++++xXxXX$XXXx++++x+++:                                .. .. :.                 ");
    printf("              ++++++++++++&&&++++++++++++++xXXx+++++++++++:                                                         ");
    printf("              :+++++++++++&&&+++++++++++++++++++++++++++++                                                          ");
    printf("               ++++++++++++++++++++++++++++++++++++++++++                                                           ");
    printf("                +++++++++++++++++++++++;...;+++++++++++.                                                            ");
    printf("                 ++++++++++++++++++++           ..:.                                                                ");
    printf("                  .+++xxxxxxxxxx++.                                                                                 ");
    printf("                     .;++++++;:                                                                                     ");
    printf("\n\n");
}

void logo4()
{
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                                __                                  ");
    printf("                                                                               |--                                  ");
    printf("                       :;+;;;;;;:                                             ||                                    ");
    printf("                   .+++++++;++++++;:                                          o                                     ");
    printf("                  ++++++++++++++++;;;;          .;;;;.                                                              ");
    printf("                 ++++++++++++++++++;;;;;+:.;;;;;;;;;;;;;:                                                           ");
    printf("                +++++++++++xxx++++;;;++;;;;;;;;;;;;;;;;;;;                                                          ");
    printf("              .+++++++++++&&&++++++;+++;;;;;;++;;;;;;;;;++                                                          ");
    printf("              ;+++++++++++&&&+++++++++;;++xxxxxx+;;;;;++++:     H E M E R O T E C A                                 ");
    printf("              xx++++++++++;x$+++++++++;+xXX$&&&XXx++++++++:     M U S I C A L               . .;.;;                 ");
    printf("              x+++++++++++;X$++++++++++xXX&&&&&&$XX+;xx;x++x;x+x+xxx+xxxxxxxxx+XX;X$X$$Xx&&:. .  .:&&;              ");
    printf("              x+++++++++++;x$+++++++;;+Xx&&&&&&&&&&Xx&$x&XX$+$X$X&$$x$$$&$&$$&x&$+$&$&&$x&&&&&&&&&&&&&              ");
    printf("              x+++++++++++;X$++++++++++xX+X$$&&&&$$xx$$x$XX$+$X&X&$$x$X$$X$XXX+XX+xxxxx+;&&:. :  :+&&.              ");
    printf("              xx++++++++++$&&+++++++++++xXxXX$XXXx++++x+++:                                .. .. :.                 ");
    printf("              ++++++++++++&&&++++++++++++++xXXx+++++++++++:                                                         ");
    printf("              :+++++++++++&&&+++++++++++++++++++++++++++++                                                          ");
    printf("               ++++++++++++++++++++++++++++++++++++++++++                                                           ");
    printf("                +++++++++++++++++++++++;...;+++++++++++.                                                            ");
    printf("                 ++++++++++++++++++++           ..:.                                                                ");
    printf("                  .+++xxxxxxxxxx++.                                                                                 ");
    printf("                     .;++++++;:                                                                                     ");
    printf("\n\n");
}

void logo5()
{
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                       :;+;;;;;;:                                                                                   ");
    printf("                   .+++++++;++++++;:                                                                                ");
    printf("                  ++++++++++++++++;;;;          .;;;;.                                 o  o  o                      ");
    printf("                 ++++++++++++++++++;;;;;+:.;;;;;;;;;;;;;:                               |  |  |                     ");
    printf("                +++++++++++xxx++++;;;++;;;;;;;;;;;;;;;;;;;                              |__|__|                     ");
    printf("              .+++++++++++&&&++++++;+++;;;;;;++;;;;;;;;;++                                                          ");
    printf("              ;+++++++++++&&&+++++++++;;++xxxxxx+;;;;;++++:     H E M E R O T E C A                                 ");
    printf("              xx++++++++++;x$+++++++++;+xXX$&&&XXx++++++++:     M U S I C A L               . .;.;;                 ");
    printf("              x+++++++++++;X$++++++++++xXX&&&&&&$XX+;xx;x++x;x+x+xxx+xxxxxxxxx+XX;X$X$$Xx&&:. .  .:&&;              ");
    printf("              x+++++++++++;x$+++++++;;+Xx&&&&&&&&&&Xx&$x&XX$+$X$X&$$x$$$&$&$$&x&$+$&$&&$x&&&&&&&&&&&&&              ");
    printf("              x+++++++++++;X$++++++++++xX+X$$&&&&$$xx$$x$XX$+$X&X&$$x$X$$X$XXX+XX+xxxxx+;&&:. :  :+&&.              ");
    printf("              xx++++++++++$&&+++++++++++xXxXX$XXXx++++x+++:                                .. .. :.                 ");
    printf("              ++++++++++++&&&++++++++++++++xXXx+++++++++++:                                                         ");
    printf("              :+++++++++++&&&+++++++++++++++++++++++++++++                                                          ");
    printf("               ++++++++++++++++++++++++++++++++++++++++++                                                           ");
    printf("                +++++++++++++++++++++++;...;+++++++++++.                                                            ");
    printf("                 ++++++++++++++++++++           ..:.                                                                ");
    printf("                  .+++xxxxxxxxxx++.                                                                                 ");
    printf("                     .;++++++;:                                                                                     ");
    printf("\n\n");
}

void logo6()
{
    printf("                                                                                                                    ");
    printf("                                                                                                                    ");
    printf("                                                                    ||           __                                 ");
    printf("                                                                   |            |--                                 ");
    printf("                       :;+;;;;;;:                                 o            ||                                   ");
    printf("                   .+++++++;++++++;:                          _                o                                    ");
    printf("                  ++++++++++++++++;;;;          .;;;;.       | |                       o  o  o                      ");
    printf("                 ++++++++++++++++++;;;;;+:.;;;;;;;;;;;;;:   o  o                        |  |  |                     ");
    printf("                +++++++++++xxx++++;;;++;;;;;;;;;;;;;;;;;;;                              |__|__|                     ");
    printf("              .+++++++++++&&&++++++;+++;;;;;;++;;;;;;;;;++                                                          ");
    printf("              ;+++++++++++&&&+++++++++;;++xxxxxx+;;;;;++++:     H E M E R O T E C A                                 ");
    printf("              xx++++++++++;x$+++++++++;+xXX$&&&XXx++++++++:     M U S I C A L               . .;.;;                 ");
    printf("              x+++++++++++;X$++++++++++xXX&&&&&&$XX+;xx;x++x;x+x+xxx+xxxxxxxxx+XX;X$X$$Xx&&:. .  .:&&;              ");
    printf("              x+++++++++++;x$+++++++;;+Xx&&&&&&&&&&Xx&$x&XX$+$X$X&$$x$$$&$&$$&x&$+$&$&&$x&&&&&&&&&&&&&              ");
    printf("              x+++++++++++;X$++++++++++xX+X$$&&&&$$xx$$x$XX$+$X&X&$$x$X$$X$XXX+XX+xxxxx+;&&:. :  :+&&.              ");
    printf("              xx++++++++++$&&+++++++++++xXxXX$XXXx++++x+++:                                .. .. :.                 ");
    printf("              ++++++++++++&&&++++++++++++++xXXx+++++++++++:                                                         ");
    printf("              :+++++++++++&&&+++++++++++++++++++++++++++++                                                          ");
    printf("               ++++++++++++++++++++++++++++++++++++++++++                                                           ");
    printf("                +++++++++++++++++++++++;...;+++++++++++.                                                            ");
    printf("                 ++++++++++++++++++++           ..:.                                                                ");
    printf("                  .+++xxxxxxxxxx++.                                                                                 ");
    printf("                     .;++++++;:                                                                                     ");
    printf("\n\n");
}

void logos()
{
    logo();
    Sleep(350);
    system("cls");
    logo2();
    Sleep(350);
    system("cls");
    logo3();
    Sleep(350);
    system("cls");
    logo4();
    Sleep(350);
    system("cls");
    logo5();
    Sleep(350);
    system("cls");
}