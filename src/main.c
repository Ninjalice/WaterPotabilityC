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
    ListaDinamica datos;
    nuevaLista(&lista);
    LeerCSV(argv[1],&datos);
    normalizar(&datos,)
    return 0;
}
