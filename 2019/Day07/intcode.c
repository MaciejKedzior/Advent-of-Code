#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"


void initialize(const char *path, IntCode *computer, int debug){
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

    for (int i=0; i<integers; i++){ 
        computer->memory[i] = atoi(words[i]);
    }

    computer->loaded_program_size = integers;
    if (debug) computer->debug_mode = true;
    else computer->debug_mode = false;


    for (int i=0; i<SIZE; i++) free(words[i]);
    printf("Intcode program loaded, memory used: %d units\n", computer->loaded_program_size);
}


void reset_memory(IntCode *computer, int *original){
    for (int i=0; i<computer->loaded_program_size; i++) computer->memory[i] = original[i];
}


void param_modes(int array[], int opcode){
    if (opcode < 10){
        array[0]=0; array[1]=0; array[2]=0; array[3]=opcode%10;
    }
    else {
        int i = 3;
        while (opcode != 0){
            array[i] = opcode%10;
            if (i==3) opcode/=100;
            else opcode/=10;
            i--;
        }
    }
}

void add(IntCode *computer, int arg1, int arg2, int arg3, int mode[]){
    int add1, add2;

    if (mode[2] == 0) add1 = computer->memory[arg1];
    else add1 = arg1;

    if (mode[1] == 0) add2 = computer->memory[arg2];
    else add2 = arg2; 

    
    computer->memory[arg3] = add1 + add2;
    if (computer->debug_mode) printf("ADD\t%d\t%d\t[%d]\n", add1, add2, arg3);
    computer->instruction_pointer += 4;
}


void mpy(IntCode *computer, int arg1, int arg2, int arg3, int mode[]){
    int mpy1, mpy2;

    if (mode[2] == 0) mpy1 = computer->memory[arg1]; 
    else mpy1 = arg1; 

    if (mode[1] == 0) mpy2 = computer->memory[arg2];
    else mpy2 = arg2;

    
    computer->memory[arg3] = mpy1 * mpy2;
    if (computer->debug_mode) printf("MPY\t%d\t%d\t[%d]\n", mpy1, mpy2, arg3);
    computer->instruction_pointer += 4;
}


void input(IntCode *computer, int value, int address){
    if (computer->debug_mode) printf("INPUT\t%d\t[%d]\n", value, address);
    computer->memory[address] = value;
    computer->instruction_pointer += 2;
}


int output(IntCode *computer, int address, int mode[]){
    if (mode[2] == 0){
        printf("OUTPUT\t[%d]\t%d\n", address, computer->memory[address]);
        computer->instruction_pointer += 2;
        return computer->memory[address];
    } 
    printf("OUTPUT\t%d\n", address);
    computer->instruction_pointer += 2;
    return address;
    
}

void jmp_true(IntCode *computer, int location, int tested, int jump_to, int mode[]){
    if (computer->debug_mode) printf("JMP_T\t%d\t%d\n", tested, jump_to);
    int temp_test, temp_jump;
    if (mode[2] == 0) temp_test = computer->memory[tested];
    else temp_test = tested;

    if (mode[1] == 0) temp_jump = computer->memory[jump_to];
    else temp_jump = jump_to;


    if ( temp_test != 0 ) computer->instruction_pointer = temp_jump;
    else computer->instruction_pointer += 3;
}

void jmp_false(IntCode *computer, int location, int tested, int jump_to, int mode[]){
    if (computer->debug_mode) printf("JMP_F\t%d\t%d\n", tested, jump_to);
    int temp_test, temp_jump;
    if (mode[2] == 0) temp_test = computer->memory[tested];
    else temp_test = tested;

    if (mode[1] == 0) temp_jump = computer->memory[jump_to];
    else temp_jump = jump_to;


    if ( temp_test == 0 ) computer->instruction_pointer = temp_jump;
    else computer->instruction_pointer += 3;
}

void less_than(IntCode *computer, int arg1, int arg2, int address, int mode[]){
    if (computer->debug_mode) printf("LESS\t%d\t%d\t[%d]\n", arg1, arg2, address);
    int temp_first, temp_second;
    if (mode[2] == 0) temp_first = computer->memory[arg1];
    else temp_first = arg1;

    if (mode[1] == 0) temp_second = computer->memory[arg2];
    else temp_second = arg2;


    if ( temp_first < temp_second ) computer->memory[address] = 1;
    else computer->memory[address] = 0;

    computer->instruction_pointer += 4;
}

void equals(IntCode *computer, int arg1, int arg2, int address, int mode[]){
    if (computer->debug_mode) printf("EQ\t%d\t%d\t[%d]\n", arg1, arg2, address);
    int temp_first, temp_second;
    if (mode[2] == 0) temp_first = computer->memory[arg1];
    else temp_first = arg1;

    if (mode[1] == 0) temp_second = computer->memory[arg2];
    else temp_second = arg2;


    if ( temp_first == temp_second ) computer->memory[address] = 1;
    else computer->memory[address]= 0;

    computer->instruction_pointer += 4;
}


int run(IntCode *computer, int input_values[]){
    #define POINTER computer->instruction_pointer
    POINTER=0;
    int input_counter=0, output_value=0;

    while (computer->memory[POINTER] != 99){
        int mode_array[]={0, 0, 0, 0};
        param_modes(mode_array, computer->memory[POINTER]);
        switch (mode_array[3]){
            case 1:
                add(computer, computer->memory[POINTER+1], computer->memory[POINTER+2], computer->memory[POINTER+3], mode_array);
                break;
            case 2:
                mpy(computer, computer->memory[POINTER+1], computer->memory[POINTER+2], computer->memory[POINTER+3], mode_array);
                break;
            case 3:
                input(computer, input_values[input_counter], computer->memory[POINTER+1]);
                input_counter++;
                break;
            case 4:
                output_value = output(computer, computer->memory[POINTER+1], mode_array);
                break;
            case 5:
                jmp_true(computer, POINTER, computer->memory[POINTER+1], computer->memory[POINTER+2], mode_array);
                break;
            case 6:
                jmp_false(computer, POINTER, computer->memory[POINTER+1], computer->memory[POINTER+2], mode_array);
                break;
            case 7:
                less_than(computer, computer->memory[POINTER+1], computer->memory[POINTER+2], computer->memory[POINTER+3], mode_array);
                break;
            case 8:
                equals(computer, computer->memory[POINTER+1], computer->memory[POINTER+2], computer->memory[POINTER+3], mode_array);
                break;
            default:
                break;
            
        }
    }
    return output_value;
}

