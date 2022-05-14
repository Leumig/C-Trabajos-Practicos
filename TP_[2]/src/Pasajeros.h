/*
 * Pasajeros.h
 *
 *  Created on: 10 may. 2022
 *      Author: JUNMI
 */

#ifndef PASAJEROS_H_
#define PASAJEROS_H_

/// @brief Hago que el usuario seleccione por ID qu� empleado de la lista quiere modificar,
/// y le muestro un men� en el cual debe seleccionar qu� campo del empleado quiere modificar.
///
/// @param list recibe la ddm del array de pasajeros que uso en el main
/// @param len recibe el tama�o del array
/// @param id en esta variable voy a cargar el id del empleado a modificar
/// @return devuelve 1 si se efectu� la modificaci�n, y sino, devuelve 0
int modificarPasajero(Passenger* list, int len, int id);


/// @brief Le agrego una cantidad de pasajeros con datos hardcodeados ingresada
///  por el usuario a la lista de pasajeros.
///
/// @param lista recibe la ddm del array de pasajeros que uso en el main
/// @param tam recibe el tama�o del array
/// @param id recibe la id del main para aumentarla correspondientemente a los pasajeros a�adidos
/// @return devuelve 1 al finalizar la funci�n
int hardcodearPasajeros(Passenger lista[], int tam, int* id);


/// @brief Ordena la lista de empleados primero por el tipo, y despu�s por el apellido.
/// Seg�n el criterio, puede hacerlo de forma ascendente o descendente.
///
/// @param vec recibe el array de pasajeros que uso en el main
/// @param tam recibe el tama�o del array
/// @param criterio recibe '1' o '0' dependiendo de lo que ingres� el usuario
/// @return devuelve 1 si la funci�n se realiz� correctamente, sino devuelve 0
int ordenarEmpleadosPorTipoYApellido(Passenger vec[], int tam, int criterio);


/// @brief Informa la suma total de precios, el promedio, y la cantidad de pasajeros
/// cuyo precio supere el promedio.
///
/// @param vec recibe el array de pasajeros que uso en el main
/// @param tam recibe el tama�o del array
/// @return devuelve 1 si la funci�n se realiz� correctamente, sino devuelve 0
int informarTotalPromedioYPasajeroSuperiorAlPromedio(Passenger vec[], int tam);


/// @brief Ordena la lista de empleados primero por el estado, y despu�s por el c�digo.
/// Seg�n el criterio, puede hacerlo de forma ascendente o descendente.
///
/// @param vec recibe el array de pasajeros que uso en el main
/// @param tam recibe el tama�o del array
/// @param criterio recibe '1' o '0' dependiendo de lo que ingres� el usuario
/// @return devuelve 1 si la funci�n se realiz� correctamente, sino devuelve 0
int ordenarEmpleadosPorCodigoYEstado(Passenger vec[], int tam, int criterio);


/// @brief Hace un listado de todos los pasajeros que tengan el estado de vuelo 'Activo'.
///
/// @param lista recibe el array de pasajeros que uso en el main
/// @param tam recibe el tama�o del array
/// @return devuelve 1 si la funci�n se realiz� correctamente, sino devuelve 0
int listarPasajerosActivos(Passenger* lista, int tam);

#endif /* PASAJEROS_H_ */
