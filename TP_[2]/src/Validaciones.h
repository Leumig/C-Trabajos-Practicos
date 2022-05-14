/*
 * Validaciones.h
 *
 *  Created on: 6 may. 2022
 *      Author: JUNMI
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @brief Valida que una cadena sea de sólo letras, sin tildes ni espacios,
/// y que tenga un mínimo y un máximo de caracteres.
///
/// @param auxCad recibe la cadena escrita la cual se va a validar
/// @return retorna 1 cuando finalice la función
int validarPalabra(char* auxCad);


/// @brief Valida que el caracter ingresado sea un número entero,
/// y que esté entre un mínimo y un máximo si es necesario.
///
/// @param validarInt recibe 1 si lo recibido es un entero, o un 0 si no lo es
/// @param num recibe la ddm de un número el cual se va a validar
/// @return retorna 1 cuando finalice la función
int validarInt(int validarInt, int* num);


/// @brief Valida que el caracter ingresado sea un número float,
/// y que esté entre un mínimo y un máximo si es necesario.
///
/// @param validarFloat recibe 1 si lo recibido es un float, o un 0 si no lo es
/// @param num recibe la ddm de un float el cual se va a validar
/// @return retorna 1 cuando finalice la función
int validarFloat(int validarFloat, float* num);


/// @brief Valida que el código sea correcto, y en base al código le da valor al estado de vuelo.
///
/// @param codigo recibe el código ingresado y lo valida
/// @param status recibe la ddm de una variable status, a la cual se le va a cargar '1', '2', o '3'
/// @return retorna 1 cuando finalice la función
int validarCodigoYStatus(char* codigo, int* status);


/// @brief Valida la elección de un número entero para elegir tipo u opción,
/// con mínimos o máximos.
///
/// @param validarTipo recibe 1 si lo recibido es un entero, o un 0 si no lo es
/// @param tipo recibe la ddm de un entero al cual se le va a cargar el tipo validado
/// @return retorna 1 cuando finalice la función
int validarTipo(int validarTipo, int* tipo);

#endif /* VALIDACIONES_H_ */
