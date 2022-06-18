#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		int cant = 0;
		char buffer[7][20];
		int cantPass = ll_len(pArrayListPassenger);
		int flagAlta = 1;
		int ultimaId = 0;
		int contadorNuevos = 0;

		if(cantPass == 0)
		{
			flagAlta = 0;
		}

		Passenger* auxPass = NULL;

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				   buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

			if(cant == 7)
			{
				auxPass = Passenger_newParametros
					   (buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

				if(auxPass != NULL)
				{
					ll_add(pArrayListPassenger, auxPass);
					ultimaId = auxPass->id;
					contadorNuevos++;
				}
			}
		}

		Passenger_delete(auxPass);

		if(flagAlta == 0)
		{
			controller_actualizarID(ultimaId);
		}

		printf("\n[Pasajeros: %d]\n", contadorNuevos);
	}

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		int cant = 1;
		int cantPass = ll_len(pArrayListPassenger);
		int flagAlta = 1;
		int ultimaId = 0;
		int contadorNuevos = 0;

		if(cantPass == 0)
		{
			flagAlta = 0;
		}

		Passenger* auxPass = Passenger_new();

		do
		{
			cant = fread(auxPass, sizeof(Passenger), 1, pFile);

			if(cant == 1 && auxPass != NULL)
			{
				ll_add(pArrayListPassenger, auxPass);
				ultimaId = auxPass->id;
			}

		}while(cant);

		Passenger_delete(auxPass);

		if(flagAlta == 0)
		{
			controller_actualizarID(ultimaId);
		}

		printf("\n[Pasajeros: %d]\n", contadorNuevos);
	}



    return 1;
}
