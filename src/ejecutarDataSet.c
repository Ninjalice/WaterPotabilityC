#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "CsvReader.h"
#include "ListaDinamicaAgua.h"
#include "normalizar.h"

int main(int argc, char** argv) 
{ 
        FILE *archivo; 
        int opcion, n;
        char archivo[32];
        ListaDinamica lista;
        float max[9], min[9], dato;
        tipoAgua Aguita;
		n = 1;
     
  
        if (archivo == NULL){ 
  
                printf("\nError de apertura del archivo. \n\n"); 
        } 
        
        else{ 
			do{
				printf("----------MENU-----------\n");
				printf("0-Elegir CSV\n");
				printf("1-Introducir dato\n");
				printf("2-Introduce el numero de distancias a comparar\n")
				printf("3-KNN\n");
				printf("4-Algoritmo de Wilson\n");
				printf("5-Punteria\n")
				printf("Escoja una opción: ");
				scanf("%d", &opcion);
				switch(opcion){
					case 0:
						printf("Introduzca el nombre del archivo: ");
						scanf("%s",archivo); 
						LeerCSV(archivo, &lista);
					case 1:
						printf("Introduzca el ph: ");
						scanf("%f", &dato);
						Aguita.ph = dato;
						printf("Introduzca la dureza: ");
						scanf("%f", &dato);
						Aguita.Hardness = dato;
						printf("Introduzca los solidos: ");
						scanf("%f", &dato);
						Aguita.Solids = dato;
						printf("Introduzca las Cloraminas\n");
						scanf("%f", &dato);
						Aguita.Chloramines = dato;
						printf("Introduzca los sulfatos\n");
						scanf("%f", &dato);
						Aguita.Sulfate = dato;
						printf("Introduzca la conductividad\n");
						scanf("%f", &dato);
						Aguita.Conductivity = dato;
						printf("Introduzca el carbono organico\n");
						scanf("%f", &dato);
						Aguita.Organic_carbon = dato;
						printf("Introduzca los Trihalometanos\n");
						scanf("%f", &dato);
						Aguita.Trihalomethanes = dato;
						printf("Introduzca la turbiedad\n");
						scanf("%f", &dato);
						Aguita.Turbidity = dato;
						Aguita.Potability = NULL;
					case 2:
						printf("Introduce el numero de distancias a comparar\n");
						scanf("%f", &n);
					case 3:
						knn(n, archivo, Aguita, &lista);
					case 4:
						wilson(&lista, n);
					case 5:
						probabilidad(&lista);
						
				}
			}while(opcion < 6 && opcion > 0);
		}
}
