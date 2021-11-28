
#include <stdlib.h>
#include <string.h>
#include "CsvReader.h"

// leer datos del archivo csv
void LeerCSV(const char *csvFilePath, ListaDinamica *lista)
{
    FILE *filePointer;

    filePointer = fopen(csvFilePath, "r");

    //Check file
    if (filePointer == NULL)
    {
        printf("%s file failed to open.", csvFilePath);
    }
    else
    {
        printf("El fichero se ha abierto correctamente.\n");

        char *line = NULL; 
        size_t bufsize = 0; //buffer para el getline
        char *pt;
        int contLineas = 0;
        int numAtributos = contarAtributos(filePointer); //Usamos la primera linea para contar el numero de atributos.
        float elementos[numAtributos - 1]; //Usamos -1 ya que el ultimo atributo es la categoria
        bool espotable = false;
        lista->numAtributos = numAtributos;
        while ((getline(&line, &bufsize, filePointer)) != -1)
        {
            int i = 0;
            pt = strtok(line, ",");
            while (pt != NULL)
            {                
                if (i < (numAtributos-1) )
                {
                    float a = atof(pt);                    
                    elementos[i] = a;
                }
                else
                {
                    espotable = atoi(pt);
                }                            
                pt = strtok(NULL, ",");
                i++;
            }
            tipoAgua elemento = insertarEnAgua(elementos, espotable);
            insertarEnLista(lista, elemento);
            contLineas = contLineas + 1;
        }
        lista->numeroAguas = contLineas;
        printf("Hemos leido %d lineas \n", contLineas);
        free(line);
        fclose(filePointer);        
        printf("El fichero se ha cerrado correctamente. \n");
    }    
}

int contarAtributos(FILE *filePointer)
{
    printf("contarAtributos\n");
    char *line = NULL;
    int numAtributos = 0;
    size_t bufsize = 0;
    char *pt;

    getline(&line, &bufsize, filePointer);
    pt = strtok(line, ",");
    while (pt != NULL)
    {
        numAtributos++;
        pt = strtok(NULL, ",");
    }    
    return numAtributos;
}

tipoAgua insertarEnAgua(float elementos[], bool espotable)
{
    tipoAgua agua;        
    agua.ph  = elementos[0];
    agua.Hardness = elementos[1];
    agua.Solids = elementos[2];
    agua.Chloramines = elementos[3];
    agua.Sulfate = elementos[4];
    agua.Conductivity = elementos[5];
    agua.Organic_carbon = elementos[6];
    agua.Trihalomethanes = elementos[7];
    agua.Turbidity = elementos[8];
    agua.Potability = espotable;
    
    return agua;
}