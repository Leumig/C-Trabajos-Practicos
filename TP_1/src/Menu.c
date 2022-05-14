/*
 * Menu.c
 *
 *  Created on: 13 abr. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Entradas.h"
#include "Calculos.h"
#include "Menu.h"

int menu(){
	int todoOk = 0;
	int opcion;

	printf("     ***** MENU DE OPCIONES *****     \n\n");
	printf("Ingrese una opción del 1 al 6: \n");

	printf("1. Ingresar kilómetros \n");
	printf("2. Ingresar precio de vuelos \n");
	printf("3. Calcular todos los costos \n");
	printf("4. Informar Resultados \n");
	printf("5. Carga forzada de datos \n");
	printf("6. Salir \n\n");

	printf("Ingrese opción: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if(todoOk)
	{
		return opcion;
	}else
	{
		return todoOk;
	}
}



int caseKilometros(int* pFlagKilometros, float* pKilometros, int* pFlagPrecios, int* pFlagCalculos)
{
	int todoOk = 0;
	if(pFlagKilometros != NULL && pKilometros != NULL && pFlagPrecios != NULL && pFlagCalculos)
	{
		int flagKilometros = 0;
		float kilometros;

		if(pedirKilometros(&flagKilometros, &kilometros) && kilometros > 0)
		{
			*pKilometros = kilometros;
			*pFlagKilometros = 1;

			printf("Los kilómetros ingresados son: %.2f \n\n", kilometros);
			*pFlagPrecios = 0;
			*pFlagCalculos = 0;
			system("pause");
		}else
		{
			printf("Error en el ingreso de kilómetros \n");
			printf("Recuerde que debe ingresar un número y que sea mayor a 0 \n\n");
			*pFlagKilometros = 0;
		}

		todoOk = 1;
	}

	return todoOk;
}



int casePrecios(int* pFlagKilometros, int* pFlagPrecios, int* pFlagCalculos, float* pPrecioAerolineas, float* pPrecioLatam)
{
	int todoOk = 0;

	if(pFlagKilometros != NULL && pFlagPrecios != NULL && pFlagKilometros != NULL && pPrecioAerolineas != NULL && pPrecioLatam != NULL)
	{
		int flagPrecios = 0;
		float precioAerolineas;
		float precioLatam;

		if(*pFlagKilometros == 0)
		{
			printf("Error, primero tendrías que ingresar los kilómetros (opción 1) \n\n");
		}else
		{
			if(pedirPrecios(&flagPrecios, &precioAerolineas, &precioLatam) && (precioAerolineas>0) && (precioLatam>0))
			{
				printf("El precio del vuelo Aerolineas ingresado es: %.2f $ \n", precioAerolineas);
				printf("El precio del vuelo Latam ingresado es: %.2f $ \n\n", precioLatam);
				*pFlagPrecios = 1;
				*pFlagCalculos = 0;

				*pPrecioAerolineas = precioAerolineas;
				*pPrecioLatam = precioLatam;
			}else
			{
				printf("Error en el ingreso de precios \n");
				printf("Recuerde que debe ingresar un número y que sea mayor a 0 \n\n");
				*pFlagPrecios = 0;
			}
		}
		system("pause");
	}

	return todoOk;
}



void informarResultados(float* pPrecioAerolineas, float* pPrecioLatam, float* pKilometros, float* pPrecioDebitoAerolineas,
float* pPrecioDebitoLatam, float* pPrecioCreditoAerolineas, float* pPrecioCreditoLatam, float* pPrecioBitcoinAerolineas,
float* pPrecioBitcoinLatam, float* pPrecioUnitarioAerolineas, float* pPrecioUnitarioLatam, float* pDiferencia)
{
	if(pPrecioAerolineas != NULL && pPrecioLatam != NULL && pKilometros != NULL && pPrecioDebitoAerolineas != NULL
	&& pPrecioDebitoLatam != NULL && pPrecioCreditoAerolineas != NULL && pPrecioCreditoLatam != NULL
	&& pPrecioBitcoinAerolineas != NULL && pPrecioBitcoinLatam != NULL && pPrecioUnitarioAerolineas != NULL
	&& pPrecioUnitarioLatam != NULL && pDiferencia != NULL)
	{
		printf("KM ingresados: %.2f km\n\n", *pKilometros);
		printf("Precio Aerolineas: $ %.2f \n", *pPrecioAerolineas);
		printf("a) Precio con tarjeta de debito: $ %.2f \n", *pPrecioDebitoAerolineas);
		printf("b) Precio con tarjeta de credito: $ %.2f \n", *pPrecioCreditoAerolineas);
		printf("c) Precio pagando con bitcoin: %.7f BTC \n", *pPrecioBitcoinAerolineas);
		printf("d) Precio unitario: $ %.2f \n\n", *pPrecioUnitarioAerolineas);

		printf("Precio Latam: $ %.2f \n", *pPrecioLatam);
		printf("a) Precio con tarjeta de debito: $ %.2f \n", *pPrecioDebitoLatam);
		printf("b) Precio con tarjeta de credito: $ %.2f \n", *pPrecioCreditoLatam);
		printf("c) Precio pagando con bitcoin: %.7f BTC \n", *pPrecioBitcoinLatam);
		printf("d) Precio unitario: $ %.2f \n\n", *pPrecioUnitarioLatam);

		printf("La diferencia de precio es: $ %.2f \n\n", *pDiferencia);
	}
}
