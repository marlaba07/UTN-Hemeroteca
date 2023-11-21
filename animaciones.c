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
    printf("                                           Usted se ha registrado con exito! \n");
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

void opcionesMenuUsuario()
{
    printf("1. Registrar publicacion(es). \n");
    printf("2. Buscar publicacion(es). \n");
    printf("3. Mostrar detalles de publicacion(es). \n");
    printf("4. Clasificar publicaciones por genero. \n");
    printf("8. Actualizar informacion de publicacion(es). \n");
    printf("9. Registro de autores. \n");
    printf("10. Busqueda de autores por nombre o nacionalidad. \n");
    printf("11. Mostrar detalles de un autor. \n");
    printf("12. Comentarios y clasificaciones. \n");
    printf("13. Reservar publicaciones. \n");
    printf("0.  Salir. \n");
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