#include <stdio.h>
#include <stdlib.h>
#include "intcode.h"

int main(int argc, const char *argv[]){
    IntCode machine;
    load_data(argv[1], &machine);
    run(&machine, atoi(argv[2]));
    return 0;
}
