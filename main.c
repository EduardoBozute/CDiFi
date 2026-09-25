#include "data_reading.h"

void main(){
    system("clear");

    const char folder[30] = "EMG_data_for_gestures-master";
    char subject_number[3], sample_number[2], file_name[60], file_path[100];

    int data_loaded_lines = 100000, data_loaded_columns = 10;
    double** data_loaded = initialize_data_loaded(data_loaded_lines, data_loaded_columns);

    scan_subject_number(subject_number);
    scan_sample_number(sample_number);
    
    get_file_name(file_name, folder, subject_number, sample_number);
    make_file_path(file_path, folder, subject_number, file_name);
    printf("File path: %s\n", file_path);

    load_file_data(file_path, data_loaded);

    int main_choice;

    do{
        printf("\n[0] Close program\n");
        printf("[1] Open other dataset file\n");
        printf("[2] Print an interval of data loaded\n");
        printf("\nCDiFi> ");
        scanf("%d", &main_choice);
        switch(main_choice){
            case 0: break;
            case 1: free_data_loaded(data_loaded, data_loaded_lines);
                    data_loaded = NULL;
                    data_loaded = initialize_data_loaded(data_loaded_lines, data_loaded_columns);
                    scan_subject_number(subject_number);
                    scan_sample_number(sample_number);
    
                    get_file_name(file_name, folder, subject_number, sample_number);
                    make_file_path(file_path, folder, subject_number, file_name);
                    printf("File path: %s\n", file_path);

                    load_file_data(file_path, data_loaded);
                    break;
            case 2: int initial_line, final_line;
                    initial_line = scan_initial_line();
                    final_line = scan_final_line();
                    print_data(initial_line, final_line, data_loaded);
                    break;
            default: printf("\nOption not recognized...\n"); break;
        }
    }while(main_choice != 0);

    free_data_loaded(data_loaded, data_loaded_lines);
    data_loaded = NULL;
}