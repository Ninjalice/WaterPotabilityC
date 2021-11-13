#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include "ListaDinamicaAgua.h"

void LeerCSV(char *csvFilePath, ListaDinamica *lista);

int contarAtributos(FILE *filePointer);

tipoAgua insertarEnAgua(float elementos[], bool espotable);
