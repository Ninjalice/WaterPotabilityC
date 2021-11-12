#include "ListaDinamicaAgua.h"

void nuevaLista(ListaDinamica *l)
{
    l->ini = NULL;
    l->fin = NULL;
}

void errorLista(char s[])
{
    printf("\n\n\nERROR en el modulo cola: %s \n", s);
    exit(1);
}

void encolar(ListaDinamica *l, tipoAgua elemento)
{
    celdaLista *nuevo;
    nuevo = (celdaLista *)malloc(sizeof(celdaLista));
    nuevo->elem = elemento;
    nuevo->sig = NULL;
    if (l->fin == NULL)
    {
        l->ini = nuevo;
    }
    else
    {
        l->fin->sig = nuevo;
    }
    l->fin = nuevo;
}

void desencolar(ListaDinamica *l)
{
    if (esNulaLista(*l))
        errorLista("No se puede desencolar en una cola vacia.");
    else
    {
        celdaLista *aux;
        aux = l->ini;
        l->ini = (l->ini)->sig;
        if (l->ini == NULL)
        {
            l->fin = NULL;
        }
        free(aux);
    }
}

tipoAgua frente(ListaDinamica l)
{
    if (esNulaLista(l))
        errorCola("No se puede obtener el primero en una cola vacia.");
    else
        return l.ini->elem;
}

bool esNulaLista(ListaDinamica l)
{
    return l.ini == NULL;
}