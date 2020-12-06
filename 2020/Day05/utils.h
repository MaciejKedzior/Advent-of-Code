#ifndef UTILS_H
#define UTILS_H

#include <inttypes.h>
#include <stdbool.h>

#define SIZE 826
#define LENGTH 11

#define ROWS 128
#define COLUMNS 8


void loadAsBinaries(char array[SIZE][LENGTH], const char* filename);
int8_t strbin2i(unsigned char* s);
int32_t findQuicklyBiggest(char array[SIZE][LENGTH]);
int32_t findYourSeatQuickly(char array[SIZE][LENGTH]);
#endif