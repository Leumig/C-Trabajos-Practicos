/*
 * Passenger.c
 *
 *  Created on: 17 jun. 2022
 *      Author: JUNMI
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
Passenger* Passenger_newParametros(int id, char* nombre, float precio)
{
	Passenger* nuevoPasajero = Passenger_new();

	if(nuevoPasajero != NULL && id > 0 && nombre != NULL && precio > 0)
	{
		if(!(Passenger_setId(nuevoPasajero, id) &&
			Passenger_setNombre(nuevoPasajero, nombre) &&
			Passenger_setPrecio(nuevoPasajero, precio)))
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



int pasajeroCompararId(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* passA;
		Passenger* passB;

		passA = (Passenger*) a;
		passB = (Passenger*) b;

		if(passA->id > passB->id)
		{
			retorno = 1;
		}else if(passA->id < passB->id)
		{
			retorno = -1;
		}
	}
	return retorno;
}
int pasajeroCompararNombre(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* passA;
		Passenger* passB;

		passA = (Passenger*) a;
		passB = (Passenger*) b;


		retorno = strcmp(passA->nombre, passB->nombre);

	}
	return retorno;
}
int pasajeroCompararPrecio(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* passA;
		Passenger* passB;

		passA = (Passenger*) a;
		passB = (Passenger*) b;

		if(passA->precio > passB->precio)
		{
			retorno = 1;
		}else if(passA->precio < passB->precio)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int mostrarPasajero(Passenger* e)
{
    int todoOk = 0;

    if(e != NULL)
    {
    	int id;
    	char nombre[20];
    	float precio;

    	if(Passenger_getId(e, &id) &&
			Passenger_getNombre(e, nombre) &&
			Passenger_getPrecio(e, &precio))
    	{
    		printf("%2d%15s      %9.2f\n", id, nombre, precio);
            todoOk = 1;
    	}
    }
    return todoOk;
}
int listarPasajeros(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger != NULL)
	{
		Passenger* auxPass = NULL;
		int flag = 0;

		printf("     *** Listado de Pasajeros ***\n\n");
		printf(" ID        Nombre         Precio     \n");
		printf("------------------------------------\n");
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPass = (Passenger*) ll_get(pArrayListPassenger, i);
			if(auxPass != NULL)
			{
				mostrarPasajero(auxPass);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("       No hay pasajeros cargados\n\n");
		}

	}

    return 1;
}
