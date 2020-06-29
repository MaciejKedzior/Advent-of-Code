#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"


void load_data(const char *path, int *integer_array, int *program_size){
    char    buffer[BUFSIZ], *words[SIZE], *token;
    int     open_code, read_code, integers=0;
     
    
    for (int i=0; i<SIZE; i++) words[i] = malloc(12*sizeof(char));

    if ((open_code=open(path, O_RDONLY)) == -1){
        perror("Error loading data: ");
        exit(EXIT_FAILURE);
    }

    if ( (read_code=read(open_code, buffer, BUFSIZ)) == -1){
        perror("Error reading: ");
        exit(EXIT_FAILURE);
    }
    
    token = strtok(buffer, ",");

    while(token){
        strcpy(words[integers], token);
        integers++;
        token = strtok(NULL, ",");
    }

    for (int i=0; i<integers-1; i++){
        integer_array[i] = atoi(words[i]);
    }
    *program_size = integers-1;
    for (int i=0; i<SIZE; i++) free(words[i]);
}


void reset_memory(IntCode *computer, int *original){
    for (int i=0; i<computer->loaded_program_size; i++) computer->memory[i] = original[i];
}


void add_op(IntCode *computer, int position1, int position2, int final_address){
    computer->memory[final_address] = computer->memory[position1] + computer->memory[position2];
}


void mpy_op(IntCode *computer, int position1, int position2, int final_address){
    computer->memory[final_address] = computer->memory[position1] * computer->memory[position2];
}


void run(IntCode *computer){
    for (int i=0; i < computer->loaded_program_size; i+=4){
        switch (computer->memory[i]){
            case 1:
                add_op(computer, computer->memory[i+1], computer->memory[i+2], computer->memory[i+3]);
                break;
            case 2:
                mpy_op(computer, computer->memory[i+1], computer->memory[i+2], computer->memory[i+3]);
                break;
            case 99:
                return;
            default:
                break;
        }
    }
}
