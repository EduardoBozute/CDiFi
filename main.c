#include "data_reading.h"

void main(){
    const char folder[30] = "./EMG_data_for_gestures-master";
    char command[256];
    char file_name[40], file_path[100];
    double data_loaded[10000][10];
    char subject_number[3]; char sample_number;

    printf("Enter the subject number (01-36): ");
    scanf("%s", subject_number);
    printf("Enter the sample number (1-2): ");
    scanf(" %c", &sample_number);

    sprintf(command, "cd %s/%s && ls %c*", folder, subject_number, sample_number);

    printf("%s\n", command);

    FILE* pipe = popen(command, "r");

    fscanf(pipe, "%39s", file_name);

    strcpy(file_path, folder);
    strcat(file_path, "/");
    strcat(file_path, subject_number);
    strcat(file_path, "/");
    strcat(file_path, file_name);
    file_path[99] = '\0';

    printf("%s\n", file_path);

    pclose(pipe);

    printf("%s\n", file_name);

    if(load_file_data(file_name, data_loaded) == 0){
        return;
    }

    for(int i = 0; i++; i<10){
        for(int j = 0; j<10; j++){
            printf("%lf\t", data_loaded[i][j]); 
        }
        printf("\n");
    }
}
