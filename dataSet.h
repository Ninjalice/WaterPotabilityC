#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct 
{
	float ph;
	float Hardness;
	float Solids;
	float Chloramines;
	float Sulfate;
	float Conductivity;
	float Organic_carbon;
	float Trihalomethanes;
	float Turbidity;
	bool Potability;
} Agua;

typedef Agua ListaAguas[2011];

void leer(FILE *archivo, float f[], matriz m);
float pasarFloat(char rt[], int g);
void imprimirBonito(matriz m, int n, int a);
void normalizar(matriz m);
void doNothing();
void operar(float *min, int *s, int *pre, matriz m, float f[], float d[], int gr, int a);
void nn(float d[], matriz m, int clase, int i, int *a);
void wilson(matriz m, int *a);
void nn2(float d[], matriz m, int c);
void normalizar2(matriz m, float d[]);
