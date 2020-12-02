#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void loadData(int array[], int size, const char* filename){
    char words[12];
    FILE* fpointer;

    if ((fpointer = fopen(filename, "r")) == NULL){
        perror("Error while opening file: ");
        exit(EXIT_FAILURE);
    }

    int i=0;
    while(fgets(words, 12, fpointer)){
        array[i] = atoi(words);
        i++;
    }
}


int twoSum(int array[], int size, int sum){
    for (int i=0; i < size; i++){
        for (int j=i; j < size; j++){
            if (array[i] + array[j] == sum)
                return array[i] * array[j];
        }
    }
    return -1;
}

int threeSum(int array[], int size, int sum){
    for (int i=0; i < size; i++){
        for (int j=i; j < size; j++){
            for (int k=j; k < size; k++){
                if (array[i] + array[j] + array[k] == sum)
                    return array[i] * array[j] * array[k];
            }
        }
    }
    return -1;
}

int main(void){
    int array[200];
    loadData(array, 200, "input.txt");
    printf("Part1: %d\n", twoSum(array, 200, 2020));
    printf("Part2: %d\n", threeSum(array, 200, 2020));
    return 0;
}