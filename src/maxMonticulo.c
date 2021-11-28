#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "maxMonticulo.h"

void intercambiar(tipoMaxMonticulo *m, int pos1, int pos2)
{
    TipoDistancia aux;
    aux = m->array[pos2];
    m->array[pos2] = m->array[pos1];
    m->array[pos1] = aux;
}

void nuevoMaxMonticulo(tipoMaxMonticulo *M, int x)
{
    M->array = (TipoDistancia *)malloc(x * sizeof(TipoDistancia));
    M->numEl = x;
    M->pos = -1;
}

void insertarMaxMonticulo(tipoMaxMonticulo *M, TipoDistancia e)
{
    M->pos++;
    M->array[M->pos] = e;
    int aux = M->pos;
    while ((aux != 0) && ((M->array[aux]).distancia > (M->array[(aux - 1) / 2]).distancia))
    {
        intercambiar(M, aux, (aux - 1) / 2);
        aux = (aux - 1) / 2;
    }
}

void eliminarElementoRaiz(tipoMaxMonticulo *M)
{
    int i = 0;
    M->array[i] = M->array[M->pos];
    M->pos--;
    while ((i * 2) + 2 <= M->pos && (M->array[i].distancia < M->array[(i * 2) + 1].distancia || M->array[i].distancia < M->array[(i * 2) + 2].distancia))
    {
        if (M->array[(i * 2) + 1].distancia < M->array[(i * 2) + 2].distancia)
        {
            intercambiar(M, i, (i * 2) + 2);
            i = (i * 2) + 2;
        }
        else
        {
            intercambiar(M, i, (i * 2) + 1);
            i = (i * 2) + 1;
        }
    }
    if ((i * 2) + 1 <= M->pos && M->array[(i * 2) + 1].distancia > M->array[i].distancia)
    {
        intercambiar(M, i, (i * 2) + 1);
    }
}

void borrarMonticulo(tipoMaxMonticulo *M)
{    
    M->pos = -1;    
}
TipoDistancia devolverRaiz(tipoMaxMonticulo M)
{
    return (M.array[0]);
}

void mostrarAnchura(tipoMaxMonticulo M)
{
    printf("Distancias: ");
    for (int i = 0; i < M.numEl; i++)
    {
        printf(" %.2f ", M.array[i].distancia);
    }
    printf("\n");

    printf("Posicion: ");
    for (int i = 0; i < M.numEl; i++)
    {
        printf(" %d", M.array[i].posicion);
    }
    printf("\n");

    printf("Potability: ");
    for (int i = 0; i < M.numEl; i++)
    {
        printf(" %s ", M.array[i].Potability ? "true" : "false");
    }
    printf("\n");
}

bool esVacio(tipoMaxMonticulo M)
{
    return (M.pos == -1);
}

bool estaLleno(tipoMaxMonticulo M)
{
    return (M.pos == (M.numEl - 1));
}
