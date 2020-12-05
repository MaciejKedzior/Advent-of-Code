#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include <fcntl.h>          // for O_RDONLY flag
#include <sys/types.h>      // for open()
#include <sys/stat.h>       // for open()
#include <unistd.h>         // for read()
#define SIZE 826
#define LENGTH 11


typedef struct range{
    unsigned int a;
    unsigned int b;
}Range;


Range row_range = {0, 127}, col_range = {0, 7};


void loadData(char array[SIZE][LENGTH], const char* filename){
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
            array[x][y] = buffer[i];
            y++;
        }
        else{ 
            x++; 
            y=0;
        }
    }
}


int32_t getSeatID(int32_t row, int32_t column){
    return 8*row+column;
}

int32_t findRow(Range range, char signs[]){
    for (int i=0; i < LENGTH-4; i++){
        int middle = (range.a + range.b) >> 1u;
        if (signs[i] == 'F')
            range.b = middle;
        else 
            range.a = middle;
    }
    if (signs[LENGTH-3] == 'F')
        return range.a;
    return range.b;
}

int32_t findColumn(Range range, char signs[]){
    for (int i=7; i < LENGTH-1; i++){
        int middle = (range.a + range.b) >> 1u;
        if (signs[i] == 'L')
            range.b = middle;
        else 
            range.a = middle;
    }
    if (signs[LENGTH] == 'L')
        return range.a;
    return range.b;
}

int32_t findBiggestID(char array[SIZE][LENGTH]){
    int32_t biggest = INT32_MIN;
    for (int i=0; i < SIZE; i++){
        char temp[LENGTH];
        memcpy(temp, array[i], LENGTH);
        int32_t currentID = getSeatID(findRow(row_range, temp), findColumn(col_range, temp));
        if ( currentID > biggest)
            biggest = currentID;
    }
    return biggest;
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Use only one argument - name of file!\n");
        exit(EXIT_FAILURE);
    }

    //char* examples[] = {"FBFBBFFRLR", "BFFFBBFRRR", "FFFBBBFRRR", "BBFFBBFRLL"};
    
    char array[SIZE][LENGTH];
    loadData(array, argv[1]);
    printf("D5P1: %d\n", findBiggestID(array));

    return 0;
}