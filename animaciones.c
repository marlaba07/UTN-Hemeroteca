#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animaciones.h"

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
