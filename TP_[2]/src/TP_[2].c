/*
 ============================================================================
 Name        : TP_[2]
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Menu.h"
#include "ArrayPassenger.h"
#include "Validaciones.h"
#include "Pasajeros.h"

#define LEN 2000

int main(void) {
	setbuf(stdout, NULL);

	char salirMenu = 'n';
	char salirMenuInformar = 'n';

	Passenger lista[LEN];

	initPassengers(lista,LEN);

	int id = 1000;
	int flagAlta = 0;
	int flagHardcodeo = 0;
	int criterio;
	int validCriterio = 0;

	do
	{
		switch(menu())
		{
		case 1:
			if(addPassenger(lista, LEN, id, lista[LEN].name,
			lista[LEN].lastName, lista[LEN].price, lista[LEN].typePassenger, lista[LEN].flycode))
			{
				printf("Pasajero agregado con éxito \n");
				id++;
				flagAlta = 1;
			}else
			{
				printf("No se pudo agregar al pasajero \n");
			}


		break;

		case 2:
				if(flagAlta == 1)
				{
					if(!modificarPasajero(lista, LEN, id))
					{
						printf("No se modificó nada\n");
					}
				}else
				{
					printf("Antes debe hacer un alta\n");
				}

		break;

		case 3:
				if(flagAlta == 1)
				{
					removePassenger(lista, LEN, 1000);
				}else
				{
					printf("Antes debe hacer un alta\n");
				}

		break;

		case 4:
			if(flagAlta == 1)
			{
				do
				{
					switch(menuInformar())
					{
					case 1:
						printf("Elija el criterio del orden ('1' = Ascendente / '0' = Descendente) \n");
						validCriterio = scanf("%d", &criterio);
						while(validCriterio != 1 || (criterio != 0 && criterio != 1))
						{
							printf("Error, debe ingresar '1' o '0'. Reingrese: \n");
							fflush(stdin);
							validCriterio = scanf("%d", &criterio);
						}
						ordenarEmpleadosPorTipoYApellido(lista, LEN, criterio);
						printPassenger(lista, LEN);
						salirMenuInformar = 's';
					break;

					case 2:
						informarTotalPromedioYPasajeroSuperiorAlPromedio(lista, LEN);
						salirMenuInformar = 's';
					break;

					case 3:
						printf("Elija el criterio del orden ('1' = Ascendente / '0' = Descendente) \n");
						validCriterio = scanf("%d", &criterio);
						while(validCriterio != 1 || (criterio != 0 && criterio != 1))
						{
							printf("Error, debe ingresar '0' o '1'. Reingrese: \n");
							fflush(stdin);
							validCriterio = scanf("%d", &criterio);
						}
						ordenarEmpleadosPorCodigoYEstado(lista, LEN, criterio);
						listarPasajerosActivos(lista, LEN);
						salirMenuInformar = 's';
					break;

					case 4:
						confirmarSalidaMenu(&salirMenuInformar);
					break;

					default:
						printf("Opción incorrecta (debe ser un número del 1 al 4) \n\n");
						salirMenuInformar = 'n';
						system("pause");
					}

				}while(salirMenuInformar != 's');
			}else
			{
				printf("Antes debe hacer un alta\n");
			}


		break;

		case 5:
			if(flagHardcodeo == 0)
			{
				hardcodearPasajeros(lista, LEN, &id);
				flagAlta = 1;
				flagHardcodeo = 1;
			}else
			{
				printf("Ya hardcodeaste pasajeros\n");
			}

		break;

		case 6:
			confirmarSalidaMenu(&salirMenu);
		break;

		default:
			printf("Opción incorrecta (debe ser un número del 1 al 6) \n\n");
		}

		system("pause");
	}while(salirMenu != 's');

	printf("Fin del programa");

	return 0;
}
