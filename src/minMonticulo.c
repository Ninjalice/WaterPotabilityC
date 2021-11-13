#include "minMonticulo.h"
#include <stddef.h>

void intercambiar(tipoMinMonticulo *m, int pos1, int pos2)
{
    tipoElementoMinMonticulo aux;
    aux = m->array[pos2];
    m->array[pos2] = m->array[pos1];
    m->array[pos1] = aux;
}

void nuevoMinMonticulo(tipoMinMonticulo *M, int x)
{
    (*M).array = (tipoElementoMinMonticulo *)malloc(x * sizeof(tipoElementoMinMonticulo));
    (*M).numEl = x;
    (*M).pos = -1;
}

void insertarMinMonticulo(tipoMinMonticulo *M, tipoElementoMinMonticulo e)
{
    int aux;
    M->pos++;
    M->array[M->pos] = e;
    aux = M->pos;
    while ((aux != 0) && M->array[aux] < M->array[(aux - 1) / 2])
    {
        intercambiar(M, aux, (aux - 1) / 2);
        aux = (aux - 1) / 2;
    }
}

void eliminarElemento(tipoMinMonticulo *M, tipoElementoMinMonticulo e)
{
    int i;
    i = 0;
    while (i < M->pos + 1 && M->array[i] != e)
    {
        i++;
    }
    if (M->array[i] == e)
    {
        M->array[i] = M->array[M->pos];
        M->pos--;
        while ((i * 2) + 2 <= M->pos && (M->array[i] > M->array[(i * 2) + 1] || M->array[i] > M->array[(i * 2) + 2]))
        {
            if (M->array[(i * 2) + 1] > M->array[(i * 2) + 2])
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
        if ((i * 2) + 1 <= M->pos && M->array[(i * 2) + 1] < M->array[i])
            intercambiar(M, i, (i * 2) + 1);
    }
    else
        printf("El elemento no esta en el monticulo\n");
}
tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo M)
{
    return (M.array[0]);
}

void mostrarAnchura(tipoMinMonticulo M)
{
    for (int i = 0; i < M.numEl; i++)
    {
        printf(" %d ", M.array[i]);
    }
}

bool esVacio(tipoMinMonticulo M)
{
    return (M.pos = -1);
}

bool estaLleno(tipoMinMonticulo M)
{
    return (M.pos = M.numEl - 1);
}
