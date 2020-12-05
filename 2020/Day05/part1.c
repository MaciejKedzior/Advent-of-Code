#include <stdio.h>
#include <stdlib.h>


#include "utils.h"

Range row_range = {0, 127}, col_range = {0, 7};

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Use only one argument - name of file!\n");
        exit(EXIT_FAILURE);
    }

    //char* examples[] = {"FBFBBFFRLR", "BFFFBBFRRR", "FFFBBBFRRR", "BBFFBBFRLL"};
    
    char array[SIZE][LENGTH];
    loadData(array, argv[1]);
    printf("D5P1: %d\n", findBiggestID(array, row_range, col_range));

    return 0;
}