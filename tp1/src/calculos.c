/*
 * calculos.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"
#include "menu.h"

/**@brief Funcion para calcular los costos en debito. Recibe los valores, aplica un descuento
 * y devuelve por referencia los resultados a las variables auxiliares
 *
 * @param aerolineas Recible el valor que el usuario ingreso para el precio de vuelos en Aerolineas
 * @param latam Recibe el valor que el usuario ingreso para el precio de vuelos en Latam
 * @param pDebitoAerolineas Puntero a la variable que guardara auxiliarmente el valor del precio con tarjeta de debito de Aerolineas
 * @param pDebitoLatam Puntero a la variable que guardara auxiliarmente el valor del precio con tarjeta de debito de Latam
 * @return retorno Retorna -1 si la validacion fallo, por el contrario retorna 0 si fue un exito
 */int calcularDebito(float aerolineas, float latam, float* pDebitoAerolineas, float* pDebitoLatam)
{
	int retorno;
	float descuento;

	retorno = -1;
	if(aerolineas > 0 && latam > 0 && pDebitoAerolineas != NULL && pDebitoLatam !=NULL)// <-- validacion de valores y punteros
	{
		//Calculo el descuento y luego se lo resto al precio de Aerolineas
		descuento = (aerolineas * 10)/100;
		*pDebitoAerolineas = aerolineas - descuento;

		//Calculo el descuento y luego se lo resto al precio de Latam
		descuento = (latam * 10)/100;
		*pDebitoLatam = latam - descuento;
		retorno = 0;
	}

	return retorno;
}

 /**@brief Funcion para calcular los costos en credito. Recibe los valores, aplica un aumento
 * y devuelve por referencia los resultados a las variables auxiliares
  *
  * @param aerolineas Recible el valor que el usuario ingreso para el precio de vuelos en Aerolineas
  * @param latam Recibe el valor que el usuario ingreso para el precio de vuelos en Latam
  * @param pCreditoAerolineas Puntero a la variable que guardara auxiliarmente el valor del precio con tarjeta de credito de Aerolineas
  * @param pCreditoLatam Puntero a la variable que guardara auxiliarmente el valor del precio con tarjeta de credito de Latam
  * @return retorno Retorna -1 si la validacion fallo, por el contrario retorna 0 si fue un exito
  */int calcularCredito(float aerolineas, float latam, float* pCreditoAerolineas, float* pCreditoLatam)
{
	int retorno;
	float interes;

	retorno = -1;
	if(aerolineas > 0 && latam > 0 && pCreditoAerolineas != NULL && pCreditoLatam != NULL)// <-- validacion de valores y punteros
	{
		//Calculo el interes y luego se lo sumo al precio de Aerolineas
		interes = (aerolineas * 25)/100;
		*pCreditoAerolineas = aerolineas + interes;

		//Calculo el interes y luego se lo sumo al precio de Latam
		interes = (latam * 25)/100;
		*pCreditoLatam = latam + interes;
		retorno = 0;
	}


	return retorno;
}

/**@brief Funcion para calcular los costos en Bitcoin. Recibe los valores, divide el valor del bitcoin por los
 * precios y devuelve por referencia los resultados a las variables auxiliares
 *
 * @param aerolineas Recible el valor que el usuario ingreso para el precio de vuelos en Aerolineas
 * @param latam Recible el valor que el usuario ingreso para el precio de vuelos en Latam
 * @param pBitcoinAerolineas Puntero a la variable que guardara auxiliarmente el valor del precio en bitcoin de Aerolineas
 * @param pBitcoinLatam Puntero a la variable que guardara auxiliarmente el valor del precio en bitcoin de Latam
 * @return retorno Retorna -1 si la validacion fallo, por el contrario retorna 0 si fue un exito
 */int calcularBitcoin(float aerolineas, float latam, float* pBitcoinAerolineas, float* pBitcoinLatam)
{
	int retorno;
	float bitcoin;

	bitcoin = 4814905.01; //Lo cargo con el valor actual del Bitcoin en pesos
	retorno = -1;

	if(aerolineas > 0 && latam > 0 && pBitcoinAerolineas != NULL && pBitcoinLatam != NULL)//<-- validacion de valores y punteros
	{
		//Calculo el precio en bitcoin del precio de Aerolineas y de Latam. Luego los paso por referencia
		*pBitcoinAerolineas = bitcoin/aerolineas;
		*pBitcoinLatam = bitcoin/latam;
		retorno = 0;
	}


	return retorno;
}

/**@brief Funcion para calcular el precio unitario. Recibe los valores, los divide por los kilometros
 * y devuelve por referencia los resultados a las variables auxiliares
 *
 * @param kilometros Pasa el valor que el usuario ingreso para los kilometros
 * @param aerolineas Recible el valor que el usuario ingreso para el precio de vuelos en Aerolineas
 * @param latam Recible el valor que el usuario ingreso para el precio de vuelos en Latam
 * @param pUnitarioAerolineas Puntero a la variable que guardara auxiliarmente el valor del precio unitario de Aerolineas
 * @param pUnitarioLatam Puntero a la variable que guardara auxiliarmente el valor del precio unitario de Latam
 * @return retorno Retorna -1 si la validacion fallo, por el contrario retorna 0 si fue un exito
 */int calcularPrecioUnitario(float kilometros, float aerolineas, float latam, float* pUnitarioAerolineas, float* pUnitarioLatam)
{
	int retorno;

	retorno = -1;

	if(kilometros > 0 && aerolineas > 0 && latam > 0 && pUnitarioAerolineas != NULL && pUnitarioLatam != NULL)//<-- validacion de punteros
	{
		//Calculo el precio unitario de Aerolineas y de Latam dividiendo precio por los kilometros ingresados
		//y paso el resultado por referencia
		*pUnitarioAerolineas = aerolineas / kilometros;
		*pUnitarioLatam = latam / kilometros;
		 retorno = 0;
	}

	return retorno;
}

/**@brief Funcion para calcular la diferencia de precios. Recibe los valores, ordena el calculo segun cual variable
 * sea mayor o menor, las resta y devuelve por referencia el resultado a las variables auxiliares
 *
 * @param aerolineas Recible el valor que el usuario ingreso para el precio de vuelos en Aerolineas
 * @param latam Recible el valor que el usuario ingreso para el precio de vuelos en Latam
 * @param pDiferencia Puntero a la variable que guardara el valor de la diferencia calculada
 * @return retorno Retorna -1 si la validacion fallo, por el contrario retorna 0 si fue un exito
 */int calcularDiferencia(float aerolineas, float latam, float* pDiferencia)
{
	int retorno;

	retorno = -1;
	if(aerolineas > 0 && latam > 0 && pDiferencia != NULL)//<-- validacion de punteros
	{
		//Pregunto cual de los dos precios es mayor. El que sea mayor se acomoda delante y se le resta el menor.
		//Se pasa la diferencia por puntero
		if(aerolineas >= latam)
		{
			//Pero si ambos precios son iguales se entra por defecto a la primera resta
			*pDiferencia = aerolineas - latam;
			retorno = 0;
		}else if(aerolineas < latam)
		{
			*pDiferencia = latam - aerolineas;
			retorno = 0;
		}
	}


	return retorno;
}
