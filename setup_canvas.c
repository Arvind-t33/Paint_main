#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> // FIXME: remove extra dependencies when compiling in main()
#include "setup_canvas.h"
#include "main.h"

// Setup takes in the parameters numRows and numCols from argv[] and creates a Canvas. Initializes current player's turn to 1. 

/*
    Creates a dynamically allocated 2d Canvas with rows and columns equal to user input
    @param rows: the number of rows that the user wants the Canvas to have
    @param cols: the number of coluns that the user wants the Canvas to have
    @param startChar: the default character that the Canvas is to be filled with when there are no pieces. 
    @returns: a 2d array that is the Canvas. 
*/
char** createCanvas(int rows, int cols, char startChar){ 
    
    char** Canvas;

    Canvas = (char**)malloc(sizeof(char*) * (rows));

    for(int i = 0; i < rows; i++){
        Canvas[i] = (char*)malloc(sizeof(char)*cols);
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            
            
            Canvas[i][j] = startChar;
            // printf("i = %d, j = %d and num = %c\n", i, j, Canvas[i][j]);
        }
    }
    return Canvas;

}


/*
    Traverses each elemnt in the Canvas to print it.
    @param Canvas: the Canvas that is to be printed
    @param rows: the number of rows in the Canvas.
    @param cols: the number of columns in the Canvas.
    @returns.
*/
void showCanvas(CanvasBoard Canvas){
    // printf("rows = %i and cols = %i\n", rows, cols);
    for(int i = 0; i < Canvas.rows + 1; i++){
        if (i != Canvas.rows) {
            printf("%i ", Canvas.rows - (i + 1));
        }
        for(int j = 0; j < Canvas.cols + 1; j++){
            if (i == Canvas.rows) {
                if (j == 0) {
                    printf("  ");
                }
                else {
                    printf("%i ", j - 1);
                }
            }
            else if (j < Canvas.cols){
                printf("%c ", Canvas.body[Canvas.rows - i - 1][j]);
            }
            
        }
        printf("\n");
    }
}


    
