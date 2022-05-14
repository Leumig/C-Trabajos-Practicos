/*
 * Pasajeros.h
 *
 *  Created on: 10 may. 2022
 *      Author: JUNMI
 */

#ifndef PASAJEROS_H_
#define PASAJEROS_H_

/// @brief Hago que el usuario seleccione por ID qué empleado de la lista quiere modificar,
/// y le muestro un menú en el cual debe seleccionar qué campo del empleado quiere modificar.
///
/// @param list recibe la ddm del array de pasajeros que uso en el main
/// @param len recibe el tamaño del array
/// @param id en esta variable voy a cargar el id del empleado a modificar
/// @return devuelve 1 si se efectuó la modificación, y sino, devuelve 0
int modificarPasajero(Passenger* list, int len, int id);


/// @brief Le agrego una cantidad de pasajeros con datos hardcodeados ingresada
///  por el usuario a la lista de pasajeros.
///
/// @param lista recibe la ddm del array de pasajeros que uso en el main
/// @param tam recibe el tamaño del array
/// @param id recibe la id del main para aumentarla correspondientemente a los pasajeros añadidos
/// @return devuelve 1 al finalizar la función
int hardcodearPasajeros(Passenger lista[], int tam, int* id);


/// @brief Ordena la lista de empleados primero por el tipo, y después por el apellido.
/// Según el criterio, puede hacerlo de forma ascendente o descendente.
///
/// @param vec recibe el array de pasajeros que uso en el main
/// @param tam recibe el tamaño del array
/// @param criterio recibe '1' o '0' dependiendo de lo que ingresó el usuario
/// @return devuelve 1 si la función se realizó correctamente, sino devuelve 0
int ordenarEmpleadosPorTipoYApellido(Passenger vec[], int tam, int criterio);


/// @brief Informa la suma total de precios, el promedio, y la cantidad de pasajeros
/// cuyo precio supere el promedio.
///
/// @param vec recibe el array de pasajeros que uso en el main
/// @param tam recibe el tamaño del array
/// @return devuelve 1 si la función se realizó correctamente, sino devuelve 0
int informarTotalPromedioYPasajeroSuperiorAlPromedio(Passenger vec[], int tam);


/// @brief Ordena la lista de empleados primero por el estado, y después por el código.
/// Según el criterio, puede hacerlo de forma ascendente o descendente.
///
/// @param vec recibe el array de pasajeros que uso en el main
/// @param tam recibe el tamaño del array
/// @param criterio recibe '1' o '0' dependiendo de lo que ingresó el usuario
/// @return devuelve 1 si la función se realizó correctamente, sino devuelve 0
int ordenarEmpleadosPorCodigoYEstado(Passenger vec[], int tam, int criterio);


/// @brief Hace un listado de todos los pasajeros que tengan el estado de vuelo 'Activo'.
///
/// @param lista recibe el array de pasajeros que uso en el main
/// @param tam recibe el tamaño del array
/// @return devuelve 1 si la función se realizó correctamente, sino devuelve 0
int listarPasajerosActivos(Passenger* lista, int tam);

#endif /* PASAJEROS_H_ */
