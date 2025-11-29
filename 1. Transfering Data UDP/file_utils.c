#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"


void printer(char * filename) {
    
    char ch;

    FILE *fptr = fopen(filename, "r");

    while ((ch = fgetc(fptr)) != EOF)
        printf("%c", ch);
        
    printf("\n");
    
    fclose(fptr);
}

char *reader(char * filename){
   

    FILE *file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    int size = ftell(file);

    fseek(file, 0, SEEK_SET);

    char *source = (char *)malloc(sizeof(char) * size + 1);
    fread(source, 1, size, file);
    fclose(file);
    source[size] = '\0';

    return source;
}