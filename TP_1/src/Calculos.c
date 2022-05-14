/*
 * Calculos.c
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

int calcularAerolineas(float* pPrecio, float* pCostoDebito, float* pCostoCredito, float* pCostoBitcoin, float* pPrecioUnitario, float* pKilometros)
{
	int todoOk = 0;

	if(pPrecio != NULL && pCostoDebito != NULL && pCostoCredito != NULL && pCostoBitcoin != NULL && pPrecioUnitario != NULL && pKilometros != NULL)
	{
		float kilometros;
		float precioAerolineas;

		float precioDebito;
		float precioCredito;
		float precioBitcoin;
		float precioUnitario;


		precioAerolineas = *pPrecio;
		precioUnitario = *pPrecioUnitario;
		kilometros = *pKilometros;


		calcularDebito(&precioAerolineas, &precioDebito);
		*pCostoDebito = precioDebito;

		calcularCredito(&precioAerolineas, &precioCredito);
		*pCostoCredito = precioCredito;

		calcularBitcoin(&precioAerolineas, &precioBitcoin);
		*pCostoBitcoin = precioBitcoin;

		calcularPrecioUnitario(&precioAerolineas, &precioUnitario, &kilometros);
		*pPrecioUnitario = precioUnitario;

		todoOk = 1;
	}

	return todoOk;
}



int calcularLatam(float* pPrecio, float* pCostoDebito, float* pCostoCredito, float* pCostoBitcoin, float* pPrecioUnitario, float* pKilometros)
{
	int todoOk = 0;

	if(pPrecio != NULL && pCostoDebito != NULL && pCostoCredito != NULL && pCostoBitcoin != NULL && pPrecioUnitario != NULL && pKilometros != NULL)
	{
		float kilometros;
		float precioLatam;

		float precioDebito;
		float precioCredito;
		float precioBitcoin;
		float precioUnitario;

		precioLatam = *pPrecio;
		kilometros = *pKilometros;


		calcularDebito(&precioLatam, &precioDebito);
		*pCostoDebito = precioDebito;

		calcularCredito(&precioLatam, &precioCredito);
		*pCostoCredito = precioCredito;

		calcularBitcoin(&precioLatam, &precioBitcoin);
		*pCostoBitcoin = precioBitcoin;

		calcularPrecioUnitario(&precioLatam, &precioUnitario, &kilometros);
		*pPrecioUnitario = precioUnitario;

		todoOk = 1;
	}

	return todoOk;
}



int calcularDebito(float* pPrecio, float* pCostoDebito)
{
	int todoOk = 0;

	if(pPrecio != NULL && pCostoDebito != NULL)
	{
		float descuento;
		float precio;

		precio = *pPrecio;

		descuento = (float) ( precio * 10 ) / 100;
		precio = precio - descuento;

		*pCostoDebito = precio;

		todoOk = 1;
	}

	return todoOk;
}

int calcularCredito(float* pPrecio, float* pCostoCredito)
{
	int todoOk = 0;

	if(pPrecio != NULL && pCostoCredito != NULL)
	{
		float aumento;
		float precio;

		precio = *pPrecio;

		aumento = (float) ( precio * 25 ) / 100;
		precio = precio + aumento;

		*pCostoCredito = precio;

		todoOk = 1;
	}

	return todoOk;
}



int calcularBitcoin(float* pPrecio, float* pCostoBitcoin)
{
	int todoOk = 0;

	if(pPrecio != NULL && pCostoBitcoin != NULL)
	{
		float precio;
		float precioBitcoin;

		precio = *pPrecio;

		precioBitcoin = (float) (1 * precio) / 4606954.55;

		*pCostoBitcoin = precioBitcoin;

		todoOk = 1;
	}

	return todoOk;
}

int calcularPrecioUnitario(float* pPrecio, float* pPrecioUnitario, float* pKilometros)
{
	int todoOk = 0;

	if(pPrecio != NULL && pPrecioUnitario != NULL && pKilometros != NULL)
	{
		float precio;
		float kilometros;
		float precioUnitario;


		precio = *pPrecio;

		kilometros = *pKilometros;

		precioUnitario = (float) precio / kilometros;


		*pPrecioUnitario = precioUnitario;

		todoOk = 1;
	}

	return todoOk;
}



int calcularDiferencia(float* pPrecioAerolineas, float* pPrecioLatam, float* pDiferencia)
{
	int todoOk = 0;

	if(pPrecioAerolineas != NULL && pPrecioLatam != NULL && pDiferencia != NULL)
	{
		float precioAerolineas;
		float precioLatam;
		float diferencia;

		precioAerolineas = *pPrecioAerolineas;
		precioLatam = *pPrecioLatam;

		if(precioAerolineas>=precioLatam)
			{
				diferencia = (float) precioAerolineas - precioLatam;
			}else
			{
				diferencia = (float) precioLatam - precioAerolineas;
			}

		*pDiferencia = diferencia;

		todoOk = 1;
	}

	return todoOk;
}
