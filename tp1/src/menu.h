/*
 * menu.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Alumno
 */

#ifndef MENU_H_
#define MENU_H_

int menu(float kilometros, float aerolineas, float latam);
void ingresarKilometros(float* pKilometros, int* pFlag);
void ingresarPrecios(float* pPrecioAerolineas, float* pPrecioLatam, int* pFlag);
int calcularCostos(float kilometros, float aerolineas, float latam, float* pDebitoAerolineas, float* pDebitoLatam, float* pCreditoAerolineas, float* pCreditoLatam, float* pBitcoinAerolineas, float* pBitcoinLatam, float* pUnitarioAerolineas, float* pUnitarioLatam, float* pDiferencia);
void informarResultados(float aerolineas, float latam, float debitoAerolineas, float debitoLatam, float creditoAerolineas, float creditoLatam, float aerolineasBTC, float latamBTC, float unitarioAerolineas, float unitarioLatam, float diferencia);
void cargaForzadaDeDatos();
void confirmarSalida(char* pSalir);

#endif /* MENU_H_ */
