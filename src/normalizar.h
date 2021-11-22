#ifndef NORMALIZAR
#define NORMALIZAR

#include "ListaDinamicaAgua.h"
#include "maxMonticulo.h"

void ObtenerMaxMins(ListaDinamica *lista, float maximos[], float minimos[]);


void InicializarMaxMins(celdaLista *celda, float maximos[], float minimos[]);


void normalizar(ListaDinamica *lista, float maximos[], float minimos[]);

void normalizarEntrada(tipoAgua *entrada, float maximos[], float minimos[]);

void CalculaDistancia(ListaDinamica *lista, tipoAgua entrada, tipoMaxMonticulo *distancias, int n);

void mostrar(ListaDinamica *lista);

#endif