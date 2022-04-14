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
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
para ofrecerlos a sus clientes.
Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.

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

		//Uso un bucle do while para que el menu se muestre en pantalla desde el comienzo del programa
		//y hasta que el usuario decida salir
		do
		{
			//Invocacion del menu
			switch(menu(kilometros, precioAerolineas, precioLatam))//<-- le paso los valores de los precios para que los muestre en pantalla
			{
				case 1:
					//En caso de que el usuario ingresa la opcion 1 se entra a este case para ingresar los kilometros
					ingresarKilometros(&kilometros, &flagKilometros);
					system("pause");
					break;
				case 2:
					//En caso de que el usuario ingresa la opcion 2 se entra a este case para ingresar los precios de las aerolineas
					ingresarPrecios(&precioAerolineas, &precioLatam, &flagPrecio);
					system("pause");
					break;
				case 3:
					//En caso de que el usuario ingresa la opcion 3 se entra a este case para calcular los precios de las aerolineas
					if(flagKilometros == 1 && flagPrecio == 1)//<--compruebo que el usuario haya ingresado los datos necesarios para empezar a calcular
					{
						printf("\nCalculando costos. Momento...\n");
						if(calcularCostos(kilometros, precioAerolineas, precioLatam, &precioDebitoAerolineas, &precioDebitoLatam, &precioCreditoAerolineas, &precioCreditoLatam, &precioAerolineasBTC, &precioLatamBTC, &precioUnitarioAerolineas, &precioUnitarioLatam, &diferencia) == 0)
						{
							//Si la funcion retorna 0 significa que el calculo se pudo realizar
							printf("Se calculo exitosamente!\n");
						}else
				 		{
				 			//De lo contrario no realiza ninguna operacion y devuelve un mensaje de error
				 			printf("ERROR. No se pudo calcular los costes!\n");
				 		}
						system("pause");
						flagCalcular = 1;
					}else
					{
						//Si el usuario no ingreso los datos muestro este mensaje
						printf("\nNo se pueden realizar los calculos sin haber ingresado todos los datos!\n");
						system("pause");
					}
					break;
				case 4:
					//En caso de que el usuario ingresa la opcion 4 se entra a este case para mostrar los resultados
					if(flagCalcular == 1)//<-- compruebo que se hayan realizado los calculos para poder informarlos
					{
						printf("\nMostrando los costos. Momento...\n");
						informarResultados(precioAerolineas, precioLatam, precioDebitoAerolineas, precioDebitoLatam, precioCreditoAerolineas, precioCreditoLatam, precioAerolineasBTC, precioLatamBTC, precioUnitarioAerolineas, precioUnitarioLatam, diferencia);
						system("pause");
					}else
					{
						//Si no se realizaron los calculos muestra este mensaje
						printf("\nPara informar resultados primero se debe calcular los vuelos ingresados!\n");
						system("pause");
					}
					break;
				case 5:
					//En caso de que el usuario ingresa la opcion 5 se entra a este case para forzar la subida de datos
					printf("\nForzando entrada de datos. Momento...\n");
					cargaForzadaDeDatos();
					system("pause");
					break;
				case 6:
					//En caso de que el usuario ingresa la opcion 6 se entra a este case para confirmar la salida del usuario
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



