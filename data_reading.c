#include "data_reading.h"

int load_file_data(char[] file_name, double[][10] data_loaded){

    FILE* file = fopen(file_name, "r");

    if(file == NULL){
        printf("This file coudn't be open. Verify if the file name is correct.\n");
        return 0; 
    }

    char[10] data;
    int line = 0;
    int column = 0;

    while(fscanf(file, "%9[^\t\n], data") == 1){
        data_loaded[line][column] = strtod(data, NULL);

        char next = fgetc(file);
        if(next == '\n'){
            line++;
            column = 0;
        } 
        else{
            column++;
        }
    }

    fclose(file);
    return 1;
}
