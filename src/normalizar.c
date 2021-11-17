#include "normalizar.h"

void ObtenerMaxMins(ListaDinamica *lista, float maximos[], float minimos[]) // valornormalizado = ((valor - min)/ dif) siendo dif = max - min;
{
    float dif;
    celdaLista *celda;
    PrimeraCeldaLista(lista, celda);
    InicializarMaxMins(celda, maximos,minimos);
    ObtenerSiguiente(celda);
    for (int i = 0; i < (lista->numeroAguas - 1); i++)
    {
        //MINIMOS
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
        if (minimos[7] > celda->elem.Turbidity)
        {
            minimos[7] = celda->elem.Turbidity;
        }

        //MAXIMOS
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
        if (maximos[7] < celda->elem.Turbidity)
        {
            maximos[7] = celda->elem.Turbidity;
        }

        ObtenerSiguiente(celda);
    }
    
}

void InicializarMaxMins(celdaLista *celda, float maximos[], float minimos[])
{
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

void normalizar(ListaDinamica *lista, float maximos[], float minimos[]) // valornormalizado = ((valor - min)/ dif) siendo dif = max - min;
{
    float dif;
    celdaLista *celda;
    PrimeraCeldaLista(lista, celda);    
    ObtenerSiguiente(celda);
    for (int i = 0; i < (lista->numeroAguas - 1); i++)
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

        ObtenerSiguiente(celda);
    }
}