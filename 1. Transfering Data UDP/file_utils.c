#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"



void reader(char * filename , char **data){
   

    FILE *file = fopen(filename, "r");

    if(file== NULL){
        printf("Could not open the file\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    int size = ftell(file);

    fseek(file, 0, SEEK_SET);

    *data = (char *)malloc(sizeof(char) * size + 1);
    
    fread(*data, 1, size, file);
    fclose(file);
    (*data)[size] = '\0';

    printf("%s\n",*data);


}