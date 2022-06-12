/*
 * Passenger_ABM.c
 *
 *  Created on: 11 jun. 2022
 *      Author: JUNMI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"

int mostrarPasajero(Passenger* e)
{
    int todoOk = 0;

    if(e != NULL)
    {
    	int id;
    	char nombre[20];
    	char apellido[20];
    	char codigoVuelo[20];
    	float precio;
    	char tipoPasajeroString[20];
    	char statusFlightString[20];

    	if(Passenger_getId(e, &id) &&
			Passenger_getNombre(e, nombre) &&
			Passenger_getApellido(e, apellido) &&
			Passenger_getTipoPasajeroString(e, tipoPasajeroString) &&
			Passenger_getCodigoVuelo(e, codigoVuelo) &&
			Passenger_getPrecio(e, &precio) &&
			Passenger_getStatusFlightString(e, statusFlightString))
    	{
    		printf("%4d%15s       %15s        %9.2f     %15s       %17s         %17s\n",
    				id, nombre, apellido, precio, codigoVuelo, tipoPasajeroString, statusFlightString);
            todoOk = 1;
    	}

    }
    return todoOk;
}

Passenger* Passenger_newParametrosAdd(int id, char* nombre, char* apellido, float precio,
								   char* codigoVuelo, int tipoPasajero, int statusFlight)
{
	Passenger* nuevoPasajero = Passenger_new();

	if(nuevoPasajero != NULL)
	{
		if(!(Passenger_setId(nuevoPasajero, id) &&
			Passenger_setNombre(nuevoPasajero, nombre) &&
			Passenger_setApellido(nuevoPasajero, apellido) &&
			Passenger_setPrecio(nuevoPasajero, precio) &&
			Passenger_setTipoPasajero(nuevoPasajero, tipoPasajero) &&
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVuelo) &&
			Passenger_setStatusFlight(nuevoPasajero, statusFlight)))
		{
			printf("Ocurrió un problema en el Setting de los campos\n");
			Passenger_delete(nuevoPasajero);
			nuevoPasajero = NULL;
		}
	}

	return nuevoPasajero;
}
int buscarPasajeroPorID(LinkedList* pArrayListPassenger, int len, int id)
{
	int indice = -1;
	int idEncontrado;

	Passenger* pass = NULL;

	if(pArrayListPassenger != NULL && len > 0 && id > 0)
	{
		for(int i = 0; i < len; i++)
		{
			pass = ll_get(pArrayListPassenger, i);

			if(pass!=NULL)
			{
				Passenger_getId(pass, &idEncontrado);

				if(idEncontrado == id)
				{
					indice = i;
				}

			}
		}
	}

	return indice;
}
