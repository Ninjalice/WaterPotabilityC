#include "CsvReader.h"

// Calcula el número total de filas en el archivo csv
int GetTotalLineCount(FILE *fp)
{
    int i = 0;
    char strLine[MAX_LINE_SIZE];
    fseek(fp, 0, SEEK_SET);
    while (fgets(strLine, MAX_LINE_SIZE, fp))
        i++;
    fseek(fp, 0, SEEK_SET);
    return i;
}

// Calcula el número total de columnas en el archivo csv (basado en el número de columnas en la primera fila)
int GetTotalColCount(FILE *fp)
{
    int i = 0;
    char strLine[MAX_LINE_SIZE];
    fseek(fp, 0, SEEK_SET);
    if (fgets(strLine, MAX_LINE_SIZE, fp))
    {
        i = strlen(strLine) / 2; 
    }
    else
    {
        fseek(fp, 0, SEEK_SET);
        return -1;
    }
    fseek(fp, 0, SEEK_SET);
    return i;
}

/*
// leer datos del archivo csv
int ReadCsvData(char *csvFilePath)
{
    FILE *filePointer;

    char *line = NULL;
    float read;
    size_t bufsize = 0;

    filePointer = fopen(argv[1], "r");

    //Check file
    if (filePointer == NULL)
    {
        printf("%s file failed to open.", argv[1]);
    }
    else
    {
        printf("The file is now opened.\n");
        int i = 0;
        while ((getline(&line, &bufsize, filePointer)) != -1)
        {
            printf("Line %d | ", i);
            printf("%s \n", line);

            i = i + 1;
        }

        free(line);
        fclose(filePointer);

        printf("Data successfully read\n");
        printf("The file is now closed. \n");
    }
    return 1;
}

void ShowCsvData(int col , int row , float datos)
{    
    for (int i = 0; i < giNumRow; i++)
    {
        printf("Line %i :", i + 1); 
        for (int j = 0; j < giNumCol; j++)
        {
            printf("%i", giCsvData[i * giNumCol + j]); 
        }
        printf("\n"); 
    }
}

*/