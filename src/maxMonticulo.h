#ifndef MAXMONTICULO
#define MAXMONTICULO

#include <stdbool.h>

typedef struct
{
    int posicion;
    float distancia;
    bool Potability;
} TipoDistancia;

typedef struct tMM
{
    TipoDistancia *array; //array dinamico
    int pos;              //indice del ultimo indice del monticulo
    int numEl;            // tamaño maximo del monticulo
} tipoMaxMonticulo;

void nuevoMaxMonticulo(tipoMaxMonticulo *, int);

void insertarMaxMonticulo(tipoMaxMonticulo *, TipoDistancia);

void eliminarElementoRaiz(tipoMaxMonticulo *);

TipoDistancia devolverRaiz(tipoMaxMonticulo);

void mostrarAnchura(tipoMaxMonticulo);

bool esVacio(tipoMaxMonticulo);

bool estaLleno(tipoMaxMonticulo);

#endif