#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CsvReader.h"
#include "normalizar.h"
#include "maxMonticulo.h"



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
            if (potable > noPotable && distancias[i].Potability == true)
            {
                if (distanciaMenor.Potability == false)
                {
                    distanciaMenor = distancias[i];
                }
                
                if (distanciaMenor.distancia > distancias[i].distancia)
                {
                    distanciaMenor = distancias[i];
                }
            }
            else if (noPotable > potable && distancias[i].Potability == false)
            {
                if (distanciaMenor.Potability == true)
                {
                    distanciaMenor = distancias[i];
                }
                if (distanciaMenor.distancia > distancias[i].distancia)
                {
                    distanciaMenor = distancias[i];
                }
            }
        }
        return distanciaMenor;
    }    
    
}

void knn(int n, const char *dirfichero, tipoAgua entrada)
{
    ListaDinamica datos;    
    bool espotable = NULL;
    tipoMaxMonticulo maxMonticulo;
    TipoDistancia distanciaMinima;
    nuevaLista(&datos);
    nuevoMaxMonticulo(&maxMonticulo, n);
    LeerCSV(dirfichero, &datos);

    float maximos[datos.numAtributos - 1];
    float minimos[datos.numAtributos - 1];

    //mostrar(&datos);
    normalizar(&datos, maximos, minimos);
    //mostrar(&datos);
    //printf("MOSTRAR\n");
    normalizarEntrada(&entrada, maximos,minimos);
    printf("Entrada normalizada\n");
    CalculaDistancia(&datos, entrada, &maxMonticulo,n);
    
    distanciaMinima = esPotable(maxMonticulo.array, n);

    printf("La distancia minima esta en la posicion %d y tiene un valor de  %.2f \n",distanciaMinima.posicion,distanciaMinima.distancia);
    printf("RESULTADO FINAL:\n");
    printf("POTABILIDAD: %s \n", distanciaMinima.Potability ? "true" : "false");
}

void wilson(ListaDinamica *datos , int n)
{
    int elementosEliminados = 0;    
    bool espotable = NULL;
    tipoMaxMonticulo maxMonticulo;
    TipoDistancia distanciaMinima;
    float maximos[datos->numAtributos - 1];
    float minimos[datos->numAtributos - 1];
    celdaLista *celda;
    int posicion = 0;
    normalizar(datos, maximos, minimos);
    celda = datos->ini;
    
    while (celda != NULL)
    {
        eliminarElemento(datos, posicion);
        CalculaDistancia(datos, celda->elem, &maxMonticulo, n);
        espotable = esPotable(maxMonticulo.array, n).Potability;
        if(espotable == celda->elem.Potability)
        {
            insertarEnLista(datos, celda->elem);
        }        
        posicion++;
        celda = celda->sig;
    } 
    
}

void probabilidad(ListaDinamica *datos)
{
    //Probabilidad
}

int main(int argc, char const *argv[])
{
    int n;
    tipoAgua entrada;
    entrada.ph = 7.65;
    entrada.Hardness = 236.9;
    entrada.Solids = 14245.7;
    entrada.Chloramines = 6.29;
    entrada.Sulfate = 373.16;
    entrada.Conductivity = 416.62;
    entrada.Organic_carbon = 10.46;
    entrada.Trihalomethanes = 85.85;
    entrada.Turbidity = 2.43;    
    knn(atoi(argv[2]), argv[1], entrada);

    return 0;
}