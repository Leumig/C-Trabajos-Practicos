/*
 ============================================================================
 Name        : TP_1.c
 Author      : Miguel Ángel Gil
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Menu.h"
#include "Entradas.h"
#include "Calculos.h"

int main(void) {
	setbuf(stdout, NULL);

	char salir = 'n';
	float kilometros;
	int flagKilometros = 0;
	float precioAerolineas;
	float precioLatam;
	int flagPrecios = 0;
	float precioDebitoAerolineas;
	float precioDebitoLatam;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaPrecio;
	int flagCalculos = 0;
	float kilometrosCF = 7090;
	float precioAerolineasCF = 162965.00;
	float precioLatamCF = 159339.00;

	do
	{
		switch(menu())
		{
		case 1:
			caseKilometros(&flagKilometros, &kilometros, &flagPrecios, &flagCalculos);

		break;

		case 2:
			casePrecios(&flagKilometros, &flagPrecios, &flagCalculos, &precioAerolineas, &precioLatam);

		break;

		case 3:
			if(flagPrecios)
			{
				calcularAerolineas(&precioAerolineas, &precioDebitoAerolineas, &precioCreditoAerolineas,
						           &precioBitcoinAerolineas, &precioUnitarioAerolineas, &kilometros);

				calcularLatam(&precioLatam, &precioDebitoLatam, &precioCreditoLatam,
						      &precioBitcoinLatam, &precioUnitarioLatam, &kilometros);

				calcularDiferencia(&precioAerolineas, &precioLatam, &diferenciaPrecio);

				printf("Cálculos realizados correctamente \n\n");
				flagCalculos = 1;
				flagKilometros = 0;
				flagPrecios = 0;
			}else
			{
				if(flagKilometros == 0)
				{
					printf("Error, primero debe ingresar los kilómetros (opción 1) \n\n");
				}else{
					printf("Error, primero debe ingresar los precios (opción 2) \n\n");
				}
			}
		break;

		case 4:
			if(flagCalculos)
			{
				informarResultados(&precioAerolineas, &precioLatam, &kilometros, &precioDebitoAerolineas, &precioDebitoLatam,
								&precioCreditoAerolineas, &precioCreditoLatam, &precioBitcoinAerolineas, &precioBitcoinLatam,
								&precioUnitarioAerolineas, &precioUnitarioLatam, &diferenciaPrecio);

				flagKilometros = 0;
				flagPrecios = 0;
				flagCalculos = 0;
			}else
			{
				if(flagKilometros == 0)
				{
					printf("Error, primero debe ingresar los kilómetros (opción 1) \n\n");
				}else
				{
					if(flagPrecios == 0)
						{
							printf("Error, primero debe ingresar los precios (opción 2) \n\n");
						}else
						{
							printf("Error, primero debe realizar los cálculos (opción 3) \n\n");
						}
				}
			}
			system("pause");
		break;

		case 5:
			calcularAerolineas(&precioAerolineasCF, &precioDebitoAerolineas, &precioCreditoAerolineas,
							&precioBitcoinAerolineas, &precioUnitarioAerolineas,  &kilometrosCF);

			calcularLatam(&precioLatamCF, &precioDebitoLatam, &precioCreditoLatam,
					      &precioBitcoinLatam, &precioUnitarioLatam,  &kilometrosCF);

			calcularDiferencia(&precioAerolineasCF, &precioLatamCF, &diferenciaPrecio);


			informarResultados(&precioAerolineasCF, &precioLatamCF, &kilometrosCF, &precioDebitoAerolineas, &precioDebitoLatam,
					&precioCreditoAerolineas, &precioCreditoLatam, &precioBitcoinAerolineas, &precioBitcoinLatam,
					&precioUnitarioAerolineas, &precioUnitarioLatam, &diferenciaPrecio);

			system("pause");
		break;
		case 6:
			confirmarSalida(&salir);
		break;

		default:
			printf("Opción incorrecta (debe ser un número del 1 al 6) \n\n");
		}
		system("pause");

	}while(salir!='s');

	printf("Fin del programa");

	return 0;
}
