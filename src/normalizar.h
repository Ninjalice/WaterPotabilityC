#include "ListaDinamicaAgua.h"

void ObtenerMaxMins(ListaDinamica *lista, float maximos[], float minimos[]);// valornormalizado = ((valor - min)/ dif) siendo dif = max - min;


void InicializarMaxMins(celdaLista *celda, float maximos[], float minimos[]);


void normalizar(ListaDinamica *lista, float maximos[], float minimos[]); // valornormalizado = ((valor - min)/ dif) siendo dif = max - min;
