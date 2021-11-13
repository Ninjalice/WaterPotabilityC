#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "dataSet.h"

void leer(FILE *fp, ListaAguas aguas){	
	char *line = NULL;
	size_t bufsize = 0;
	while ((getline(&line, &bufsize, fp)) != -1)
	{
		char *pt;
		getline(&line, &bufsize, fp);
		pt = strtok(line, ",");
		while (pt != NULL)
		{
			double a = atof(pt);
			pt = strtok(NULL, ",");
			i = i + 1;
		}
	}
	free(line);
}

void normalizar(matriz m){
	
	float min,max,dif;
	
	for(int i = 0; i < 9; i++){
		min = m[i][0];
		max = m[i][0];
		for(int j = 0; j < 2011; j++){
			if(m[j][i] < min){
				min = m[j][i];
			}
			else if(m[j][i] > max){
				max = m[j][i];
			}
		}
		dif = max-min;
		for(int k = 0; k < 2011; k++){
			m[k][i] = ((m[k][i]-min)/(dif));
		}
	}
}


void operar(float *min, int *s, int *pre, matriz m, float f[],float d[], int gr, int a){
	int i, j;
	float aux;
	int e = 0;
	for(i = 0; i<2011-a; i++){
		if(i != gr){
			e++;
			aux = 0;
			for(j = 0; j<9; j++){
				aux = aux + pow((m[i][j]-d[j]),2);
			}
			aux = sqrt(aux);
			if(aux < *min){
				*min = aux;
				*s = e;
				*pre = m[i][j+1];
			}
			f[e-1] = aux;
		}
	}
}

