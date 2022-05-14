/*
 * Menu.h
 *
 *  Created on: 28 abr. 2022
 *      Author: JUNMI
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief Muestra un menú de opciones y le pide al usuario
/// que ingrese una opción.
///
/// @return devuelve 1 si funcionó, y sino, devuelve 0
int menu();


/// @brief Muestra un menú de opciones de informes y le pide al usuario
/// que ingrese una opción.
///
/// @return devuelve 1 si funcionó, y sino, devuelve 0
int menuInformar();


/// @brief Muestra un menú de opciones de modificaciones y le pide al usuario
/// que ingrese una opción.
///
/// @return devuelve 1 si funcionó, y sino, devuelve 0
int menuModificar();


/// @brief Le pide al usuario que responda con 's' o 'n' si quiere salir
/// o no del menú.
///
/// @param p es un puntero que va a cargar el valor de la respuesta
void confirmarSalidaMenu(char* p);


#endif /* MENU_H_ */
