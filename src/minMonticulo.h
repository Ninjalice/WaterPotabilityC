#include <stdbool.h>
#include "minMonticulo.h"

typedef struct {
	int posicion;
	float distancia;
	bool Potability;
}TipoDistancia;


typedef struct tMM{
	TipoDistancia *array; //array dinamico
	int pos; //indice del ultimo indice del monticulo
	int numEl; // tamaño maximo del monticulo
}tipoMinMonticulo;

void nuevoMinMonticulo(tipoMinMonticulo *, int);

void insertarMinMonticulo(tipoMinMonticulo *, TipoDistancia);

void eliminarElemento(tipoMinMonticulo *, TipoDistancia);

TipoDistancia devolverRaiz(tipoMinMonticulo);

void mostrarAnchura(tipoMinMonticulo);

bool esVacio(tipoMinMonticulo);

bool estaLleno(tipoMinMonticulo);
