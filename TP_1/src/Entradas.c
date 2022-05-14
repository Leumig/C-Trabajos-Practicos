/*
 * Entradas.c
 *
 *  Created on: 13 abr. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Menu.h"
#include "Entradas.h"
#include "Calculos.h"

int pedirKilometros(int* pFlagKilometros, float* pKilometros){

	int todoOk = 0;

	if(pFlagKilometros != NULL && pKilometros!=NULL)
	{
		float kilometros;

		printf("Ingrese la cantidad de kilómetros: ");
		fflush(stdin);
		todoOk=scanf("%f", &kilometros);

		if(todoOk)
		{
		*pKilometros =  kilometros;
		*pFlagKilometros = 1;
		return todoOk;
		}
	}
	return todoOk;
}



int pedirPrecios(int* pPreciosFlag, float* pPreciosAerolineas, float* pPreciosLatam){

	int todoOkAerolineas = 0;
	int todoOkLatam = 0;
	int todoOk = 0;

	float precioAerolineas;
	float precioLatam;

	int flagAerolineas = 0;

	if(pPreciosFlag != NULL && pPreciosAerolineas != NULL)
	{
		printf("Ahora debera ingresar los precios de los vuelos \n\n");
		printf("Ingrese precio vuelo Aerolineas: \n");
		fflush(stdin);
		todoOkAerolineas=scanf("%f", &precioAerolineas);

		if(todoOkAerolineas && precioAerolineas > 0)
		{
			*pPreciosAerolineas =  precioAerolineas;
			flagAerolineas = 1;
		}
	}else
	{
		return todoOk;
	}

	if(pPreciosLatam!=NULL && flagAerolineas)
	{
		printf("Ingrese precio vuelo Latam: \n");
		fflush(stdin);
		todoOkLatam=scanf("%f", &precioLatam);

		if(todoOkLatam)
		{
			*pPreciosLatam =  precioLatam;
		}
	}else
	{
		return todoOk;
	}

	if(todoOkAerolineas && todoOkLatam)
	{
		todoOk = 1;
		*pPreciosFlag = 1;
	}
	return todoOk;
}



void confirmarSalida(char* p)
{
	if(p != NULL)
	{
		char confirma;

		printf("¿Confirma la salida? (si = 's'  no = 'n') \n");
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
