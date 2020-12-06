#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#include <fcntl.h>          // for O_RDONLY flag
#include <sys/types.h>      // for open()
#include <sys/stat.h>       // for open()
#include <unistd.h>         // for read()

#include "utils.h"



void loadAsBinaries(char array[SIZE][LENGTH], const char* filename){
    int open_code = open(filename, O_RDONLY);
    char buffer[SIZE*LENGTH];
    if ( open_code == -1 ){
        perror("open error");
        exit(EXIT_FAILURE);
    }
    
    int read_code = read(open_code, buffer, SIZE*LENGTH);
    if (read_code == -1 ){
        perror("error reading: ");
        exit(EXIT_FAILURE);
    }

    int x=0, y=0;
    for (int i=0; i < read_code; i++){
        if (buffer[i] != '\n'){
            if (buffer[i] == 'F' || buffer[i] == 'L')
                array[x][y] = '0';
            else if (buffer[i] == 'B' || buffer[i] == 'R')
                array[x][y] = '1';
            y++;
        }
        else{ 
            x++; 
            y=0;
        }
    }
}

int8_t strbin2i(unsigned char* s) {
    register unsigned char *p = s;
    register unsigned int   r = 0;

    while (p && *p ) {
        r <<= 1;
        r += (unsigned int)((*p++) & 0x01);
    }
    return (int8_t)r;
}

int32_t findQuicklyBiggest(char array[SIZE][LENGTH]){
    int32_t biggest = INT32_MIN;
    for (int i=0; i<SIZE; i++){
        char row[LENGTH-3]; memcpy(row, array[i], LENGTH-4);
        char column[LENGTH-7]; int x=0; for (int j=7; j < LENGTH-1; j++) { column[x] = array[i][j]; x++;}

        int32_t row_num = strbin2i((unsigned char*)row);
        int32_t col_num = strbin2i((unsigned char*)column);
        int32_t currID = (row_num<<3)+col_num;

        if (currID > biggest){
            biggest = currID; 
        }
    }
    return biggest;
}

int32_t findYourSeatQuickly(char array[SIZE][LENGTH]){
    bool taken[ROWS][COLUMNS]; memset(taken, 0, sizeof(bool)*ROWS*COLUMNS);
    for (int i=0; i<SIZE; i++){
        char row[LENGTH-3]; memcpy(row, array[i], LENGTH-4);
        char column[LENGTH-7]; int x=0; for (int j=7; j < LENGTH-1; j++) { column[x] = array[i][j]; x++;}

        int32_t row_num = strbin2i((unsigned char*)row);
        int32_t col_num = strbin2i((unsigned char*)column);

        taken[row_num][col_num] = true;
    }

    for (int i=1; i < ROWS-1; i++){
        for (int j=1; j < COLUMNS; j++){
            if (!taken[i][j] && taken[i][j-1] && taken[i][j+1])
                return (i<<3)+j;
        }
    }
    return -1;
}

