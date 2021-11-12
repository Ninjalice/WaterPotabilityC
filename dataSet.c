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

float pasarFloat(char caracteres[], int g){
	float entero;
	if(g == 1){
		entero = caracteres[0]-48;
		return(entero);
	}
	else{
		float decimal;
		int i, j, k;
		entero = 0;
		j = 1;
	
		for(i=0; caracteres[i]>47 && caracteres[i]<58; i++){
			//encontrar punto
			doNothing();
		}
		
		for(k=i-1; k>-1; k--){
			entero = entero + (caracteres[k]-48)*j;
			j = j * 10;
		}
		
		if(caracteres[i] == '.'){
			i++;
			for(k=1; caracteres[i]!='\0'; k++){
				decimal = caracteres[i] - 48;
				for(j=0; j<k; j++){
					decimal = decimal * 0.1;
				}
				entero = entero + decimal;
				i++;
			}
		}
		return entero;
	}
}

void imprimirBonito(matriz m, int n, int a){
	float j1[2011],j2[2011],j3[2011],j4[2011],j5[2011],j6[2011],j7[2011],j8[2011],j9[2011],j10[2011];
	for(int i = 0; i < 2011; i++){
		j1[i] = m[i][0];
		j2[i] = m[i][1];
		j3[i] = m[i][2];
		j4[i] = m[i][3];
		j5[i] = m[i][4];
		j6[i] = m[i][5];
		j7[i] = m[i][6];
		j8[i] = m[i][7];
		j9[i] = m[i][8];
		j10[i] = m[i][9];
	}
	int ancho = -10;

	printf("%d|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",0,ancho, "PH", ancho,"Hardness", ancho, "Solids",ancho, "Chloramins", ancho,"Sulfate", ancho, "Conductive",ancho, "OrCarbon", ancho,"Trihalo.", ancho, "Turbidity",ancho,"Potability");
	printf("+---------------------------------------------------------+----------------------------------------------------+\n");
	for(int i = 0; i < n-a; i++){
		printf("%d|%*.2f|%*.2f|%*.2f|%*.2f|%*.2f|%*.2f|%*.2f|%*.2f|%*.2f|%*.2f|\n",i+1, ancho, j1[i], ancho,j2[i], ancho, j3[i],ancho, j4[i], ancho, j5[i], ancho, j6[i],ancho, j7[i], ancho, j8[i], ancho, j9[i],ancho, j10[i]);
	}
	printf("+---------------------------------------------------------+----------------------------------------------------+\n");
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

void doNothing(){
	
}

void nn(float d[], matriz m, int clase, int i, int *a){
	float f[2011], g[20110];
	int s = 0;
	int k = 0;
	int pre = 0;
	float min = 7;
	
	
	operar(&min,&s,&pre,m,f,d,i,*a);
	if(i == -1){
		printf("Closest example: e = %d\n", s);
		printf("Min distance = %f\n", min);
		printf("Prediction: Class = %d\n", pre);
		if(clase == pre){
			printf("Prediction success = true\n");
		}
		else{
			printf("Prediction success = false\n");
		}
	}
	else{
		if(clase != pre){
			//printf("%d\n", i);
			*a = *a + 1;
			for(int l = 0; l<2011-(*a);l++){
				if(l == i){
					for(int j = 0; j < 10; j++){
						doNothing();
					}
				}
				else{
					for(int j = 0; j < 10; j++){
						g[k] = m[l][j];
						k++;
					}
				}
			}
			k = 0;
			for(int l = 0; l<2011-*a-1; l++){
				for(int j = 0; j < 10; j++){
					m[l][j] = g[k];
					k++;
				}
			}
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

void wilson(matriz m, int *a){
	for(int i = 0; i<2011-*a; i++){
		nn(m[i], m, m[i][9], i, a);
	}
}

void nn2(float d[], matriz m, int c){
	float f[2011];
	int op;
	int e = 0;
	int s = 0;
	int i, j, pre2;
	float aux = 0;
	float min = 7;
	float pre;
	
	normalizar2(m,d);
	
	for(i = 0; i<2011; i++){
		e++;
		aux = 0;
		for(j = 0; j<9; j++){
			aux = aux + pow((m[i][j]-d[j]),2);
		}
		aux = sqrt(aux);
		if(aux < min){
			min = aux;
			s = e;
			pre = m[i][9];
		}
		f[e-1] = aux;
	}
	printf("Closest example: e = %d\n", s);
	printf("Min distance = %f\n", min);
	pre2 = pre;
	printf("Predicition: Class = %d\n", pre2); 
	if(c == pre){
		printf("Prediction success: true\n");
	}
	else{
		printf("Prediction success: false\n");
	}
	
	while(true){
		printf("Introduce numero: ");
		scanf("%d", &op);
		printf("%f\n", f[op-1]);
	}
}

void normalizar2(matriz m, float d[]){
	
	float min,max,dif;
	
	for(int i = 0; i < 9; i++){
		min = d[i];
		max = d[i];
		for(int j = 0; j < 2011; j++){
			if(m[j][i] < min){
				min = m[j][i];
			}
			else if(m[j][i] > max){
				max = m[j][i];
			}
		}
		dif = max-min;
		d[i] = ((d[i]-min)/(dif));
		for(int k = 0; k < 2011; k++){
			m[k][i] = ((m[k][i]-min)/(dif));
		}
	}
}
