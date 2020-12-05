#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct range{
    int minimum;
    int maximum;
}Range;


bool isAcceptedPart1(char password[], char rule_letter, Range range){
    int counter=0;
    while (*password){
        if (*password == rule_letter)
            counter++;
        if (counter > range.maximum) return false;
        password++;
    }
    if (counter < range.minimum) return false;
    return true;
}

bool isAcceptedPart2(char password[], char rule_letter, Range range){
    int position=1;
    bool min=false, max=false;
    while (*password){
        if (*password == rule_letter && position == range.minimum)
            min = true;
        if (*password == rule_letter && position == range.maximum)
            max = true;
        password++;
        position++;
    }
    if (min^max) return true;
    return false;
}



int loadAndCalculate(const char* filename, int policy){
    char words[50];
    FILE* fpointer;
    char tokens[3][30];

    int counter = 0;


    if ((fpointer = fopen(filename, "r")) == NULL){
        perror("Error while opening file: ");
        exit(EXIT_FAILURE);
    }

    
    while(fgets(words, 50, fpointer)){
        char * temp;
        int i=0;
        Range range;
        temp = strtok(words, " ");
        while ( temp != NULL){
            strcpy(tokens[i], temp);
            i++;
            temp = strtok(NULL, " ");
        }
        
        char *s_range = strtok(tokens[0], "-");
        range.minimum = atoi(s_range);
        s_range = strtok(NULL, "-");
        range.maximum = atoi(s_range);

        size_t ln = strlen(tokens[2]) - 1;
        if (*tokens[2] && tokens[2][ln] == '\n') 
            tokens[2][ln] = '\0';

        if (policy == 0){
            if (isAcceptedPart1(tokens[2], tokens[1][0], range))
                counter++;
        }
        else if (policy == 1){
            if (isAcceptedPart2(tokens[2], tokens[1][0], range))
                counter++;
        }
        else exit(EXIT_FAILURE);
    }

    return counter;
}


int main(void){
    printf("Part1: %d\n", loadAndCalculate("input", 0));
    printf("Part2: %d\n", loadAndCalculate("input", 1));
}