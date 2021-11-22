#ifndef CSV_READER
#define CSV_READER

#include <stdio.h>
#include <stdbool.h>
#include "ListaDinamicaAgua.h"

void LeerCSV(const char *csvFilePath, ListaDinamica *lista);

int contarAtributos(FILE *filePointer);

tipoAgua insertarEnAgua(float elementos[], bool espotable);


#endif