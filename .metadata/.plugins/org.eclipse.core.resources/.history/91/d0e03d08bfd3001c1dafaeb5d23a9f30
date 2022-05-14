/*
 * Menu.c
 *
 *  Created on: 28 abr. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Menu.h"

int menu()
{
	int todoOk = 0;
	int opcion;

	printf("  ***** MENÚ DE OPCIONES *****     \n\n");
	printf("Ingrese una opción del 1 al 6: \n\n");

	printf("1. ALTAS \n");
	printf("2. MODIFICAR \n");
	printf("3. BAJA \n");
	printf("4. INFORMAR \n");
	printf("5. HARDCODEAR \n\n");
	printf("6. SALIR \n\n");

	printf("Ingrese opción: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if(todoOk)
	{
		return opcion;
	}

	return todoOk;
}


int menuInformar()
{
	int todoOk = 0;
	int opcion;

	printf("\n  ***** MENÚ DE INFORMES *****     \n\n");
	printf("Ingrese una opción del 1 al 4: \n\n");
	printf("1. Pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\n");
	printf("2. Total y Promedios de los precios de los pasajes, y cantidad de pasajeros que superan el promedio\n");
	printf("3. Pasajeros ordenados por Código de vuelo y Estados de vuelos ‘ACTIVO’\n\n");
	printf("4. Salir al Menú Principal\n\n");

	printf("Ingrese opción: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if(todoOk)
	{
		return opcion;
	}

	return todoOk;
}


int menuModificar()
{
	int todoOk = 0;
	int opcion;

	printf("\n  ***** MENÚ DE MODIFICACIÓN *****     \n\n");
	printf("Ingrese una opción del 1 al 6: \n\n");
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Precio\n");
	printf("4. Código de vuelo\n");
	printf("5. Tipo de pasajero\n\n");
	printf("6. Salir\n\n");

	printf("Ingrese opción: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if(todoOk)
	{
		return opcion;
	}


	return todoOk;

}


void confirmarSalidaMenu(char* p)
{
	if(p != NULL)
	{
		char confirma;

		printf("¿Seguro que desea salir? (si = 's'  no = 'n') \n");
		fflush(stdin);
		scanf("%c", &confirma);
		confirma = tolower(confirma);

		while(confirma != 's' && confirma != 'n')
		{
			printf("Error, debe responder con 's' o 'n':  \n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
		}
		*p = confirma;
	}
}
