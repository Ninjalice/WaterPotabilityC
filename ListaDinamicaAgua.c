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

void insertarEnLista(ListaDinamica *l, tipoAgua elemento)
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

void eliminarDeLista(ListaDinamica *l,int indice)
{
    if (esNulaLista(*l))
        errorLista("No se puede desencolar en una cola vacia.");
    else
    {
        //hace falta hacer esto
    }
}

tipoAgua mostrarElementoLista(ListaDinamica l)
{
    if (esNulaLista(l))
        errorCola("No se puede obtener el primero en una cola vacia.");
    else
        return l.ini->elem; //hace falta cambiar esto
}

bool esNulaLista(ListaDinamica l)
{
    return l.ini == NULL;
}