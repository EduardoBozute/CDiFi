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

int load_file_data(char(*), double(*)[10]);

#endif
