/*
 * ArrayPassenger.h
 *
 *  Created on: 6 may. 2022
 *      Author: JUNMI
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGER_H_ */

/// @brief Inicializa el array de pasajeros, colocando a todos
/// los 'isEmpty' en '1'.
///
/// @param list recibe el array de la estructura pasajero
/// @param len recibe el tamaño del array
/// @return devuelve 1 si funcionó, y sino, devuelve 0
int initPassengers(Passenger* list, int len);


/// @brief Primero va a buscar si hay un lugar disponible en el sistema,
/// y si hay, va a pedirle al usuario que ingrese cada dato de un nuevo
/// pasajero para agregarlo al listado.
///
/// @param list recibe el array de la estructura pasajero
/// @param len recibe el tamaño del array
/// @param id recibe la id para cargársela como corresponde al pasajero
/// @param name recibe un char para cargarle el nombre al pasajero
/// @param lastName recibe un char para cargarle el apellido al pasajero
/// @param price recibe un float para cargarle el precio al pasajero
/// @param typePassenger recibe un int para cargarle el tipo al pasajero
/// @param flycode recibe un char para cargarle el codigo al pasajero
/// @return devuelve 1 si funcionó, y sino, devuelve 0
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);


/// @brief Va a buscar un lugar libre (isEmpty = 1) en el sistema, y al encontrarlo,
/// va devolver su correspondiente índice.
///
/// @param list recibe el array de la estructura pasajero
/// @param len recibe el tamaño del array
/// @param pIndex puntero a entero que va a cargar el valor del índice encontrado (-1 si no encuentra)
/// @return devuelve 1 si funcionó, y sino, devuelve 0
int findFreePassenger(Passenger* list, int len, int* pIndex);


/// @brief Va a buscar un pasajero dependiendo de su ID, función que sirve
/// para que el usuario seleccione al pasajero que quiere modificar o dar de baja.
///
/// @param list recibe el array de la estructura pasajero
/// @param len recibe el tamaño del array
/// @param id recibe el id que tiene que buscar en el array de pasajeros
/// @return devuelve el índice en el cual encontró el id, y si no encontró, devuelve -1
int findPassengerById(Passenger* list, int len,int id);


/// @brief Le pide al usuario que elija por ID al pasajero que quiere dar de baja,
/// si se encuentra ese pasajero y lo confirma, su isEmpty pasa a ser 1.
///
/// @param list recibe el array de la estructura pasajero
/// @param len recibe el tamaño del array
/// @param id recibe el id que tiene que buscar en el array de pasajeros
/// @return devuelve 0 si la baja se realizó correctamente, y sino, devuelve -1
int removePassenger(Passenger* list, int len, int id);


/// @brief Muestra el listado de todos los pasajeros con isEmpty = 0 del sistema,
/// cada uno con su campo.
///
/// @param list recibe el array de la estructura pasajero
/// @param length recibe el tamaño del array
/// @return devuelve 1 si funcionó, y sino, devuelve 0
int printPassenger(Passenger* list, int length);
