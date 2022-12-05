#include <stdio.h>
#include <stdbool.h>
#include "main.h"
// #include "resize.h" // FIXME: create/update this. 

void resize_main(CanvasBoard Canvas, int* resize_arguments);
bool isValidResize(CanvasBoard Canvas, int rows, int cols);
void resizeBoard(CanvasBoard Canvas, int newRows, int newCols); // FIXME: this should become resize.h

void resize_main(CanvasBoard Canvas, int* resize_arguments){
    int newRows = resize_arguments[0];
    int newCols = resize_arguments[1];
    if(isValidResize(Canvas, newRows, newCols)){
        resizeBoard(Canvas, newRows, newCols);
    }
    else{
        printf("Error: not caught by isValidResize or higher"); // FIXME: remove after implementation complete. 
    }

    return;
}
bool isValidResize(CanvasBoard Canvas, int rows, int cols){ // FIXME: check where we want to implement this function and also which checks occur when (non-integer should be caught upstream)
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
void resizeBoard(CanvasBoard Canvas, int newRows, int newCols){ // Given the board and a new number of rows and columns, changes its size to them, and initializes any new empty space to *. Also updates Canvas dimensions.
    Canvas.body = (char**)realloc(Canvas.body, newRows * sizeof(char*)); 
    for(int i = 0; i < newRows; i++){
        Canvas.body[i] = (char*)realloc(Canvas.body[i], newCols * sizeof(char));
    }

    if(newRows > Canvas.rows){ // If the number of rows increases, the new rows are entirely filled in as *
        for(int i = Canvas.rows; i < newRows; i++){ 
            for(int j = 0; j < newCols; j++){
                Canvas.body[i][j] = '*';
            }
        }
    }
    if(newCols > Canvas.cols){ // If the number of columns increases, the new columns are entirely filled in as *
        for(int i = 0; i < newRows; i++){
            for(int j = Canvas.cols; j < newCols; j++){
                Canvas.body[i][j] = '*';
            }
        }
    }
    Canvas.rows = newRows;
    Canvas.cols = newCols;
}
