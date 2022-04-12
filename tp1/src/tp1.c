/*
 ============================================================================
 Name        : tp1.c
 Author      : Tom
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
/* ENUNCIADO:
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.

Cheride Thomas
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menu.h"
#include "calculos.h"

int main(void) {
		setbuf(stdout, NULL);

		//Inicializacion de variables
		int flagKilometros;
		int flagPrecio;
		int flagCalcular;
		float kilometros;
		float precioAerolineas;
		float precioLatam;
		float precioDebitoAerolineas;
		float precioDebitoLatam;
		float precioCreditoAerolineas;
		float precioCreditoLatam;
		float precioAerolineasBTC;
		float precioLatamBTC;
		float precioUnitarioAerolineas;
		float precioUnitarioLatam;
		float diferencia;
		char salir;

		//Declaracion de variables
		flagKilometros = 0;
		flagPrecio = 0;
		flagCalcular = 0;
		precioAerolineas = 0;
		precioLatam = 0;

		do
		{
			//Invocacion del menu
			switch(menu(kilometros, precioAerolineas, precioLatam))//<-- le paso los valores de los precios para que los muestre en pantalla
			{
				case 1:
					ingresarKilometros(&kilometros, &flagKilometros);
					system("pause");
					break;
				case 2:
					ingresarPrecios(&precioAerolineas, &precioLatam, &flagPrecio);
					system("pause");
					break;
				case 3:
					if(flagKilometros == 1 && flagPrecio == 1)
					{
						printf("\nCalculando costos. Momento...\n");
						if(calcularCostos(kilometros, precioAerolineas, precioLatam, &precioDebitoAerolineas, &precioDebitoLatam, &precioCreditoAerolineas, &precioCreditoLatam, &precioAerolineasBTC, &precioLatamBTC, &precioUnitarioAerolineas, &precioUnitarioLatam, &diferencia) == 0)
						{
							printf("Se calculo exitosamente!\n");
						}else
				 		{
				 			//De lo contrario no realiza ninguna operacion y devuelve un mensaje de error
				 			printf("ERROR. No se pudo calcular los costes!\n");
				 		}
						system("pause");
						flagCalcular = 1;
					}else if(flagKilometros == 0 && flagPrecio == 0)
					{
						printf("\nNo se pueden realizar los calculos sin haber ingresado todos los datos!\n");
						system("pause");
					}
					break;
				case 4:
					if(flagCalcular == 1)
					{
						printf("\nMostrando los costos. Momento...\n");
						informarResultados(precioAerolineas, precioLatam, precioDebitoAerolineas, precioDebitoLatam, precioCreditoAerolineas, precioCreditoLatam, precioAerolineasBTC, precioLatamBTC, precioUnitarioAerolineas, precioUnitarioLatam, diferencia);
						system("pause");
					}else
					{
						printf("\nPara informar resultados primero se debe calcular los vuelos ingresados!\n");
						system("pause");
					}
					break;
				case 5:
					printf("\nForzando entrada de datos. Momento...\n");
					cargaForzadaDeDatos();
					system("pause");
					break;
				case 6:
					confirmarSalida(&salir);
					if(salir == 's')
					{
						printf("\nSaliendo...\n");
					}else if(salir == 'n')
					{
						printf("\nRegresando...\n");
					}
					break;
			}
		}while(salir != 's');


	return EXIT_SUCCESS;
}



