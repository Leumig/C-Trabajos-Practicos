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

/// @brief Le pide al usuario que ingrese 'a' o 'd' para elegir el criterio de orden,
/// y le carga al criterioString la palabra 'Ascendente' o 'Descendente'.
///
/// @param criterioString recibe la ddm de un char que guardará la palabra
/// @return devuelve 1 si se ingreso 'a' o 0 si se ingreso 'd'
int preguntarCriterio(char* criterioString);

/// @brief Compara los dos elementos recibidos (ID) para poder ordenarlos
/// gracias a la función ll_sort.
///
/// @param a recibe la ddm del primer elemento
/// @param b recibe la ddm del segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int pasajeroCompararId(void* a, void* b);

/// @brief Compara los dos elementos recibidos (Nombre) para poder ordenarlos
/// gracias a la función ll_sort.
///
/// @param a recibe la ddm del primer elemento
/// @param b recibe la ddm del segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int pasajeroCompararNombre(void* a, void* b);

/// @brief Compara los dos elementos recibidos (Apellido) para poder ordenarlos
/// gracias a la función ll_sort.
///
/// @param a recibe la ddm del primer elemento
/// @param b recibe la ddm del segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int pasajeroCompararApellido(void* a, void* b);

/// @brief Compara los dos elementos recibidos (Precio) para poder ordenarlos
/// gracias a la función ll_sort.
///
/// @param a recibe la ddm del primer elemento
/// @param b recibe la ddm del segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int pasajeroCompararPrecio(void* a, void* b);

/// @brief Compara los dos elementos recibidos (Codigo) para poder ordenarlos
/// gracias a la función ll_sort.
///
/// @param a recibe la ddm del primer elemento
/// @param b recibe la ddm del segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int pasajeroCompararCodigo(void* a, void* b);

/// @brief Compara los dos elementos recibidos (Tipo) para poder ordenarlos
/// gracias a la función ll_sort.
///
/// @param a recibe la ddm del primer elemento
/// @param b recibe la ddm del segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int pasajeroCompararTipo(void* a, void* b);

/// @brief Compara los dos elementos recibidos (Estado) para poder ordenarlos
/// gracias a la función ll_sort.
///
/// @param a recibe la ddm del primer elemento
/// @param b recibe la ddm del segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int pasajeroCompararEstado(void* a, void* b);

#endif /* PASSENGER_ABM_H_ */
