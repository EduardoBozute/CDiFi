#ifndef DATA_READING_C
#define DATA_READING_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    UNMARKED_DATA,
    HAND_AT_REST,
    HAND_CLENCHED_IN_A_FIST,
    WRIST_FLEXION,
    WRIST_EXTENSION,
    RADIAL_DEVIATIONS,
    UNLNAR_DEVIATIONS,
    EXTENDED_PALM
} Gesture;

double** initialize_data_loaded(int, int);

void free_data_loaded(double**, int);

void get_file_name(char*, const char*, char*, char);

void make_file_path(char*, const char*, char*, char*);

int load_file_data(char*, double**);

void print_data(int, int, double**);

#endif
