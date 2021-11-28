#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CsvReader.h"
#include "normalizar.h"


TipoDistancia esPotable(TipoDistancia distancias[], int n)
{
    int potable = 0;
    int noPotable = 0;
    TipoDistancia distanciaMenor = distancias[0];
    
    for (int i = 0; i < n; i++)
    {
        if (distanciaMenor.distancia > distancias[i].distancia)
        {
            distanciaMenor = distancias[i];
        }
        if (distancias[i].Potability)
        {
            potable++;
        }
        else
        {
            noPotable++;
        }
    }    
    if(potable == noPotable)
    {
        return distanciaMenor;
    }
    else
    {        
        for (int i = 0; i < n; i++)
        {
            if (potable > noPotable )
            {
                if (distanciaMenor.Potability == false)
                {
                    distanciaMenor = distancias[i];
                }
                if (distanciaMenor.distancia > distancias[i].distancia && distancias[i].Potability == true)
                {
                    distanciaMenor = distancias[i];
                }
            }
            else if (noPotable > potable )
            {
                if (distanciaMenor.Potability == true)
                {
                    distanciaMenor = distancias[i];
                }
                if (distanciaMenor.distancia > distancias[i].distancia && distancias[i].Potability == false)
                {
                    distanciaMenor = distancias[i];
                }
            }
        }
        return distanciaMenor;
    }   
    
    
}

float probabilidad(ListaDinamica *datos, int n)
{
    int elementosEliminados = 0;
    bool espotable = NULL;
    tipoMaxMonticulo maxMonticulo;
    celdaLista *celda;
    int posicion = datos->numeroAguas - 1;
    float maximos[datos->numAtributos - 1];
    float minimos[datos->numAtributos - 1];
    tipoAgua entrada;

    nuevoMaxMonticulo(&maxMonticulo, n);
    normalizar(datos, maximos, minimos);
    celda = datos->fin;
    while (celda != NULL && posicion >= 0)
    {
        entrada = celda->elem;
        CalculaDistancia(datos, entrada, &maxMonticulo, n, posicion);
        espotable = esPotable(maxMonticulo.array, n).Potability;

        if (espotable != celda->elem.Potability)
        {            
            elementosEliminados++;
        }
        celda = celda->ant;        
        posicion--;
        borrarMonticulo(&maxMonticulo);
    }
    return ((datos->numeroAguas - (float)elementosEliminados) / datos->numeroAguas);        
}

void knn(int n, tipoAgua entrada , ListaDinamica *datos)
{   
    tipoMaxMonticulo maxMonticulo;
    TipoDistancia distanciaMinima;    
    nuevoMaxMonticulo(&maxMonticulo, n); 

    float maximos[datos->numAtributos - 1];
    float minimos[datos->numAtributos - 1];
    mostrar(datos);
    normalizar(datos, maximos, minimos);
    mostrar(datos);   
    normalizarEntrada(&entrada, maximos,minimos);   
    CalculaDistancia(datos, entrada, &maxMonticulo,n,-1);    
    distanciaMinima = esPotable(maxMonticulo.array, n);
    mostrarAnchura(maxMonticulo);
    printf("La distancia minima esta en la posicion %d y tiene un valor de  %.8f \n",distanciaMinima.posicion , distanciaMinima.distancia);
    printf("RESULTADO FINAL:\n");
    printf("POTABILIDAD: %s \n", distanciaMinima.Potability ? "true" : "false");    
}

int wilson(ListaDinamica *datos , int n)
{
    int elementosEliminados = 0;    
    bool espotable = NULL;
    tipoMaxMonticulo maxMonticulo;      
    celdaLista *celda;
    int posicion = datos->numeroAguas - 1;
    float maximos[datos->numAtributos - 1];
    float minimos[datos->numAtributos - 1];
    tipoAgua entrada;
    
    nuevoMaxMonticulo(&maxMonticulo, n);
    normalizar(datos, maximos, minimos);     
    celda = datos->fin;    
    while (celda != NULL && posicion >= 0)
    {        
        entrada = celda->elem;       
        CalculaDistancia(datos, entrada, &maxMonticulo, n, posicion);
        espotable = esPotable(maxMonticulo.array, n).Potability;

        if (espotable != celda->elem.Potability)
        {
            eliminarElemento(datos, posicion);
            elementosEliminados++;
        }       
        celda = celda->ant;               
        posicion--;        
        borrarMonticulo(&maxMonticulo);       
    }
    return elementosEliminados;    
}

float probabilidad2(ListaDinamica *datos, int n) //solo se usa para obtener la K optima
{
    int elementosEliminados = 0;
    bool espotable = NULL;
    tipoMaxMonticulo maxMonticulo;
    celdaLista *celda;
    int posicion = datos->numeroAguas - 1;
    float maximos[datos->numAtributos - 1];
    float minimos[datos->numAtributos - 1];
    tipoAgua entrada;

    nuevoMaxMonticulo(&maxMonticulo, n);    
    celda = datos->fin;
    while (celda != NULL && posicion >= 0)
    {
        entrada = celda->elem;
        CalculaDistancia(datos, entrada, &maxMonticulo, n, posicion);
        espotable = esPotable(maxMonticulo.array, n).Potability;

        if (espotable != celda->elem.Potability)
        {
            elementosEliminados++;
        }
        celda = celda->ant;
        posicion--;
        borrarMonticulo(&maxMonticulo);
    }
    return ((datos->numeroAguas - (float)elementosEliminados) / datos->numeroAguas);
}

int ObtenerMejorN(ListaDinamica *datos)
{
    float mejorProbabilidad, prob;
    mejorProbabilidad = 0.0;
    int mejorN = 1;
    float maximos[datos->numAtributos - 1];
    float minimos[datos->numAtributos - 1];

    normalizar(datos, maximos, minimos);

    for (int i = 1; i < datos->numeroAguas; i++)
    {
        prob = probabilidad2(datos, i);
        if (prob > mejorProbabilidad)
        {
            mejorN = i;
            mejorProbabilidad = prob;
        }
        printf("La probabilidad de %d es %.5f\n", i, prob);
    }
    printf("La mejor probabilidad de %d es %.5f\n", mejorN, mejorProbabilidad);
    return mejorN;
}
