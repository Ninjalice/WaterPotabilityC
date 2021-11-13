#include <stdbool.h>

typedef float tipoElementoMinMonticulo;

typedef struct tMM{
	tipoElementoMinMonticulo *array; //array dinamico
	int pos; //indice del ultimo indice del monticulo
	int numEl; // tamaño maximo del monticulo
}tipoMinMonticulo;

void nuevoMinMonticulo(tipoMinMonticulo *, int);

void insertarMinMonticulo(tipoMinMonticulo *, tipoElementoMinMonticulo);

void eliminarElemento(tipoMinMonticulo *, tipoElementoMinMonticulo);

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo);

void mostrarAnchura(tipoMinMonticulo);

bool esVacio(tipoMinMonticulo);

bool estaLleno(tipoMinMonticulo);
