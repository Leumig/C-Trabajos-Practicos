/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* nuevoPasajero = (Passenger*) calloc(1,sizeof(Passenger));

	return nuevoPasajero;
}
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,
								   char* codigoVueloStr, char* tipoPasajeroStr, char* statusFlightStr)
{
	Passenger* nuevoPasajero = Passenger_new();

	if(nuevoPasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL
			         && codigoVueloStr != NULL && tipoPasajeroStr != NULL && statusFlightStr)
	{
		if(!(Passenger_setId(nuevoPasajero, atoi(idStr)) &&
			Passenger_setNombre(nuevoPasajero, nombreStr) &&
			Passenger_setApellido(nuevoPasajero, apellidoStr) &&
			Passenger_setPrecio(nuevoPasajero, atof(precioStr)) &&
			Passenger_setTipoPasajero(nuevoPasajero, atoi(tipoPasajeroStr)) &&
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr) &&
			Passenger_setStatusFlight(nuevoPasajero, atoi(statusFlightStr))))
		{
			Passenger_delete(nuevoPasajero);
			nuevoPasajero = NULL;
		}
	}
	return nuevoPasajero;
}

void Passenger_delete(Passenger* e)
{
	free(e);
}


int Passenger_setId(Passenger* e, int id)
{
    int todoOk = 0;
    if(e != NULL && id > 0)
    {
        e->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getId(Passenger* e, int* id)
{
    int todoOk = 0;

    if(e != NULL && id != NULL)
    {
        *id = e->id;
        todoOk = 1;
    }

    return todoOk;
}


int Passenger_setNombre(Passenger* e, char* nombre)
{
    int todoOk = 0;
    if(e != NULL && nombre != NULL && strlen(nombre) < 20 && strlen(nombre) > 1)
    {
        strcpy(e->nombre, nombre);
        strlwr(e->nombre);
        (e->nombre)[0] = toupper((e->nombre)[0]);

        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getNombre(Passenger* e, char* nombre)
{
    int todoOk = 0;

    if(e != NULL && nombre != NULL)
    {
        strcpy(nombre, e->nombre);
        todoOk = 1;
    }

    return todoOk;
}


int Passenger_setApellido(Passenger* e, char* apellido)
{
    int todoOk = 0;
    if(e != NULL && apellido != NULL && strlen(apellido) < 20 && strlen(apellido) > 1)
    {
        strcpy(e->apellido, apellido);
        strlwr(e->apellido);
        (e->apellido)[0] = toupper((e->apellido[0]));
        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getApellido(Passenger* e, char* apellido)
{
    int todoOk = 0;

    if(e != NULL && apellido != NULL)
    {
        strcpy(apellido, e->apellido);
        todoOk = 1;
    }

    return todoOk;
}


int Passenger_setCodigoVuelo(Passenger* e, char* codigoVuelo)
{
	int todoOk = 0;
    if(e != NULL && codigoVuelo != NULL)
    {
        strcpy(e->codigoVuelo, codigoVuelo);
        strlwr(e->codigoVuelo);
        todoOk = 1;
    }

	return todoOk;
}
int Passenger_getCodigoVuelo(Passenger* e, char* codigoVuelo)
{
	int todoOk = 0;

    if(e != NULL && codigoVuelo != NULL)
    {
        strcpy(codigoVuelo, e->codigoVuelo);
        codigoVuelo = strupr(codigoVuelo);
        todoOk = 1;
    }

	return todoOk;
}


int Passenger_setTipoPasajero(Passenger* e, int tipoPasajero)
{
	int todoOk = 0;

    if(e != NULL && tipoPasajero >= 0 && tipoPasajero <= 5)
    {
        e->tipoPasajero = tipoPasajero;
        todoOk = 1;
    }

	return todoOk;
}
int Passenger_getTipoPasajero(Passenger* e, int* tipoPasajero)
{
	int todoOk = 0;

    if(e != NULL && tipoPasajero != NULL)
    {
        *tipoPasajero = e->tipoPasajero;
        todoOk = 1;
    }

	return todoOk;
}
int Passenger_getTipoPasajeroString(Passenger* e, char* tipoPasajero)
{
	int todoOk = 0;

    if(e != NULL && tipoPasajero != NULL)
    {
    	switch(e->tipoPasajero)
		{
		case 1:
			strcpy(tipoPasajero, "ExecutiveClass");
			break;
		case 2:
			strcpy(tipoPasajero, "FirstClass");
			break;
		default:
			strcpy(tipoPasajero, "EconomyClass");
			break;
		}
        todoOk = 1;
    }

	return todoOk;
}


int Passenger_setPrecio(Passenger* e, float precio)
{
    int todoOk = 0;

    if(e != NULL && precio > 5000)
    {
        e->precio = precio;
        todoOk = 1;
    }

    return todoOk;
}
int Passenger_getPrecio(Passenger* e, float* precio)
{
	int todoOk = 0;

    if(e != NULL && precio != NULL)
    {
        *precio = e->precio;
        todoOk = 1;
    }

    return todoOk;
}


int Passenger_setStatusFlight(Passenger* e, int statusFlight)
{
	int todoOk = 0;

    if(e != NULL && statusFlight >= 0 && statusFlight <= 4)
    {
        e->statusFlight = statusFlight;
        todoOk = 1;
    }

	return todoOk;
}
int Passenger_getStatusFlight(Passenger* e, int* statusFlight)
{
	int todoOk = 0;

    if(e != NULL && statusFlight != NULL)
    {
        *statusFlight = e->statusFlight;
        todoOk = 1;
    }

	return todoOk;
}
int Passenger_getStatusFlightString(Passenger* e, char* statusFlight)
{
	int todoOk = 0;

    if(e != NULL && statusFlight != NULL)
    {
    	switch(e->statusFlight)
    	{
    	case 1:
    		strcpy(statusFlight, "Aterrizado");
    		break;
    	case 2:
    		strcpy(statusFlight, "En Vuelo");
    		break;
    	case 3:
    		strcpy(statusFlight, "En Horario");
    		break;
    	default:
    		strcpy(statusFlight, "Demorado");
    		break;
    	}
        todoOk = 1;
    }
	return todoOk;
}
