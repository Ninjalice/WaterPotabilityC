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

void PrimeraCeldaLista(ListaDinamica l, celdaLista *celda);

void ObtenerSiguiente(celdaLista *celda);


tipoAgua mostrarElementoCelda(celdaLista *celda);

void editarElementoLista(celdaLista *celda, int i, float valor);

bool esNulaLista(ListaDinamica l);
