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

int preguntarCriterio(char* criterioString)
{
	char criterio;
	int retorno = -1;

	printf("'A' = Ascendente\n");
	printf("'D' = Descendente\n\n");
	printf("Ingrese el criterio de ordenamiento: ");
	fflush(stdin);
	scanf("%c", &criterio);

	while(criterio != 'a' && criterio != 'd' && criterio != 'A' && criterio != 'D')
	{
		printf("Opción errónea\n");
		printf("Ingrese el criterio de ordenamiento ('A' o 'D'): ");
		fflush(stdin);
		scanf("%c", &criterio);
	}

	if(criterio == 'a' || criterio == 'A')
	{
		retorno = 1;
	}else
	{
		retorno = 0;
	}

	if(retorno == 1)
	{
		strcpy(criterioString, "Ascendente");
	}else
	{
		strcpy(criterioString, "Descendente");
	}

	return retorno;
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
int pasajeroCompararApellido(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* passA;
		Passenger* passB;

		passA = (Passenger*) a;
		passB = (Passenger*) b;


		retorno = strcmp(passA->apellido, passB->apellido);
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
int pasajeroCompararCodigo(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* passA;
		Passenger* passB;

		passA = (Passenger*) a;
		passB = (Passenger*) b;


		retorno = strcmp(passA->codigoVuelo, passB->codigoVuelo);

	}

	return retorno;
}
int pasajeroCompararTipo(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* passA;
		Passenger* passB;

		passA = (Passenger*) a;
		passB = (Passenger*) b;

		if(passA->tipoPasajero > passB->tipoPasajero)
		{
			retorno = 1;
		}else if(passA->tipoPasajero < passB->tipoPasajero)
		{
			retorno = -1;
		}

	}

	return retorno;
}
int pasajeroCompararEstado(void* a, void* b)
{
	int retorno = 0;

	if(a != NULL && b != NULL)
	{
		Passenger* passA;
		Passenger* passB;

		passA = (Passenger*) a;
		passB = (Passenger*) b;

		if(passA->statusFlight > passB->statusFlight)
		{
			retorno = 1;
		}else if(passA->statusFlight < passB->statusFlight)
		{
			retorno = -1;
		}

	}

	return retorno;
}
