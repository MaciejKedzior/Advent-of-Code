#include <stdio.h>
#include <stdlib.h>
#include "intcode.h"

int maximum = 0;
IntCode amp_a, amp_b, amp_c, amp_d, amp_e;
IntCode *computers[5] = {&amp_a, &amp_b, &amp_c, &amp_d, &amp_e};



void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void permutation(int *arr, int start, int end){
    if (start == end){
        int result = 0;
        
        for (int i=0; i<5; i++){
            int temp[2] = {arr[i], result};
            result = run(computers[i], temp);
        }

        if (result > maximum) maximum = result;
        return;
    }
    
    for (int i=start; i<=end; i++){
        swap((arr+i), (arr+start));
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}



int main(int argc, char *argv[]){
    if (argc < 3){
        printf("Not enough command line args! You have to write file's name and debug value (1 or 0)\n");
        exit(EXIT_FAILURE);
    }


    int phase_values[5] = {0, 1, 2, 3, 4};
    for (int i=0; i<5; i++) initialize(argv[1], computers[i], atoi(argv[2]));
    permutation(phase_values, 0, 4);
    printf("FINAL RESULT: %d\n", maximum);
    exit(EXIT_SUCCESS);
}