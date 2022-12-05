#include <stdio.h>
#include <stdbool.h>
#include "main.h"
// #include "delete.h" // FIXME: create/update this. 

void delete_main(CanvasBoard Canvas, int* delete_arguments);
bool isValidDelete(CanvasBoard Canvas, char rc_choice, int num_rc);
void delete_row(CanvasBoard Canvas, int row);
void delete_col(CanvasBoard Canvas, int col);

void delete_main(CanvasBoard Canvas, int* delete_arguments){
    char rc = delete_arguments[0];
    int num_rc = atoi(delete_arguments[1]); // FIXME: check the array type of delete arguments, or just pass them as a single char and single number instead of array
    if(isValidDelete(Canvas, rc, num_rc)){
        switch(rc){
            case 'r' :
                delete_row(Canvas, num_rc);
                break;
            case 'c' :
                delete_col(Canvas, num_rc);
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
}
void delete_row(CanvasBoard Canvas, int row){
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
    Canvas.body = (char**)realloc((Canvas.rows - 1) * sizeof(char*));
    Canvas.rows = Canvas.rows - 1;
    return;
}
void delete_col(CanvasBoard Canvas, int col){
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
        Canvas.body[i] = (char*)realloc((Canvas.cols - 1) * sizeof(char));
    }
    Canvas.cols = Canvas.cols - 1;
    return;
}