#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Only filename!\n");
        exit(EXIT_FAILURE);
    }

    char array[SIZE][LENGTH];
    loadAsBinaries(array, argv[1]);

    printf("D5P2: %d\n", findYourSeatQuickly(array));
    return 0;
}
