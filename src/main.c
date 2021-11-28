#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "CsvReader.h"
#include "ListaDinamicaAgua.h"
#include "normalizar.h"
#include "knn.h"

int main(int argc, char **argv)
{
	int opcion, n;
	char archivo[128];
	ListaDinamica datos;
	float maximos[9], minimos[9], dato;
	tipoAgua entrada;
	n = 1;
	printf("\n\n----------WaterPotability-----------\n");
	printf("Programa creado por Wassim, Karolina, Andres y Endika\n");
	printf("Gracias por usarlo!\n");
	printf("\n\n------------------------------------\n");
	do
	{		
		printf("\n\n----------------MENU----------------\n");
		printf("0-Elegir CSV (Nombre del fichero)\n");
		printf("1-Introducir dato\n");
		printf("2-Introduce el numero de distancias a comparar\n");
		printf("3-KNN (Debes introducir antes la K usando el menu 2)\n");
		printf("4-Algoritmo de Wilson (Debes introducir antes la K usando el menu 2)\n");
		printf("5-Probabilidad\n");
		printf("6-Entrada Automatica (Para hacer tests)\n");
		printf("7-K optima (Puede tardar minutos en calcular)\n");
		printf("8-Wilson optimo\n");
		printf("9-Probabilidad optima\n");
		printf("10-Mostrar datos\n");
		printf("11-Normalizar datos\n");
		printf("99-EXIT\n");
		printf("------------------------------------\n\n");
		printf("Escoja una opción: ");
		scanf("%d", &opcion);
		printf("\n------------------------------------\n\n");

		switch (opcion)
		{
		case 0:
			printf("Introduzca el nombre del archivo: ");
			scanf("%s", archivo);
			printf("\n-------------------------\n\n");
			nuevaLista(&datos);
			LeerCSV(archivo, &datos);
			break;
		case 1:
			printf("Introduzca el ph: ");
			scanf("%f", &dato);
			entrada.ph = dato;
			printf("Introduzca la dureza: ");
			scanf("%f", &dato);
			entrada.Hardness = dato;
			printf("Introduzca los solidos: ");
			scanf("%f", &dato);
			entrada.Solids = dato;
			printf("Introduzca las Cloraminas\n");
			scanf("%f", &dato);
			entrada.Chloramines = dato;
			printf("Introduzca los sulfatos\n");
			scanf("%f", &dato);
			entrada.Sulfate = dato;
			printf("Introduzca la conductividad\n");
			scanf("%f", &dato);
			entrada.Conductivity = dato;
			printf("Introduzca el carbono organico\n");
			scanf("%f", &dato);
			entrada.Organic_carbon = dato;
			printf("Introduzca los Trihalometanos\n");
			scanf("%f", &dato);
			entrada.Trihalomethanes = dato;
			printf("Introduzca la turbiedad\n");
			scanf("%f", &dato);
			entrada.Turbidity = dato;
			entrada.Potability = NULL;
			break;
		case 2:
			printf("Introduce el numero de distancias a comparar\n");
			scanf("%d", &n);
			printf("Distancias a comparar: %d \n", n);
			break;
		case 3:
			knn(n, entrada, &datos);
			break;
		case 4:
			printf("Se han eliminado %d elementos \n", wilson(&datos, n));
			break;
		case 5:
			printf("La probabilidad es %.5f \n", probabilidad(&datos, n));
			break;
		case 6:
			entrada.ph = 8.32;
			entrada.Hardness = 214.37;
			entrada.Solids = 22018.42;
			entrada.Chloramines = 8.06;
			entrada.Sulfate = 356.89;
			entrada.Conductivity = 363.27;
			entrada.Organic_carbon = 18.44;
			entrada.Trihalomethanes = 100.34;
			entrada.Turbidity = 4.63;
			entrada.Potability = NULL;
			break;		
		case 7:
			normalizar(&datos, maximos, minimos);
			printf("El numero mas optimo para K es %d \n", ObtenerMejorN(&datos));					
			break;
		case 8:
			printf("Se han eliminado %d elementos \n", wilson(&datos, n));
			break;
		case 9:
			printf("La probabilidad es %.5f \n", probabilidad(&datos, n));
			break;
		case 10:
			mostrar(&datos);
			break;
		case 11:
			normalizar(&datos, maximos, minimos);
			printf("Los datos han sido normalizados pulse 10 para mostrarlos\n");
			break;

		}
	} while (opcion < 12 && opcion >= 0);
}
