/*
 * Menu.h
 *
 *  Created on: 28 abr. 2022
 *      Author: JUNMI
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief Muestra un men� de opciones y le pide al usuario
/// que ingrese una opci�n.
///
/// @return devuelve 1 si funcion�, y sino, devuelve 0
int menu();


/// @brief Muestra un men� de opciones de informes y le pide al usuario
/// que ingrese una opci�n.
///
/// @return devuelve 1 si funcion�, y sino, devuelve 0
int menuInformar();


/// @brief Muestra un men� de opciones de modificaciones y le pide al usuario
/// que ingrese una opci�n.
///
/// @return devuelve 1 si funcion�, y sino, devuelve 0
int menuModificar();


/// @brief Le pide al usuario que responda con 's' o 'n' si quiere salir
/// o no del men�.
///
/// @param p es un puntero que va a cargar el valor de la respuesta
void confirmarSalidaMenu(char* p);


#endif /* MENU_H_ */
