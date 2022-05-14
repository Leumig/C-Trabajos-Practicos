/*
 * Pasajeros.c
 *
 *  Created on: 10 may. 2022
 *      Author: JUNMI
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "Menu.h"
#include "Validaciones.h"
#include "Pasajeros.h"

int modificarPasajero(Passenger* list, int len, int id)
{
	int todoOk = 0;
	int index;
	char salirMenuModificar = 'n';

	if(list != NULL && len > 0 && id > 999 && id < 3001)
	{
		do
		{
			printPassenger(list, len);
			printf("¿Qué pasajero quiere modificar?\n");
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
				char nombre[100];
				char apellido[100];
				char codigo[100];
				int validarPrecio = 0;
				float precio = 0;
				int validTipo = 0;
				int tipo = 0;
				int status = 0;

				switch(menuModificar())
				{
				case 1:
					printf("Ingrese el nuevo Nombre: ");
					fflush(stdin);
					gets(nombre);
					validarPalabra(nombre);

					strcpy(list[index].name, nombre);

					todoOk = 1;
					printf("Nombre modificado correctamente\n");
					return todoOk;

				break;

				case 2:
					printf("Ingrese el nuevo Apellido: ");
					fflush(stdin);
					gets(apellido);
					validarPalabra(apellido);

					strcpy(list[index].lastName, apellido);

					todoOk = 1;
					printf("Apellido modificado correctamente\n");
					return todoOk;

				break;

				case 3:
					printf("Ingrese el nuevo Precio: ");
					validarPrecio = scanf("%f", &precio);
					validarFloat(validarPrecio, &precio);

					list[index].price = precio;


					todoOk = 1;
					printf("Precio modificado correctamente\n");
					return todoOk;

				break;

				case 4:
					printf("\nNuevo código de vuelo\n");
					printf("Recuerde que debe tener 10 dígitos y empezar con 'A', 'B', o 'C'\n\n");
					printf("Ingrese nuevo código: ");
					fflush(stdin);
					gets(codigo);
					validarCodigoYStatus(codigo, &status);

	                printf("\nAclaración: Todos los vuelos de las líneas 'B' se encuentran inactivos\n");
	                printf("Aclaración: Todos los vuelos de las líneas 'C' se encuentran demorados\n");

	                system("pause");

					list[index].statusFlight = status;
					strcpy(list[index].flycode, codigo);

					todoOk = 1;
					printf("Código modificado correctamente\n");
					return todoOk;

				break;

				case 5:
					printf("Ingrese el nuevo Tipo de pasajero: ");
					printf("\n\nTipos de pasajero \n\n");
					printf("1. VIP \n");
					printf("2. Standard \n");
					printf("3. General \n\n");
					printf("Seleccione su tipo: ");
					validTipo = scanf("%d", &tipo);
					validarTipo(validTipo, &tipo);

					list[index].typePassenger = tipo;

					todoOk = 1;
					printf("Tipo modificado correctamente\n");
					return todoOk;

				break;

				case 6:
					confirmarSalidaMenu(&salirMenuModificar);
				break;

				default:
					printf("Opción incorrecta (debe ser un número del 1 al 6) \n\n");
				break;
				}
			}
		}while(salirMenuModificar == 'n');

	}

	if(todoOk == 0)
	{
		printf("No se modificó nada\n");
	}
	return todoOk;
}



int hardcodearPasajeros(Passenger lista[], int tam, int* id)
{
	int todoOk = 0;
	int index;
	int cant;
	int validarCant = 0;

    Passenger hardcodeos[] =
    {
        {0, "Luis", "Diaz", 150250,"B8A1G27c01",2,2,0},
        {0, "Emilia", "Mernes", 750500, "AK22Zx8h9m",1,1,0},
        {0, "Maria", "Ortiz", 280800, "A4n0Qw7hvB",1,1,0},
        {0, "Mauro", "Lombardo", 125000, "Ci3L1Ppew5",2,3,0},
        {0, "Pedro", "Gonzalez", 100000, "B2s1A0lqF1",3,2,0},
        {0, "Fernando", "Torres", 95000, "CHuR9mck4I",3,3,0},
        {0, "Belen", "Lavena", 80850, "A0FD2aoR6t",3,1,0},
        {0, "Sol", "Ruiz", 305600, "B7X1Zlhm0Y",1,2,0},
        {0, "Juan", "Prestia", 225000, "Cy2AsB8evb",2,3,0},
		{0, "Gabriel", "Sardiz", 550900,"C00XCw1I2n",1,3,0},
		{0, "Paulo", "Lupa", 750500, "BD93s2Azg9",1,2,0},
		{0, "Karim", "Nieves", 185000, "Age1L0icjF",2,1,0},
		{0, "Victor", "Torbe", 215000, "B5q4RWh1H7",2,2,0},
		{0, "Zoe", "Siso", 675500, "B9ldKY21u0",1,2,0},
		{0, "Franco", "Noria", 95000, "AUmE2t7aPX",3,1,0},
		{0, "Carla", "Alcaraz", 195450, "CbBa28mgCV",2,3,0},
		{0, "Lucia", "Pilar", 660000, "C19wHpOyqf",1,3,0},
		{0, "Horacio", "Rosario", 90800, "BL0ocXf42I",3,2,0},
		{0, "Bianca", "Azul", 235200, "A6s5GmbeuE",2,1,0},
        {0, "Roman", "Riquelme", 65900, "CT0k7teY3U",3,3,0}
    };


	printf("\n  ***** HARDCODEO *****     \n\n");
	printf("Los pasajeros que hardcodee, se agregarán a la lista del sistema\n");
	printf("Aclaración: solo se puede hardcodear una vez\n\n");
	printf("Ingrese cantidad de pasajeros hardcodeados (máximo 20): ");
	validarCant = scanf("%d", &cant);
    while(validarCant != 1 || cant < 1 || cant > 20)
    {
    	printf("Error. Debe hardcodear entre 1 y 20 pasajeros\n");
    	printf("Reingrese: ");
    	fflush(stdin);
    	validarCant = scanf("%d", &cant);
    }

	findFreePassenger(lista, tam, &index);

    if(index==-1)
	{
		printf("Ya no hay lugar en el sistema\n");
		return todoOk;
	}
    else
    {
    	 if(lista != NULL && tam > 0 && id != NULL && cant > 0 && cant <= 20)
		{
    		int j = 0;

			for(int i=index; i < (index+cant); i++)
			{
				lista[i] = hardcodeos[j];
				lista[i].id = *id;
				*id = *id +1;
				j++;

			}
			todoOk = 1;
		}else
		{
			printf("Ocurrió un error en el hardcodeo\n");
		}
    }

    if(cant == 1)
    {
    	printf("Se hardcodeó al pasajero\n");
    }else
    {
        printf("Se hardcodearon los pasajeros\n");
    }

	return todoOk;
}



int ordenarEmpleadosPorTipoYApellido(Passenger vec[], int tam, int criterio)
{
    int todoOk = 0;
    Passenger auxEmpleado;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(((vec[i].typePassenger == vec[j].typePassenger) && (strcmp(vec[i].lastName, vec[j].lastName) > 0) && criterio)
                ||((vec[i].typePassenger == vec[j].typePassenger) && (strcmp(vec[i].lastName, vec[j].lastName) < 0) && !criterio)
				||((vec[i].typePassenger != vec[j].typePassenger) && (vec[i].typePassenger > vec[j].typePassenger) && criterio)
				||((vec[i].typePassenger != vec[j].typePassenger) && (vec[i].typePassenger < vec[j].typePassenger) && !criterio))
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }

            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int informarTotalPromedioYPasajeroSuperiorAlPromedio(Passenger vec[], int tam)
{
	int todoOk = 0;

	if(vec != NULL && tam > 0)
	{
        printf("\n--------------------------------------\n");

    	int contador = 0;
    	float acumulador = 0;
    	float promedio;
    	int contadorSuperiorAlPromedio = 0;

        for(int i = 0; i < tam; i++)
		{
			if(!vec[i].isEmpty)
			{
				acumulador = acumulador + vec[i].price;
				contador++;
			}
		}

		promedio = (acumulador / contador);

	   for(int i = 0; i < tam; i++)
		{
			if(!vec[i].isEmpty && vec[i].price > promedio)
			{
				contadorSuperiorAlPromedio++;
			}
		}


        if(contador == 0)
        {
        	printf("No hay pasajeros\n");
        }else
        {
        	printf("Total de precios de los pasajes: $ %.2f\n", acumulador);
        	printf("Promedio de precios de los pasajes: $ %.2f\n", promedio);
        	printf("Cantidad de pasajeros que superan el precio promedio: %d\n", contadorSuperiorAlPromedio);
        }


        todoOk = 1;
	}

	return todoOk;
}



int ordenarEmpleadosPorCodigoYEstado(Passenger vec[], int tam, int criterio)
{
    int todoOk = 0;
    Passenger auxEmpleado;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(((vec[i].statusFlight == vec[j].statusFlight) && (strcmp(vec[i].flycode, vec[j].flycode) > 0) && criterio)
                ||((vec[i].statusFlight == vec[j].statusFlight) && (strcmp(vec[i].flycode, vec[j].flycode) < 0) && !criterio)
				||((vec[i].statusFlight != vec[j].statusFlight) && (vec[i].statusFlight > vec[j].statusFlight) && criterio)
				||((vec[i].statusFlight != vec[j].statusFlight) && (vec[i].statusFlight < vec[j].statusFlight) && !criterio))
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }

            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int listarPasajerosActivos(Passenger* lista, int tam)
{
    int todoOk = 0;
    char tipo[10];
    char estado[10];

    if(lista != NULL && tam > 0)
    {

        printf("                                  *** Listado de Pasajeros [Estado Activo] ***\n\n");
        printf(" ID       Nombre         Apellido           Precio         Código de vuelo        Tipo de Pasajero         Estado de Vuelo\n");
        printf("----------------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
        	if(lista[i].isEmpty == 0 && lista[i].statusFlight == 1)
        	{
            	switch(lista[i].typePassenger)
            	{
            	case 1:
            		strcpy(tipo, "VIP");
            		break;
            	case 2:
            		strcpy(tipo, "Standard");
            		break;
            	default:
            		strcpy(tipo, "General");
            		break;
            	}

            	if(lista[i].statusFlight == 1)
				{
					strcpy(estado, "Activo");
				}

            	printf("%4d    %10s    %10s         %9.2f           %10s              %8s                 %8s\n",
            	lista[i].id, lista[i].name, lista[i].lastName, lista[i].price, lista[i].flycode, tipo, estado);
        	}

        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
