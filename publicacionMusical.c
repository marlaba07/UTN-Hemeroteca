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

int esBisiesto(int anio)
{
    return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

// Funcion para que un usuario ingrese el dia, mes y anio por separado
// Funcion para ingresar un dia valido
int ingresarDia()
{
    int dia;

    do
    {
        scanf("%d", &dia);

        if (dia < 1 || dia > 31)
        {
            printf("Error: El dia ingresado no es valido. Debe estar entre 1 y 31.\n");
        }

    } while (dia < 1 || dia > 31);

    return dia;
}

// Funcion para ingresar un mes valido
int ingresarMes()
{
    int mes;
    do
    {
        scanf("%d", &mes);

        if (mes < 1 || mes > 12)
        {
            printf("Error: El mes ingresado no es valido. Debe estar entre 1 y 12.\n");
        }

    } while (mes < 1 || mes > 12);

    return mes;
}

// Funcion para ingresar un anio
int ingresarAnio()
{
    int anio;
    do
    {
        scanf("%d", &anio);

        if (anio < 0 || anio > 2023)
        {
            printf("Error: El a%co ingresado no es valido. Debe ser un valor entre 0 y 2023.\n", 164);
        }

    } while (anio < 0 || anio > 2023);

    return anio;
}

void mostrarFecha(datosCadaPublicacion publicacion)
{
    // Paso 2: Formatear la fecha y mostrarla
    printf("- Fecha ingresada (con barras): %02d/%02d/%04d\n\n", publicacion.datosPublicacion.dia, publicacion.datosPublicacion.mes, publicacion.datosPublicacion.anio);
}
