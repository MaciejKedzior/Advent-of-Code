#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


int main(int argc, char* argv[]){
    Range row_range = {0, 127}, col_range = {0, 7};
    
    if (argc != 2){
        printf("Use only one argument - name of file!\n");
        exit(EXIT_FAILURE);
    } 
    
    char array[SIZE][LENGTH];
    loadData(array, argv[1]);
    
    bool seats[ROWS][COLUMNS];
    memset(seats, 0, ROWS*COLUMNS*sizeof(bool));
    fillSeats(array, seats, row_range, col_range);

    printf("D5P2: %d\n", findYourSeatID(seats));

    return 0;
}

