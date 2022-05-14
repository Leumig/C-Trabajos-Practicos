/*
 * Menu.h
 *
 *  Created on: 13 abr. 2022
 *      Author: JUNMI
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief muestro un menu de opciones y pido una opcion
///
/// \return retorna la opcion seleccionada por el usuario
int menu();



/// @brief llama a la funcion pedirKilometros para pedir los kilometros, realiza las validaciones correspondientes
/// y cambia los valores de las Flags
///
/// @param pFlagKilometros int* recibe la Flag de los kilometros
/// @param pKilometros float* recibe los kilometros
/// @param pFlagCPrecios int*  recibe la Flag de los precios
/// @param pFlagCalculos int*  recibe la Flag de los calculos
/// @return
int caseKilometros(int* pFlagKilometros, float* pKilometros, int* pFlagCPrecios, int* pFlagCalculos);



/// @brief llama a la funcion pedirPrecios para pedir los precios, realiza las validaciones correspondientes
/// y cambia los valores de las Flags
///
/// @param pFlagKilometros int* recibe la Flag de los kilometros
/// @param pFlagPrecios int*  recibe la Flag de los precios
/// @param pFlagCalculos int*  recibe la Flag de los calculos
/// @param pPrecioAerolineas float* recibe la ddm de una variable que va a guardar el precio Aerolineas
/// @param pPrecioLatam float* recibe la ddm de una variable que va a guardar el precio Latam
/// @return
int casePrecios(int* pFlagKilometros, int* pFlagPrecios, int* pFlagCalculos, float* pPrecioAerolineas, float* pPrecioLatam);



/// @brief recibo direcciones de memoria para guardar los valores que vienen del main, para después mostrarlos todos
/// ordenadamente usando printf
///
/// @param pPrecioAerolineas float* recibe una ddm que va a guardar el precio Aerolineas
/// @param pPrecioLatam float* recibe una ddm que va a guardar el precio Latam
/// @param pKilometros float* recibe una ddm que va a guardar la cantidad de Kilometros
/// @param pPrecioDebitoAerolineas float* recibe una ddm que va a guardar el debito Aerolineas
/// @param pPrecioDebitoLatam float* recibe una ddm que va a guardar el debito Latam
/// @param pPrecioCreditoAerolineas float* recibe una ddm que va a guardar el credito Aerolineas
/// @param pPrecioCreditoLatam float* recibe una ddm que va a guardar el credito Latam
/// @param pPrecioBitcoinAerolineas float* recibe una ddm que va a guardar el bitcoin Aerolineas
/// @param pPrecioBitcoinLatam float* recibe una ddm que va a guardar el bitcoin Latam
/// @param pPrecioUnitarioAerolineas float* recibe una ddm que va a guardar el precio unitario Aerolineas
/// @param pPrecioUnitarioCreditoLatam float* recibe una ddm que va a guardar el precio unitario Latam
/// @param pDiferencia float* recibe una ddm que va a guardar la diferencia entre los precios
///
/// @return retorno 0 o 1 dependiendo si funcionó bien o no
void informarResultados(float* pPrecioAerolineas, float* pPrecioLatam, float* pKilometros, float* pPrecioDebitoAerolineas,
float* pPrecioDebitoLatam, float* pPrecioCreditoAerolineas, float* pPrecioCreditoLatam, float* pPrecioBitcoinAerolineas,
float* pPrecioBitcoinLatam, float* pPrecioUnitarioAerolineas, float* pPrecioUnitarioCreditoLatam, float* pDiferencia);

#endif /* MENU_H_ */
