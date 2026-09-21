#include "data_reading.h"

void main(){
    const char folder[30] = "EMG_data_for_gestures-master";
    char subject_number[3], sample_number, file_name[60], file_path[100];

    int data_loaded_lines = 100000, data_loaded_columns = 10;
    double** data_loaded = initialize_data_loaded(data_loaded_lines, data_loaded_columns);

    printf("Enter the subject number (01-36): ");
    scanf("%s", subject_number);
    printf("Enter the sample number (1-2): ");
    scanf(" %c", &sample_number);
    
    get_file_name(file_name, folder, subject_number, sample_number);
    make_file_path(file_path, folder, subject_number, file_name);
    printf("File path: %s\n", file_path);

    load_file_data(file_path, data_loaded);

    for(int i = data_loaded_lines - 1; i>=0; i--){
        free(data_loaded[i]);
    }
    free(data_loaded);
}
