#include "normalizar.h"

void normalizar(ListaDinamica *lista, float maximos[], float minimos[]) // valornormalizado = ((valor - min)/ dif) siendo dif = max - min;
{
    float dif;  
    celdaLista celda;
    tipoAgua elemento;
    PrimeraCeldaLista(lista, celda); 
    for (int i = 0; i < (lista->numAtributos - 1); i++)
    {
        minimos[i] = mostrarElementoCelda(celda){0};
        maximos[i] = mostrarElementoCelda(celda);
        for (int j = 0; j < lista->numeroAguas; j++)
        {
            elemento = mostrarElementoCelda(celda);
            if (elemento{j}; < min)
            {
                minimos[i] = elemento{j};
               
            }
            else if (elemento{j}; > max)
            {
                maximos[i] = elemento{j};
                
            }
            ObtenerSiguiente(celda);
        }
        dif = maximos[i] - minimos[i];
        PrimeraCeldaLista(lista, celda);
        for (int k = 0; k < lista->numeroAguas; k++)
        {
            float valor = ((mostrarElementoCelda(celda){i} - minimos[i]) / (dif)); 
            editarElementoLista(celda,i,valor);
            ObtenerSiguiente(celda);
        }
    }
} 