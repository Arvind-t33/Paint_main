#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "quit.h"

void freeCanvas(CanvasBoard Canvas){ // Frees up the Canvas each row at a time
    for(int i = 0; i < Canvas.rows; i++){
            free(Canvas.body[i]); 
            //printf("freed %i\n", i);
        }
    exit(0);
}

