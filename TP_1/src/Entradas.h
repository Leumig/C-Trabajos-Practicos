/*
 * Entradas.h
 *
 *  Created on: 13 abr. 2022
 *      Author: JUNMI
 */

#ifndef ENTRADAS_H_
#define ENTRADAS_H_


/// @brief le pido al usuario que ingrese un float de kilometros y valido que este bien
///
/// @param pkilometrosFlag int* recibe una flag para guardar si ya funciono la funcion o no
/// @param pKilometros float* recibe una direccion de memoria float para pasar los km ya sabidos
/// @return devuelve 1 si funciono correctamente
int pedirKilometros(int* pKilometrosFlag, float* pKilometros);

/// @brief le pido al usuario que ingrese un precio para Aerolineas y otro para Latam y valido que esten bien
///
/// @param pFlag int* recibe una flag para guardar si ya funciono la funcion o no
/// @param pPreciosAerolineas float* recibe una direccion de memoria float para pasar el precio ya sabido
/// @param pPreciosLatam float* recibe una direccion de memoria float para pasar el precio ya sabido
/// @return devuelve 1
int pedirPrecios(int* pPreciosFlag, float* pPreciosAerolineas, float* pPreciosLatam);

/// @brief le pido al usuario que responda con 's' o 'n' y lo cargo a una variable
///
/// @param p float* le carga valor a una variable char que se use para salir o seguir en un loop
void confirmarSalida(char* p);

#endif /* ENTRADAS_H_ */
