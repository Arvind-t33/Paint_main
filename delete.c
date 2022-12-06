#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "delete.h" // FIXME: create/update this. 

/* void delete_main(CanvasBoard Canvas, int* numRowsPointer, int* numColsPointer, char rc_choice, int num_rc);
bool isValidDelete(CanvasBoard Canvas, char rc_choice, int num_rc);
void delete_row(CanvasBoard Canvas, int row, int* numRowsPointer);
void delete_col(CanvasBoard Canvas, int col, int* numColsPointer); */

void delete_main(CanvasBoard Canvas, int* numRowsPointer, int* numColsPointer, char rc_choice, int num_rc){

    if(isValidDelete(Canvas, rc_choice, num_rc)){
        switch(rc_choice){
            case 'r' :
                delete_row(Canvas, num_rc, numRowsPointer);
                break;
            case 'c' :
                delete_col(Canvas, num_rc, numColsPointer);
                break;
        }
    }
    //else {} // FIXME: update failure behavior. Check which fails trigger which print statements. 
    
}
bool isValidDelete(CanvasBoard Canvas, char rc_choice, int num_rc){
    switch(rc_choice){
        case 'r' :
            if((0 <= num_rc) && (num_rc < Canvas.rows)){
                return true;
            } 
            return false;
            break;
        case 'c' :
            if((0 <= num_rc) && (num_rc < Canvas.cols)){
                    return true;
                } 
                return false;
                break;
    }
    return false;
}
void delete_row(CanvasBoard Canvas, int row, int* numRowsPointer){
    for(int currentRow = 0; currentRow < Canvas.rows - 1; currentRow++){
        for(int currentCol = 0; currentCol < Canvas.cols; currentCol++){
            if(currentRow < row){
                continue;
            }
            if(currentRow >= row){
                Canvas.body[currentRow][currentCol] = Canvas.body[currentRow + 1][currentCol];
            }
        }
    }
    Canvas.body = (char**)realloc(Canvas.body, (Canvas.rows - 1) * sizeof(char*));
    (*numRowsPointer) = Canvas.rows - 1;
    return;
}
void delete_col(CanvasBoard Canvas, int col, int* numColsPointer){
    for(int currentCol = 0; currentCol < Canvas.cols - 1; currentCol++){
        for(int currentRow = 0; currentRow < Canvas.rows; currentRow++){
            if(currentCol < col){
                continue;
            }
            if(currentCol >= col){
                Canvas.body[currentRow][currentCol] = Canvas.body[currentRow][currentCol + 1];
            }
        }
    }
    for(int i = 0; i < Canvas.rows; i++){
        Canvas.body[i] = (char*)realloc(Canvas.body[i], (Canvas.cols - 1) * sizeof(char));
    }
    (*numColsPointer) = Canvas.cols - 1;
    return;
}