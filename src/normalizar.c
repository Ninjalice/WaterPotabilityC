#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "normalizar.h"

void ObtenerMaxMins(ListaDinamica *lista, float maximos[], float minimos[]) 
{
    celdaLista *celda;
    celda = lista->ini;
    InicializarMaxMins(celda, maximos, minimos);
    while (celda != NULL)
    {
        // MINIMOS
        if (minimos[0] > celda->elem.ph)
        {
            minimos[0] = celda->elem.ph;
        }
        if (minimos[1] > celda->elem.Hardness)
        {
            minimos[1] = celda->elem.Hardness;
        }
        if (minimos[2] > celda->elem.Solids)
        {
            minimos[2] = celda->elem.Solids;
        }
        if (minimos[3] > celda->elem.Chloramines)
        {
            minimos[3] = celda->elem.Chloramines;
        }
        if (minimos[4] > celda->elem.Sulfate)
        {
            minimos[4] = celda->elem.Sulfate;
        }
        if (minimos[5] > celda->elem.Conductivity)
        {
            minimos[5] = celda->elem.Conductivity;
        }
        if (minimos[6] > celda->elem.Organic_carbon)
        {
            minimos[6] = celda->elem.Organic_carbon;
        }
        if (minimos[7] > celda->elem.Trihalomethanes)
        {
            minimos[7] = celda->elem.Trihalomethanes;
        }
        if (minimos[8] > celda->elem.Turbidity)
        {
            minimos[8] = celda->elem.Turbidity;
        }

        // MAXIMOS
        if (maximos[0] < celda->elem.ph)
        {
            maximos[0] = celda->elem.ph;
        }
        if (maximos[1] < celda->elem.Hardness)
        {
            maximos[1] = celda->elem.Hardness;
        }
        if (maximos[2] < celda->elem.Solids)
        {
            maximos[2] = celda->elem.Solids;
        }
        if (maximos[3] < celda->elem.Chloramines)
        {
            maximos[3] = celda->elem.Chloramines;
        }
        if (maximos[4] < celda->elem.Sulfate)
        {
            maximos[4] = celda->elem.Sulfate;
        }
        if (maximos[5] < celda->elem.Conductivity)
        {
            maximos[5] = celda->elem.Conductivity;
        }
        if (maximos[6] < celda->elem.Organic_carbon)
        {
            maximos[6] = celda->elem.Organic_carbon;
        }
        if (maximos[7] < celda->elem.Trihalomethanes)
        {
            maximos[7] = celda->elem.Trihalomethanes;
        }
        if (maximos[8] < celda->elem.Turbidity)
        {
            maximos[8] = celda->elem.Turbidity;
        }

        celda = celda->sig;
    }
}

void InicializarMaxMins(celdaLista *celda, float maximos[], float minimos[])
{
    printf("InicializarMaxMins\n");
    minimos[0] = celda->elem.ph;
    minimos[1] = celda->elem.Hardness;
    minimos[2] = celda->elem.Solids;
    minimos[3] = celda->elem.Chloramines;
    minimos[4] = celda->elem.Sulfate;
    minimos[5] = celda->elem.Conductivity;
    minimos[6] = celda->elem.Organic_carbon;
    minimos[7] = celda->elem.Trihalomethanes;
    minimos[8] = celda->elem.Turbidity;

    maximos[0] = celda->elem.ph;
    maximos[1] = celda->elem.Hardness;
    maximos[2] = celda->elem.Solids;
    maximos[3] = celda->elem.Chloramines;
    maximos[4] = celda->elem.Sulfate;
    maximos[5] = celda->elem.Conductivity;
    maximos[6] = celda->elem.Organic_carbon;
    maximos[7] = celda->elem.Trihalomethanes;
    maximos[8] = celda->elem.Turbidity;
}

void normalizar(ListaDinamica *lista, float maximos[], float minimos[]) 
{
    printf("normalizar\n");
    float dif;
    celdaLista *celda;
    celda = lista->ini;
    ObtenerMaxMins(lista, maximos, minimos);
    while (celda != NULL)
    {
        dif = maximos[0] - minimos[0];
        celda->elem.ph = ((celda->elem.ph - minimos[0]) / (dif));

        dif = maximos[1] - minimos[1];
        celda->elem.Hardness = ((celda->elem.Hardness - minimos[1]) / (dif));

        dif = maximos[2] - minimos[2];
        celda->elem.Solids = ((celda->elem.Solids - minimos[2]) / (dif));

        dif = maximos[3] - minimos[3];
        celda->elem.Chloramines = ((celda->elem.Chloramines - minimos[3]) / (dif));

        dif = maximos[4] - minimos[4];
        celda->elem.Sulfate = ((celda->elem.Sulfate - minimos[4]) / (dif));

        dif = maximos[5] - minimos[5];
        celda->elem.Conductivity = ((celda->elem.Conductivity - minimos[5]) / (dif));

        dif = maximos[6] - minimos[6];
        celda->elem.Organic_carbon = ((celda->elem.Organic_carbon - minimos[6]) / (dif));

        dif = maximos[7] - minimos[7];
        celda->elem.Trihalomethanes = ((celda->elem.Trihalomethanes - minimos[7]) / (dif));

        dif = maximos[8] - minimos[8];
        celda->elem.Turbidity = ((celda->elem.Turbidity - minimos[8]) / (dif));

        celda = celda->sig;
    }
}

void normalizarEntrada(tipoAgua *entrada, float maximos[], float minimos[]) 
{    
    float dif;
    dif = maximos[0] - minimos[0];
    entrada->ph = ((entrada->ph - minimos[0]) / (dif));

    dif = maximos[1] - minimos[1];
    entrada->Hardness = ((entrada->Hardness - minimos[1]) / (dif));

    dif = maximos[2] - minimos[2];
    entrada->Solids = ((entrada->Solids - minimos[2]) / (dif));

    dif = maximos[3] - minimos[3];
    entrada->Chloramines = ((entrada->Chloramines - minimos[3]) / (dif));

    dif = maximos[4] - minimos[4];
    entrada->Sulfate = ((entrada->Sulfate - minimos[4]) / (dif));

    dif = maximos[5] - minimos[5];
    entrada->Conductivity = ((entrada->Conductivity - minimos[5]) / (dif));

    dif = maximos[6] - minimos[6];
    entrada->Organic_carbon = ((entrada->Organic_carbon - minimos[6]) / (dif));

    dif = maximos[7] - minimos[7];
    entrada->Trihalomethanes = ((entrada->Trihalomethanes - minimos[7]) / (dif));

    dif = maximos[8] - minimos[8];
    entrada->Turbidity = ((entrada->Turbidity - minimos[8]) / (dif));
}


void CalculaDistancia(ListaDinamica *lista, tipoAgua entrada, tipoMaxMonticulo *distancias, int n)
{
    float distancia;    
    TipoDistancia elementoDistancia;
    celdaLista *celda;
    int i = 0;
    celda = lista->ini;       
    while (celda != NULL)
    {        
        distancia = pow(celda->elem.ph - entrada.ph, 2);
        distancia = distancia + pow(celda->elem.Hardness - entrada.Hardness, 2);
        distancia = distancia + pow(celda->elem.Solids - entrada.Solids, 2);
        distancia = distancia + pow(celda->elem.Chloramines - entrada.Chloramines, 2);
        distancia = distancia + pow(celda->elem.Sulfate - entrada.Sulfate, 2);
        distancia = distancia + pow(celda->elem.Conductivity - entrada.Conductivity, 2);
        distancia = distancia + pow(celda->elem.Organic_carbon - entrada.Organic_carbon, 2);
        distancia = distancia + pow(celda->elem.Trihalomethanes - entrada.Trihalomethanes, 2);
        distancia = distancia + pow(celda->elem.Turbidity - entrada.Turbidity, 2);

        distancia = sqrt(distancia);
        printf(" %.2f \n", distancia);
        elementoDistancia.distancia = distancia;
        elementoDistancia.posicion = i;
        elementoDistancia.Potability = celda->elem.Potability;        
        
        if (esVacio(*distancias))
        {
            insertarMaxMonticulo(distancias, elementoDistancia);                       
        }
        else
        {
            if (estaLleno(*distancias))
            {                
                if (devolverRaiz(*distancias).distancia > elementoDistancia.distancia)
                {
                    eliminarElementoRaiz(distancias);
                    insertarMaxMonticulo(distancias, elementoDistancia);
                }                              
                               
            }
            else
            {                
                insertarMaxMonticulo(distancias, elementoDistancia);                
            }                        
            
        }        
        celda = celda->sig;
        i++;
    }
    mostrarAnchura(*distancias);
}


void mostrar(ListaDinamica *lista)
{    
    celdaLista *celda;
    celda = lista->ini;
    int i = 0;
    
    while(celda != NULL)
    {
        printf("CELDA: ");
        printf(" %.2f ", celda->elem.ph);
        printf(" %.2f ", celda->elem.Hardness);
        printf(" %.2f ", celda->elem.Solids);
        printf(" %.2f ", celda->elem.Chloramines);
        printf(" %.2f ", celda->elem.Sulfate);
        printf(" %.2f ", celda->elem.Conductivity);
        printf(" %.2f ", celda->elem.Organic_carbon);
        printf(" %.2f ", celda->elem.Trihalomethanes);
        printf(" %.2f ", celda->elem.Turbidity);
        printf(" %s \n", celda->elem.Potability ? "true" : "false");

        celda = celda->sig;
    }
    
    
}