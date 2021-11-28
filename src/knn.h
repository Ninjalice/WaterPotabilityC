#ifndef KNN
#define KNN

#include "ListaDinamicaAgua.h"
#include "maxMonticulo.h"

TipoDistancia esPotable(TipoDistancia distancias[], int n);

float probabilidad(ListaDinamica *datos, int n);

void knn(int n, tipoAgua entrada, ListaDinamica *datos);

int wilson(ListaDinamica *datos, int n);

float probabilidad2(ListaDinamica *datos, int n);

int ObtenerMejorN(ListaDinamica *datos);

#endif