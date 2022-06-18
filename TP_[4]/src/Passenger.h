/*
 * Passenger.h
 *
 *  Created on: 17 jun. 2022
 *      Author: JUNMI
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	float precio;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, float precio);

void Passenger_delete();

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int pasajeroCompararId(void* a, void* b);
int pasajeroCompararNombre(void* a, void* b);
int pasajeroCompararPrecio(void* a, void* b);
int mostrarPasajero(Passenger* e);
int listarPasajeros(LinkedList* pArrayListPassenger);








#endif /* SRC_PASSENGER_H_ */
