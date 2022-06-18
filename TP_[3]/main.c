#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
#include "Passenger.h"
#include "Passenger_ABM.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	char salirMenu = 'n';

	int flagCargaTxt = 0;
	int flagCargaBin = 0;
	int flagGuardarTxt = 0;
	int flagGuardarBin = 0;

	controller_getUltimaID();

    LinkedList* listaPasajeros = ll_newLinkedList();

    if(listaPasajeros == NULL)
    {
    	printf("No se pudo cargar en la memoria\n\n");
    	exit(1);
    }

    do{
    	switch(menu(listaPasajeros))
		{
		case 1:
			if(flagCargaTxt == 1 || flagCargaBin == 1)
			{
				printf("Ya se realizó la carga de datos anteriormente\n\n");
			}else
			{
				controller_loadFromText("data.csv", listaPasajeros);
				flagCargaTxt = 1;
			}

			break;
		case 2:
			if(flagCargaTxt == 1 || flagCargaBin == 1)
			{
				printf("Ya se realizó la carga de datos anteriormente\n\n");
			}else
			{
				controller_loadFromBinary("data.bin", listaPasajeros);
				flagCargaBin = 1;
			}

			break;
		case 3:
				controller_addPassenger(listaPasajeros);
			break;
		case 4:
			controller_editPassenger(listaPasajeros);

			break;
		case 5:
			controller_removePassenger(listaPasajeros);

			break;
		case 6:
			controller_ListPassenger(listaPasajeros);

			break;
		case 7:
			controller_sortPassenger(listaPasajeros);

			break;
		case 8:

			if(flagCargaBin)
			{
				printf("No se puede guardar como texto si se hizo una carga binaria\n\n");
			}else
			{
				controller_saveAsText("data.csv" , listaPasajeros);
				printf("\nGuardado correctamente\n\n");
				flagGuardarTxt = 1;
			}

			break;
		case 9:
			if(flagCargaTxt)
			{
				printf("No se puede guardar como binario si se hizo una carga de texto\n\n");
			}else
			{
				controller_saveAsBinary("data.csv" , listaPasajeros);
				printf("\nGuardado correctamente\n\n");
				flagGuardarBin = 1;
			}

			break;
		case 10:
			if(flagGuardarTxt == 1 || flagGuardarBin == 1)
			{
				confirmarSalidaMenu(&salirMenu);
			}else
			{
				printf("Primero deberías guardar datos\n\n");
			}
			break;

		default:
			printf("Opción incorrecta (debe ser un número del 1 al 10) \n\n");
		}
		system("pause");

	}while(salirMenu != 's');

    if(flagGuardarTxt)
    {
    	controller_saveAsBinary("data.csv" , listaPasajeros);
    }else
    {
    	controller_saveAsText("data.csv" , listaPasajeros);
    }

    printf("Fin del programa\n\n");

    Passenger_delete(listaPasajeros);

    return 0;
}

