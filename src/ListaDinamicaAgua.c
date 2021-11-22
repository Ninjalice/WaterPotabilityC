#include "ListaDinamicaAgua.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void eliminarElemento(ListaDinamica *l, int posicion)
{
    
    if (esNulaLista(*l))
    {
        errorLista("No se puede eliminar elemento de lista.");
    }
    else
    {
        celdaLista *celda;
        int i;
        celda = l->ini;
        while (celda != NULL && i < posicion)
        {
            i = i++;
            celda = celda->sig;
        }
        if (i != posicion)
        {
            errorLista("No se puede eliminar elemento de lista en la posicion dada.");
        }
        else
        {
            if(celda->ant == NULL)
            {                
                celda->sig->ant = NULL;
                l->ini = celda->sig;                
            }
            else if (celda->sig == NULL)
            {
                celda->ant->sig = NULL;
                l->fin = celda->ant;                
            }
            else
            {
                celda->ant->sig = celda->sig;
                celda->sig->ant = celda->ant;
            }
            l->numeroAguas = l->numeroAguas - 1;
            free(celda);
        }
            
    }
    
}

void PrimeraCeldaLista(ListaDinamica *l , celdaLista *celda)
{    
    if (esNulaLista(*l))
        errorLista("No se puede obtener elemento.");
    else
    {        
        celda = l->ini;
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

bool esNulaLista(ListaDinamica l)
{
    return l.ini == NULL;
}