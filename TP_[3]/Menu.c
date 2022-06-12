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
	printf("Ingrese una opción del 1 al 10: \n\n");

	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario). \n");
	printf("3. Alta de pasajero \n");
	printf("4. Modificar datos de pasajero \n");
	printf("5. Baja de pasajero \n");
	printf("6. Listar pasajeros \n");
	printf("7. Ordenar pasajeros \n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario). \n\n");

	printf("10. Salir \n\n");

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
