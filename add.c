#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "add.h"

/*void add_main(CanvasBoard Canvas, int *numRowsPointer, int *numColsPointer, char rc_choice, int index_to_add);
bool is_rc_inBounds(CanvasBoard Canvas, char choice, int index_to_add);
void addRow(CanvasBoard Canvas, int *numRowsPointer, int index_to_add);
void addCol(CanvasBoard Canvas, int *numColsPointer, int index_to_add);*/

void add_main(CanvasBoard Canvas, int *numRowsPointer, int *numColsPointer, char rc_choice, int index_to_add){
    if (!is_rc_inBounds(Canvas, rc_choice, index_to_add)) {
        printf("Improper add command.\n");
    }
    if (rc_choice == 'r') {
        addRow(Canvas, numRowsPointer, index_to_add);
    }
    else if (rc_choice == 'c') {
        addCol(Canvas, numColsPointer, index_to_add);
    }
}
bool is_rc_inBounds(CanvasBoard Canvas, char choice, int index_to_add){
    if (choice == 'r') {
        if ((index_to_add >= 0) && (index_to_add < Canvas.rows)) {
            return true;
        }
    }
    if (choice == 'c') {
        if ((index_to_add >= 0) && (index_to_add < Canvas.cols)) {
            return true;
        }
    }
    return false;
}
void addRow(CanvasBoard Canvas, int *numRowsPointer, int index_to_add){
    Canvas.body = (char**)realloc(Canvas.body, (Canvas.rows + 1) * sizeof(char*));
    Canvas.body[Canvas.rows] = malloc(Canvas.cols * sizeof(char));
    for(int i = Canvas.rows; i >= 0; i--){
        for(int j = 0; j < Canvas.cols; j++){
            if(i > index_to_add){
                Canvas.body[i][j] = Canvas.body[i-1][j];
            } 
            else if(i == index_to_add){
                Canvas.body[i][j] = '*';
            }
            else{
                continue;
            }
        }
    }
    (*numRowsPointer) = Canvas.rows + 1;
    return;
}
void addCol(CanvasBoard Canvas, int *numColsPointer, int index_to_add){
    for(int i = 0; i < Canvas.rows; i++){
        Canvas.body[i] = (char*)realloc(Canvas.body[i], (Canvas.cols + 1) * sizeof(char));
    }
    for(int j = Canvas.cols; j >= 0; j--){
        for(int i = 0; i < Canvas.rows; i++){
                if(j > index_to_add){
                    Canvas.body[i][j] = Canvas.body[i][j-1];
                }
                else if(j == index_to_add){
                    Canvas.body[i][j] = '*';
                }
                else{
                    continue;
                }
        }
    }
    (*numColsPointer) = Canvas.cols + 1;
    return;
}


    