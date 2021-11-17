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
        int opcion;
        char archivo[32];
        ListaDinamica lista;
        float max[9], min[9], dato;
        tipoAgua Aguita;
     
  
        if (archivo == NULL){ 
  
                printf("\nError de apertura del archivo. \n\n"); 
        } 
        
        else{ 
			do{
				printf("----------MENU-----------\n");
				printf("0-Elegir CSV\n");
				printf("1-Introducir dato\n");
				printf("2-KNN\n");
				printf("3-Algoritmo de Wilson\n");
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
						Aguita->ph = dato;
						printf("Introduzca la dureza: ");
						scanf("%f", &dato);
						Aguita->Hardness = dato;
						printf("Introduzca los solidos: ");
						scanf("%f", &dato);
						Aguita->Solids = dato;
						printf("Introduzca las Cloraminas: ");
						scanf("%f", &dato);
						Aguita->Chloramines = dato;
						printf("Introduzca los sulfatos: ");
						scanf("%f", &dato);
						Aguita->Sulfate = dato;
						printf("Introduzca la conductividad: ");
						scanf("%f", &dato);
						Aguita->Conductivity = dato;
						printf("Introduzca el carbono organico");
						scanf("%f", &dato);
						Aguita->Organic_carbon = dato;
						printf("Introduzca los Trihalometanos");
						scanf("%f", &dato);
						Aguita->Trihalomethanes = dato;
						printf("Introduzca la turbiedad");
						scanf("%f", &dato);
						if(dato > 4)
						{
							printf("Eto ta turbio mi bro");
						}
						Aguita->Turbidity = dato;
						Aguita->Potability = false;
					case 2:
						KNN(&lista, archivo, Aguita);
					case 3:
						Wilson(&lista, archivo);
						
				}
			}while(opcion < 4);
		}
}
