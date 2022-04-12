/*
 * calculos.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Alumno
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int calcularDebito(float aerolineas, float latam, float* pDebitoAerolineas, float* pDebitoLatam);
int calcularCredito(float aerolineas, float latam, float* pCreditoAerolineas, float* pCreditoLatam);
int calcularBitcoin(float aerolineas, float latam, float* pBitcoinAerolineas, float* pBitcoinLatam);
int calcularPrecioUnitario(float kilometros, float aerolineas, float latam, float* pUnitarioAerolineas, float* pUnitarioLatam);
int calcularDiferencia(float aerolineas, float latam, float* pDiferencia);

#endif /* CALCULOS_H_ */
