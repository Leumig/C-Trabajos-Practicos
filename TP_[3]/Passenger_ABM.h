/*
 * Passenger_ABM.h
 *
 *  Created on: 11 jun. 2022
 *      Author: JUNMI
 */

#ifndef PASSENGER_ABM_H_
#define PASSENGER_ABM_H_

/// @brief Muestro los datos de un pasajero.
///
/// @param e recibe la estructura Passenger
/// @return retorna 1 al finalizar
int mostrarPasajero(Passenger* e);

/// @brief Llama a la función newParametros para pedir espacio en la memoria dinámica,
/// y con los Setters le asigna los valores recibidos al nuevo pasajero.
///
/// @param id recibe el valor del campo id
/// @param nombre recibe el valor del campo nombre
/// @param apellido recibe el valor del campo apellido
/// @param precio recibe el valor del campo precio
/// @param codigoVuelo recibe el valor del campo codigoVuelo
/// @param tipoPasajero recibe el valor del campo tipoPasajero
/// @param statusFlight recibe el valor del campo statusFlight
/// @return retorna al nuevo pasajero de tipo puntero a Passenger
Passenger* Passenger_newParametrosAdd(int id, char* nombre, char* apellido, float precio,
								   char* codigoVuelo, int tipoPasajero, int statusFlight);



















#endif /* PASSENGER_ABM_H_ */
