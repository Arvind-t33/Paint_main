#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "delete.h" // FIXME: create/update this. 

/* void delete_main(CanvasBoard Canvas, int* numRowsPointer, int* numColsPointer, char rc_choice, int num_rc);
bool isValidDelete(CanvasBoard Canvas, char rc_choice, int num_rc);
void delete_row(CanvasBoard Canvas, int row, int* numRowsPointer);
void delete_col(CanvasBoard Canvas, int col, int* numColsPointer); */

void delete_main(CanvasBoard* CanvasPointer, char rc_choice, int num_rc){
    if(isValidDelete(CanvasPointer, rc_choice, num_rc)){
        switch(rc_choice){
            case 'r' :
                delete_row(CanvasPointer, num_rc);
                break;
            case 'c' :
                delete_col(CanvasPointer, num_rc);
                break;
        }
    }
    //else {} // FIXME: update failure behavior. Check which fails trigger which print statements. 
}
bool isValidDelete(CanvasBoard* CanvasPointer, char rc_choice, int num_rc){
    switch(rc_choice){
        case 'r' :
            if((0 <= num_rc) && (num_rc < (*CanvasPointer).rows)){
                return true;
            } 
            printf("Improper delete command.\n");
            return false;
            break;
        case 'c' :
            if((0 <= num_rc) && (num_rc < (*CanvasPointer).cols)){
                    return true;
                } 
                printf("Improper delete command.\n");
                return false;
                break;
    }
    return false;
}
void delete_row(CanvasBoard* CanvasPointer, int row){
    int rows = (*CanvasPointer).rows;
    int cols = (*CanvasPointer).cols;
    for(int currentRow = 0; currentRow < rows - 1; currentRow++){
        for(int currentCol = 0; currentCol < cols; currentCol++){
            if(currentRow < row){
                continue;
            }
            if(currentRow >= row){
                (*CanvasPointer).body[currentRow][currentCol] = (*CanvasPointer).body[currentRow + 1][currentCol];
            }
        }
    }
    (*CanvasPointer).body = (char**)realloc((*CanvasPointer).body, (rows - 1) * sizeof(char*));
    (*CanvasPointer).rows = rows - 1;
    return;
}
void delete_col(CanvasBoard* CanvasPointer, int col){
    int rows = (*CanvasPointer).rows;
    int cols = (*CanvasPointer).cols;
    for(int currentCol = 0; currentCol < cols - 1; currentCol++){
        for(int currentRow = 0; currentRow < rows; currentRow++){
            if(currentCol < col){
                continue;
            }
            if(currentCol >= col){
                (*CanvasPointer).body[currentRow][currentCol] = (*CanvasPointer).body[currentRow][currentCol + 1];
            }
        }
    }
    for(int i = 0; i < rows; i++){
        (*CanvasPointer).body[i] = (char*)realloc((*CanvasPointer).body[i], (cols - 1) * sizeof(char));
    }
    (*CanvasPointer).cols = cols - 1;
    return;
}