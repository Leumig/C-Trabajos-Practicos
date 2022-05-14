/*
 * ArrayPassenger.c
 *
 *  Created on: 6 may. 2022
 *      Author: JUNMI
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Validaciones.h"

#define LEN 5

int initPassengers(Passenger* list, int len)
{
	int todoOk = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}

		todoOk = 1;
	}

	return todoOk;
}


int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int todoOk = 0;
	int index;
	Passenger nuevoPasajero[LEN];

	if(list != NULL && len > 0 && id > 0 && name != NULL
	&& lastName != NULL  && flycode != NULL)
	{
		if(findFreePassenger(list, len, &index))
		{
			if(index==-1)
			{
				printf("No hay más lugar en el sistema\n");
			}else
			{
				char nombre[100];
				char apellido[100];
				char codigo[100];
				int validarPrecio = 0;
				float precio = 0;
				int validTipo = 0;
				int tipo = 0;
				int status = 0;

				printf("Ingrese el nombre del pasajero: ");
				fflush(stdin);
				gets(nombre);
				validarPalabra(nombre);
				strcpy(nuevoPasajero->name, nombre);


				printf("Ingrese el apellido del pasajero: ");
				fflush(stdin);
				gets(apellido);
				validarPalabra(apellido);
				strcpy(nuevoPasajero->lastName, apellido);


				printf("\nIngrese precio: ");
				validarPrecio = scanf("%f", &precio);
				validarFloat(validarPrecio, &precio);
				nuevoPasajero->price = precio;


				printf("\nCódigo de vuelo\n");
				printf("Recuerde que debe tener 10 dígitos y empezar con 'A', 'B', o 'C'\n\n");
				printf("Ingrese código: ");
				fflush(stdin);
				gets(codigo);
				validarCodigoYStatus(codigo, &status);
                strcpy(nuevoPasajero->flycode, codigo);

                printf("\nAclaración: Todos los vuelos de las líneas 'B' se encuentran inactivos\n");
                printf("Aclaración: Todos los vuelos de las líneas 'C' se encuentran demorados\n");

                system("pause");

				printf("\n\nTipos de pasajero \n\n");
				printf("1. VIP \n");
				printf("2. Standard \n");
				printf("3. General \n\n");
				printf("Seleccione su tipo: ");
				validTipo = scanf("%d", &tipo);
				validarTipo(validTipo, &tipo);
				nuevoPasajero->typePassenger = tipo;

				nuevoPasajero->statusFlight = status;

				nuevoPasajero->isEmpty = 0;
				fflush(stdin);
				nuevoPasajero->id = id;
				list[index] = *nuevoPasajero;
				todoOk = 1;
			}
		}else
		{
			printf("Ocurrió un problema con los parámetros\n");
		}
	}

	return todoOk;
}


int findFreePassenger(Passenger* list, int len, int* pIndex)
{
	int todoOk = 0;

	if(list != NULL && len > 0 && pIndex != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			*pIndex = -1;
			if(list[i].isEmpty == 1)
			{
				*pIndex = i;
				break;
			}
		}

		todoOk = 1;
	}

	return todoOk;
}


int findPassengerById(Passenger* list, int len,int id)
{
	int index = -1;

	if(list != NULL && len > 0 && id > 999 && id < 3001)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				index = i;
				return index;
			}
		}
	}

	return index;
}


int removePassenger(Passenger* list, int len, int id)
{
	int todoOk = -1;
	int index;
	char confirma;

	if(list != NULL && len > 0 && id > 999 && id < 3001)
	{
		do
		{
			printPassenger(list, len);
			printf("¿Qué pasajero quiere dar de baja?\n");
			printf("Ingrese la ID correspondiente: ");
			fflush(stdin);
			scanf("%d", &id);

			if(findPassengerById(list, len, id) == -1)
			{
				printf("No hay ningún pasajero con esa ID \n");
				system("pause");
			}else
			{
				index = findPassengerById(list, len, id);
				printf("¿Confirma la baja del pasajero? (si = 's'  no = 'n') \n");
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
				if(confirma == 'n')
				{
					printf("La baja del pasajero fue cancelada\n");
					system("pause");
					return todoOk;
				}else
				{
					list[index].isEmpty = 1;
					printf("Baja realizada correctamente\n");
					system("pause");
					todoOk = 0;
				}
			}

		}while(todoOk == -1);

	}
	return todoOk;
}


int printPassenger(Passenger* list, int length)
{
    int todoOk = 0;
    char type[10];
    char status[10];

    if(list != NULL && length > 0 )
    {

        printf("                                  *** Listado de Pasajeros ***\n\n");
        printf(" ID       Nombre         Apellido           Precio         Código de vuelo        Tipo de Pasajero         Estado de Vuelo\n");
        printf("----------------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i < length; i++)
        {

        	if(list[i].isEmpty == 0)
        	{
            	switch(list[i].typePassenger)
            	{
            	case 1:
            		strcpy(type, "VIP");
            		break;
            	case 2:
            		strcpy(type, "Standard");
            		break;
            	default:
            		strcpy(type, "General");
            		break;
            	}
            	switch(list[i].statusFlight)
				{
				case 1:
					strcpy(status, "Activo");
					break;
				case 2:
					strcpy(status, "Inactivo");
					break;
				default:
					strcpy(status, "Demorado");
					break;
				}

            	printf("%4d    %10s    %10s         %9.2f           %10s              %8s                 %8s\n",
            	list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, type, status);
        	}

        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
