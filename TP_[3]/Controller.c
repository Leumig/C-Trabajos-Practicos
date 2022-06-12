#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "parser.h"
#include "Validaciones.h"
#include "Passenger_ABM.h"
#include "Controller.h"
#include "Passenger_ABM.h"
#include "Menu.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return ints
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* f = fopen("data.csv", "r");

		if(f == NULL)
		{
			printf("No se pudo abrir el archivo de texto\n\n");
			return todoOk;
		}

		parser_PassengerFromText(f, pArrayListPassenger);

		printf("\nCargado correctamente desde texto\n\n");
		fclose(f);
	}

    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* f = fopen("data.bin", "rb");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo binario\n\n");
			return todoOk;
		}

		parser_PassengerFromBinary(f, pArrayListPassenger);

		printf("\nCargado correctamente desde binario\n\n");
		fclose(f);
	}

    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	if(pArrayListPassenger != NULL)
	{
		Passenger* nuevoPasajero = NULL;

		char nombre[50];
		char apellido[50];
		char codigo[15];
		int validarPrecio = 0;
		float precio = 0;
		int validTipo = 0;
		int tipo = 0;
		int status = 0;

		printf("Ingrese el nombre del pasajero: ");
		fflush(stdin);
		gets(nombre);
		validarPalabra(nombre);

		printf("Ingrese el apellido del pasajero: ");
		fflush(stdin);
		gets(apellido);
		validarPalabra(apellido);

		printf("\nIngrese precio: ");
		validarPrecio = scanf("%f", &precio);
		validarFloat(validarPrecio, &precio);

		printf("\nC�digo de vuelo\n");
		printf("Recuerde que debe tener 10 d�gitos y empezar con 'A', 'B', 'C' o 'D'\n\n");
		printf("Ingrese c�digo: ");
		fflush(stdin);
		gets(codigo);
		validarCodigoYStatus(codigo, &status);

		printf("\nAclaraci�n: Todos los vuelos de la l�nea 'C' ya aterrizaron\n");
		printf("Aclaraci�n: Todos los vuelos de la l�nea 'A' se encuentran en vuelo\n");
		printf("Aclaraci�n: Todos los vuelos de la l�nea 'B' se encuentran est�n en horario\n");
		printf("Aclaraci�n: Todos los vuelos de la l�nea 'D' se encuentran demorados\n\n");


		system("pause");

		printf("Tipos de pasajero \n\n");
		printf("1. Executive Class \n");
		printf("2. First Class \n");
		printf("3. Economy Class \n\n");
		printf("Seleccione su tipo: ");
		validTipo = scanf("%d", &tipo);
		validarTipo(validTipo, &tipo);

		int idActual = controller_getUltimaID();

		nuevoPasajero = Passenger_newParametrosAdd(idActual, nombre, apellido, precio, codigo, tipo, status);

		if(nuevoPasajero != NULL)
		{
			ll_add(pArrayListPassenger, nuevoPasajero);

			controller_actualizarID(idActual);

			todoOk = 1;

			printf("\nSe agreg� correctamente al nuevo pasajero\n\n");
		}
	}

	if(todoOk == 0)
	{
		printf("No se pudo agregar al pasajero\n\n");
	}

	return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	return 1;
}



/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	int len = ll_len(pArrayListPassenger);
	int indice;
	char confirma;

	if(pArrayListPassenger != NULL)
	{
		do
		{
			if(len == 0)
			{
				printf("No hay pasajeros en el sistema\n\n");
				return todoOk;
			}
			controller_ListPassenger(pArrayListPassenger);
			printf("�Qu� pasajero quiere dar de baja?\n");
			printf("Ingrese la ID correspondiente: ");
			fflush(stdin);
			scanf("%d", &id);


			if(controller_buscarPasajeroPorID(pArrayListPassenger, len, id) == -1)
			{
				printf("No hay ning�n pasajero con esa ID \n");
				system("pause");
			}else
			{
				indice = controller_buscarPasajeroPorID(pArrayListPassenger, len, id);
				printf("�Confirma la baja del pasajero? (si = 's'  no = 'n') \n");
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
					ll_remove(pArrayListPassenger, indice);
					printf("Baja realizada correctamente\n");
					system("pause");
					todoOk = 1;
				}
			}

		}while(todoOk == 0);

	}
	return todoOk;
}
/// @brief Busca encontrar la ID recibida en la lista de pasajeros y devuelve
/// el indice correspondiente si es que la encuentra.
///
/// @param lista recibe el array de la estructura
/// @param len recibe el tama�o del linkedlist
/// @param id recibe la ID que tiene que buscar
/// @return retorna el indice correspondiente o -1 si no logro encontrarlo
int controller_buscarPasajeroPorID(LinkedList* pArrayListPassenger, int len, int id)
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

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger != NULL)
	{
		Passenger* auxPass = NULL;
		int flag = 0;

		printf("                                           *** Listado de Pasajeros ***\n\n");
		printf(" ID          Nombre              Apellido           Precio         C�digo de vuelo        Tipo de Pasajero         Estado de Vuelo\n");
		printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
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
			printf("                                            No hay pasajeros cargados                         \n\n");
		}

	}

    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* f = fopen("data.csv", "w");
		Passenger* auxPass = NULL;

		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPass = (Passenger*) ll_get(pArrayListPassenger, i);
			fprintf(f,"%d,%s,%s,%f,%s,%d,%d\n",
			auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->precio,
			auxPass->codigoVuelo, auxPass->tipoPasajero, auxPass->statusFlight);
		}

		fclose(f);
	}

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* f = fopen("data.bin", "wb");
		Passenger* auxPass = NULL;

		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPass = (Passenger*) ll_get(pArrayListPassenger, i);
			fwrite(auxPass,sizeof(Passenger), 1, f);
		}

		fclose(f);
	}

    return 1;
}


/// @brief Al iniciar el programa cargo el valor que tenga guardado, y se lo asigno a la
/// ID que voy a usar, si no hay nada guardado, se crea el archivo por primera vez.
///
///
/// @return retorna el valor del �ltimo ID
int controller_getUltimaID()
{
	int ultimaId = 1;
	char ultimaIdStr[50];

	FILE* f = fopen("ultimaID.txt", "r");

	if(f != NULL)
	{
		fscanf(f, "%[^\n]", ultimaIdStr);
		ultimaId = atoi(ultimaIdStr);
	}
	else
	{
	    f = fopen("ultimaID.txt", "w");
	    fprintf(f, "%d\n", ultimaId);
	}

	fclose(f);

	return ultimaId;
}

/// @brief Recibe el valor de la id actual (la ultima), y la guarda en el archivo sumandole 1+
///
/// @param idActual recibe el valor de la id actual
/// @return retorna 1 si funciona, 0 si no funciona
int controller_actualizarID(int idActual)
{
	int todoOk = 0;

	FILE* f = fopen("ultimaID.txt", "w");

	if(f!=NULL)
	{
		fprintf(f, "%d\n", idActual + 1);
		todoOk = 1;
	}
	fclose(f);

	return todoOk;
}
