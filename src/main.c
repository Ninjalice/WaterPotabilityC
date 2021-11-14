#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CsvReader.h"
#include "normailizar.h"

// gcc main.c -o main
//  ./main nombre_fichero
//gcc main.c CsvReader.o - o main


int main(int argc, char const *argv[])
{
    float maximos[lista->numAtributos - 1];
    float minimos[lista->numAtributos - 1];
    ListaDinamica datos;
    nuevaLista(&lista);
    LeerCSV(argv[1],&datos);
    normalizar(&datos, maximos,minimos);
    return 0;
}

void knn(int n , char *dirfichero)
{
    ListaDinamica datos;
    nuevaLista(&datos);
    LeerCSV(dirfichero, &datos);
    normalizar(&datos);       
}
