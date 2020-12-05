#ifndef UTILS_H
#define UTILS_H

#include <inttypes.h>
#include <stdbool.h>

#define SIZE 826
#define LENGTH 11

#define ROWS 128
#define COLUMNS 8


typedef struct range{
    unsigned int a;
    unsigned int b;
}Range;

typedef struct seat_cords{
    int32_t a;
    int32_t b;
}SeatCoordinates;


void loadData(char array[SIZE][LENGTH], const char* filename);
void fillSeats(char array[SIZE][LENGTH], bool seats[ROWS][COLUMNS], Range row_range, Range col_range);

int32_t getSeatID(int32_t row, int32_t column);
int32_t findRow(Range range, char signs[]);
int32_t findColumn(Range range, char signs[]);
int32_t findBiggestID(char array[SIZE][LENGTH], Range row_range, Range col_range);
int32_t findYourSeatID(bool seats[ROWS][COLUMNS]);
#endif