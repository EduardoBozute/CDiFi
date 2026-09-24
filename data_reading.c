#include "data_reading.h"

double** initialize_data_loaded(int lines, int columns){
    double** data_loaded = (double**)calloc(lines, sizeof(double*));

    for(int i = 0; i<lines; i++){
        data_loaded[i] = (double*)calloc(columns, sizeof(double));
    }

    return data_loaded;
}

void get_file_name(char* file_name, const char* folder, char* subject_number, char* sample_number){
    char command[256];
    sprintf(command, "cd %s/%s && ls %s*", folder, subject_number, sample_number);

    FILE* pipe = popen(command, "r");
    fscanf(pipe, "%39s", file_name);

    pclose(pipe);
    pipe = NULL;
}

void scan_subject_number(char* subject_number){
    printf("Enter the subject number (01-36): ");
    scanf("%s", subject_number);
}

void scan_sample_number(char* sample_number){
    printf("Enter the sample number (1-2): ");
    scanf("%s", sample_number);
}

int scan_initial_line(){
    int initial_line;
    printf("Enter the initial_line ( >= 0): ");
    scanf("%d", &initial_line);
    return initial_line;
}

int scan_final_line(){
    int final_line;
    printf("Enter the final_line ( <= 100000): ");
    scanf("%d", &final_line);
    return final_line;
}

void make_file_path(char* file_path, const char* folder, char* subject_number, char* file_name){
    strcpy(file_path, folder);
    strcat(file_path, "/");
    strcat(file_path, subject_number);
    strcat(file_path, "/");
    strcat(file_path, file_name);
    file_path[99] = '\0';
}

int load_file_data(char* file_path, double** data_loaded){

    FILE* file = fopen(file_path, "r");

    if(file == NULL){
        printf("This file coudn't be open. Verify if the file path is correct.\n");
        return 0; 
    }

    char data[20];
    int line = 0;
    int column = 0;

    while(fscanf(file, "%9[^\t\n]", data) == 1){
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

void print_data(int initial_line, int final_line, double** data_loaded){
    if(initial_line < 0 || final_line > 100000 || initial_line > final_line){
        printf("Invalid interval for reading.\n");
        return;
    }
    for(int i = initial_line; i < final_line; i++){
        for(int j = 0; j<10; j++){
            printf("%lf\t", data_loaded[i][j]); 
        }
        printf("\n");
    }
}

void free_data_loaded(double** data_loaded, int data_loaded_lines){
    for(int i = data_loaded_lines - 1; i>=0; i--){
        free(data_loaded[i]);
    }
    free(data_loaded);
}
