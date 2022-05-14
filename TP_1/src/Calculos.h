/*
 * Calculos.h
 *
 *  Created on: 13 abr. 2022
 *      Author: JUNMI
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @brief recibe los parametros que necesita cada funcion de cada calculo para el vuelo Aerolineas,
/// llama a todas las funciones y devuelve los valores hacia el main
///
/// @param pPrecio float* recibe el precio de Aerolineas
/// @param pCostoDebito float* recibe la ddm de la variable que va a guardar el precio Debito de Aerolineas
/// @param pCostoCredito float* recibe la ddm de la variable que va a guardar el precio Credito de Aerolineas
/// @param pCostoBitcoin float* recibe la ddm de la variable que va a guardar el precio Bitcoin de Aerolineas
/// @param pPrecioUnitario float* recibe la ddm de la variable que va a guardar el precio Unitario de Aerolineas
/// @param pKilometros float* recibe los kilometros para calcular el precio Unitario
/// @return
int calcularAerolineas(float* pPrecio, float* pCostoDebito, float* pCostoCredito, float* pCostoBitcoin, float* pPrecioUnitario, float* pKilometros);



/// @brief recibe los parametros que necesita cada funcion de cada calculo para el vuelo Latam,
/// llama a todas las funciones y devuelve los valores hacia el main
///
/// @param pPrecio float* recibe el precio de Latam
/// @param pCostoDebito float* recibe la ddm de la variable que va a guardar el precio Debito de Latam
/// @param pCostoCredito float* recibe la ddm de la variable que va a guardar el precio Credito de Latam
/// @param pCostoBitcoin float* recibe la ddm de la variable que va a guardar el precio Bitcoin de Latam
/// @param pPrecioUnitario float* recibe la ddm de la variable que va a guardar el precio Unitario de Latam
/// @param pKilometros float* recibe los kilometros para calcular el precio Unitario
/// @return
int calcularLatam(float* pPrecio, float* pCostoDebito, float* pCostoCredito, float* pCostoBitcoin, float* pPrecioUnitario, float* pKilometros);



/// @brief recibe el precio de Aerolineas o de Latam para calcular el Debito
///
/// @param pPrecio float* recibe el precio
/// @param pCostoDebito float* recibe la ddm de una variable que va a guardar el precio Debito
/// @return
int calcularDebito(float* pPrecio, float* pCostoDebito);

/// @brief recibe el precio de Aerolineas o de Latam para calcular el Credito
///
/// @param pPrecio float* recibe el precio
/// @param pCostoCredito float* recibe la ddm de una variable que va a guardar el precio Credito
/// @return
int calcularCredito(float* pPrecio, float* pCostoCredito);



/// @brief recibe el precio de Aerolineas o de Latam para calcular el Bitcoin
///
/// @param pPrecio float* recibe el precio
/// @param pCostoBitcoin float* recibe la ddm de una variable que va a guardar el precio Bitcoin
/// @return
int calcularBitcoin(float* pPrecio, float* pCostoBitcoin);



/// @brief recibe el precio de Aerolineas o de Latam para calcular el Precio Unitario
///
/// @param pPrecio float* recibe el precio
/// @param pPrecioUnitario float* recibe la ddm de una variable que va a guardar el precio Unitario
/// @param pKilometros float* recibe los kilometros
/// @return
int calcularPrecioUnitario(float* pPrecio, float* pPrecioUnitario, float* pKilometros);



/// @brief recibe el precio de Aerolineas y de Latam para calcular la diferencia
///
/// @param pPrecioAerolineas float* recibe el precio Aerolineas
/// @param pPrecioLatam float* recibe el precio Latam
/// @param pDiferencia float* recibe la ddm de una variable que va a guardar la diferencia entre ambos precios
/// @return
int calcularDiferencia(float* pPrecioAerolineas, float* pPrecioLatam, float* pDiferencia);



#endif /* CALCULOS_H_ */

