#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "add.h"
#include "setup_canvas.h" // FIXME: REMOVE THIS ONLY USED IN TESTING

/*void add_main(CanvasBoard Canvas, int *numRowsPointer, int *numColsPointer, char rc_choice, int index_to_add);
bool is_rc_inBounds(CanvasBoard Canvas, char choice, int index_to_add);
void addRow(CanvasBoard Canvas, int *numRowsPointer, int index_to_add);
void addCol(CanvasBoard Canvas, int *numColsPointer, int index_to_add);*/

void add_main(CanvasBoard* CanvasPointer, char rc_choice, int index_to_add){
    if (!is_rc_inBounds(CanvasPointer, rc_choice, index_to_add)) {
        printf("Improper add command.\n");
    }
    if (rc_choice == 'r') {
        addRow(CanvasPointer, index_to_add);
        printf("outside of addRow: new rows: %d new cols:%d\n", (*CanvasPointer).rows, (*CanvasPointer).cols); // remove
    }
    else if (rc_choice == 'c') {
        addCol(CanvasPointer, index_to_add);
    }
}
bool is_rc_inBounds(CanvasBoard* CanvasPointer, char choice, int index_to_add){
    if (choice == 'r') {
        if ((index_to_add >= 0) && (index_to_add < (*CanvasPointer).rows)){
            return true;
        }
        else{
            return false;
        }
    }
    if (choice == 'c') {
        if ((index_to_add >= 0) && (index_to_add < (*CanvasPointer).cols)) {
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}
void addRow(CanvasBoard* CanvasPointer, int index_to_add){
    int rows = (*CanvasPointer).rows;
    int cols = (*CanvasPointer).cols;
    (*CanvasPointer).body = (char**)realloc((*CanvasPointer).body, (rows + 1) * sizeof(char*));
    (*CanvasPointer).body[(*CanvasPointer).rows] = malloc(cols * sizeof(char));
    for(int i = rows; i >= 0; i--){
        for(int j = 0; j < cols; j++){
            if(i > index_to_add){
                (*CanvasPointer).body[i][j] = (*CanvasPointer).body[i-1][j];
            } 
            else if(i == index_to_add){
                (*CanvasPointer).body[i][j] = '*';
            }
            else{
                continue;
            }
        }
    }
    (*CanvasPointer).rows = rows + 1;
    printf("rows = %d\n", (*CanvasPointer).rows);
    return;
}
void addCol(CanvasBoard* CanvasPointer, int index_to_add){
    int rows = (*CanvasPointer).rows;
    int cols = (*CanvasPointer).cols;
    for(int i = 0; i < rows; i++){
        (*CanvasPointer).body[i] = (char*)realloc((*CanvasPointer).body[i], (cols + 1) * sizeof(char));
    }
    for(int j = cols; j >= 0; j--){
        for(int i = 0; i < rows; i++){
                if(j > index_to_add){
                    (*CanvasPointer).body[i][j] = (*CanvasPointer).body[i][j-1];
                }
                else if(j == index_to_add){
                    (*CanvasPointer).body[i][j] = '*';
                }
                else{
                    continue;
                }
        }
    }
    (*CanvasPointer).cols = cols + 1;
    return;
}


    