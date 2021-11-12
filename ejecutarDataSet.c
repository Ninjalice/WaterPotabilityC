#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "dataSet.h"

int main(int argc, char** argv) 
{ 
        FILE *archivo; 
        float f[20110], d[9], c;
        matriz m;
        int a = 0;
        int n, opcion, ac;
        archivo = fopen(argv[1],"r"); 
  
        if (archivo == NULL){ 
  
                printf("\nError de apertura del archivo. \n\n"); 
        } 
        else{ 
			leer(archivo, f, m);
			do{
				printf("----------MENU-----------\n");
				printf("1-Mostrar tabla de datos\n");
				printf("2-Normalizar tabla de datos\n");
				printf("3-Mostrar resultado\n");
				printf("4-Algoritmo de Wilson\n");
				printf("Escoja una opción: ");
				scanf("%d", &opcion);
				switch(opcion){
					case 1:
						printf("¿Cuántas filas quieres ver? MAXIMO = %d: ", 2011-a);
						scanf("%d", &n);
						if(n <= 2011-a){
							imprimirBonito(m,n,0);
						}
						else{
							printf("No hay suficientes filas de datos\n");
						}
						break;
					case 2:
						normalizar(m);
						printf("Matriz normalizada\n");
						break;
					case 3:
						printf("Introduce los valores de las nueve columnas: ");
						for(int i = 0; i<9; i++){
							scanf("%f", &d[i]);
						}
						printf("Introduce el valor de la clase: ");
						scanf("%f", &c);
						nn2(d,m,c);
						break;
						
					case 4:
						wilson(m,&a);
						printf("Eliminadas %d filas \n", a);
						break;
				}
			}while(opcion < 5);
		}
}
