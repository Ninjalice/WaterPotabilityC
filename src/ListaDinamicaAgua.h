#ifndef LISTA_DINAMICA
#define LISTA_DINAMICA

#include <stdbool.h>

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

} tipoAgua;

typedef struct celdaL
{
    tipoAgua elem;
    struct celdaL *sig;
    struct celdaL *ant;
} celdaLista;

typedef struct 
{
    celdaLista *ini;
    celdaLista *fin;
    int numeroAguas;
    int numAtributos;
} ListaDinamica;

void nuevaLista(ListaDinamica *l);


void errorLista(char s[]);


void insertarEnLista(ListaDinamica *l, tipoAgua elemento);

void PrimeraCeldaLista(ListaDinamica *l, celdaLista *celda);

void eliminarElemento(ListaDinamica *l, int posicion);

void ObtenerSiguiente(celdaLista *celda);

tipoAgua mostrarElementoCelda(celdaLista *celda);

bool esNulaLista(ListaDinamica l);

#endif