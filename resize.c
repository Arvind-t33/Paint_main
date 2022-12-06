#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "resize.h" // FIXME: create/update this. 

/* void resize_main(CanvasBoard Canvas, int* resize_arguments, int* numRowsPointer, int* numColsPointer);
bool isValidResize(CanvasBoard Canvas, int rows, int cols);
void resizeBoard(CanvasBoard Canvas, int newRows, int newCols, int* numRowsPointer, int* numColsPointer); */ // FIXME: this should become resize.h

void resize_main(CanvasBoard* CanvasPointer, int *resize_arguments){
    int newRows = resize_arguments[0];
    int newCols = resize_arguments[1];
    if(isValidResize(CanvasPointer, newRows, newCols)){
        resizeBoard(CanvasPointer, newRows, newCols);
    }
    else{
        printf("Error: not caught by isValidResize or higher"); // FIXME: remove after implementation complete. 
    }

    return;
}
bool isValidResize(CanvasBoard* CanvasPointer, int rows, int cols){ // FIXME: COMPLETE FUNCTION
    (void)CanvasPointer;
    if(rows < 1){
        printf("The number of rows is less than 1.\n");
        return false;
    }
    if(cols < 1){
        printf("The number of columns is less than 1.\n");
        return false;
    }
    else{
        return true;
    }
}
void resizeBoard(CanvasBoard* CanvasPointer, int newRows, int newCols){ // Given the board and a new number of rows and columns, changes its size to them, and initializes any new empty space to *. Also updates Canvas dimensions.
    int rows = (*CanvasPointer).rows;
    int cols = (*CanvasPointer).cols;

    (*CanvasPointer).body = (char**)realloc((*CanvasPointer).body, newRows * sizeof(char*)); 
    for(int i = 0; i < newRows; i++){
        (*CanvasPointer).body[i] = (char*)realloc((*CanvasPointer).body[i], newCols * sizeof(char));
    }

    if(newRows > rows){ // If the number of rows increases, the new rows are entirely filled in as *
        for(int i = rows; i < newRows; i++){ 
            for(int j = 0; j < newCols; j++){
                (*CanvasPointer).body[i][j] = '*';
            }
        }
    }
    if(newCols > cols){ // If the number of columns increases, the new columns are entirely filled in as *
        for(int i = 0; i < newRows; i++){
            for(int j = cols; j < newCols; j++){
                (*CanvasPointer).body[i][j] = '*';
            }
        }
    }
    (*CanvasPointer).rows = newRows;
    (*CanvasPointer).cols = newCols;
}
