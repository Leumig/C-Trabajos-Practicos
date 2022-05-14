/*
 * Validaciones.h
 *
 *  Created on: 6 may. 2022
 *      Author: JUNMI
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @brief Valida que una cadena sea de s�lo letras, sin tildes ni espacios,
/// y que tenga un m�nimo y un m�ximo de caracteres.
///
/// @param auxCad recibe la cadena escrita la cual se va a validar
/// @return retorna 1 cuando finalice la funci�n
int validarPalabra(char* auxCad);


/// @brief Valida que el caracter ingresado sea un n�mero entero,
/// y que est� entre un m�nimo y un m�ximo si es necesario.
///
/// @param validarInt recibe 1 si lo recibido es un entero, o un 0 si no lo es
/// @param num recibe la ddm de un n�mero el cual se va a validar
/// @return retorna 1 cuando finalice la funci�n
int validarInt(int validarInt, int* num);


/// @brief Valida que el caracter ingresado sea un n�mero float,
/// y que est� entre un m�nimo y un m�ximo si es necesario.
///
/// @param validarFloat recibe 1 si lo recibido es un float, o un 0 si no lo es
/// @param num recibe la ddm de un float el cual se va a validar
/// @return retorna 1 cuando finalice la funci�n
int validarFloat(int validarFloat, float* num);


/// @brief Valida que el c�digo sea correcto, y en base al c�digo le da valor al estado de vuelo.
///
/// @param codigo recibe el c�digo ingresado y lo valida
/// @param status recibe la ddm de una variable status, a la cual se le va a cargar '1', '2', o '3'
/// @return retorna 1 cuando finalice la funci�n
int validarCodigoYStatus(char* codigo, int* status);


/// @brief Valida la elecci�n de un n�mero entero para elegir tipo u opci�n,
/// con m�nimos o m�ximos.
///
/// @param validarTipo recibe 1 si lo recibido es un entero, o un 0 si no lo es
/// @param tipo recibe la ddm de un entero al cual se le va a cargar el tipo validado
/// @return retorna 1 cuando finalice la funci�n
int validarTipo(int validarTipo, int* tipo);

#endif /* VALIDACIONES_H_ */
