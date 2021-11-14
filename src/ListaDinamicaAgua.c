#include "ListaDinamicaAgua.h"

void nuevaLista(ListaDinamica *l)
{
    l->ini = NULL;
    l->fin = NULL;
    l->numAtributos = 0;
    l->numeroAguas = 0;
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
    if (esNulaLista(*l))
    {
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        l->ini = nuevo;
    }
    else
    {
        l->fin->sig = nuevo;
        nuevo->ant = l->fin;
        nuevo->sig = NULL;
    }
    l->fin = nuevo;
}

void PrimeraCeldaLista(ListaDinamica l , celdaLista *celda)
{
    if (esNulaLista(l))
        errorLista("No se puede obtener elemento.");
    else
    {        
        celda = l.ini;
    }
}

void ObtenerSiguiente(celdaLista *celda)
{
    if (celda == NULL)
        errorLista("No se puede obtener elemento.");
    else
    {
        celda = celda->sig;
    }
}

tipoAgua mostrarElementoCelda(celdaLista *celda)
{
    if (celda == NULL)
        errorLista("No se puede obtener elemento.");
    else
    {
        return celda->elem;
    }
}

void editarElementoLista(celdaLista *celda, int  i , float valor)
{
    if (celda == NULL)
        errorLista("No se puede editar elemento.");
    else
    {
        (celda->elem){i} = valor;
    }
}

bool esNulaLista(ListaDinamica l)
{
    return l.ini == NULL;
}