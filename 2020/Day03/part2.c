#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define ROWS 323
#define COLUMNS 31

typedef struct vect2d{
    int x;
    int y;
}Vector2D;

void loadData(char array[ROWS][COLUMNS], const char * filename){
    int open_code = open(filename, O_RDONLY);
    char buffer[2*BUFSIZ];
    if ( open_code == -1 ){
        perror("open error");
        exit(EXIT_FAILURE);
    }

    
    int read_code = read(open_code, buffer, 2*BUFSIZ);
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


int treesHitUsingVectorTranslation(char map[ROWS][COLUMNS], Vector2D *vector){
    int counter=0;
    int j=0;
    for (int i=0; i < ROWS; i+=vector->x){
        if ( map[i][j%COLUMNS] == '#')
            counter++;
        j += vector->y;
    }
    return counter;
}


int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Input wasn't added!\n");
        exit(EXIT_FAILURE);
    }
    
    char map[ROWS][COLUMNS];
    Vector2D vect_array[5] = {{.x=1, .y=1}, {.x=1, .y=3}, {.x=1, .y=5}, {.x=1, .y=7}, {.x=2, .y=1}};
    long int result = 1;

    loadData(map, argv[1]);
    
    for (int i=0; i < 5; i++){
        result *= treesHitUsingVectorTranslation(map, &(vect_array[i]));
    }

    printf("D3P2: %ld\n", result);
    

    return 0;
}