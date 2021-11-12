#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// gcc main.c -o main
//  ./main nombre_fichero
//gcc main.c CsvReader.o - o main


int main(int argc, char const *argv[])
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
        

        printf("Data successfully read\n");
        printf("The file is now closed. \n");        
        fclose(filePointer);
    }
    return 0;
}

