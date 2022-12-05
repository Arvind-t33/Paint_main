#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "add.h"

void add_main(CanvasBoard Canvas, int *numRows, int *numCols, char choice, int num) {
    if (!is_rc_inBounds(Canvas, choice, num)) {
        printf("Improper add command.\n");
    }
    if (choice == 'r') {
        addRow(Canvas, numRows, numCols, num);
    }
    else if (choice == 'c') {
        addCol(Canvas, numRows, numCols, num);
    }
}

bool is_rc_inBounds(CanvasBoard Canvas, char choice, int num) {
    if (choice == 'r') {
        if ((num >= 0) && (num < Canvas.rows)) {
            return true;
        }
    }
    if (choice == 'c') {
        if ((num >= 0) && (num < Canvas.cols)) {
            return true;
        }
    }
    return false;
}

void addRow(CanvasBoard Canvas, int *numRows, int *numCols, int num) {
    appendRow(Canvas, numRows, numCols);
    (void) num;  

}

void addCol(CanvasBoard Canvas, int *numRows, int *numCols, int num) {
    appendCol(Canvas, numRows, numCols); 
    (void) num;  
}

void appendRow(CanvasBoard Canvas, int *numRows, int *numCols) {
    //printf("Called append Row\n");
    *numRows = *numRows + 1;
    Canvas.body = (char **) realloc(Canvas.body, (*numRows) * sizeof(char*));
    //printf("reallocated canvas\n");
    Canvas.body[*numRows - 1] = (char *) malloc(*numCols * sizeof(char));

    for (int i = 0; i < *numCols; i++) {
        Canvas.body[*numRows - 1][*numCols] = '*';
        //printf("Current char = %c\n", Canvas.body[*numRows - 1][*numCols]);
        //printf("Canvas has %i rows and numRows = %i\n", Canvas.rows, *numRows);
    }
}

void appendCol(CanvasBoard Canvas, int *numRows, int *numCols) {
    //printf("Called append Col\n");
    *numCols = *numCols + 1;
    Canvas.body = (char **) realloc(Canvas.body, (*numRows) * sizeof(char*));

    for(int i = 0; i < *numRows; i++){
        Canvas.body[i] = (char*)realloc(Canvas.body[i], (*numCols + 1) * sizeof(char));
        Canvas.body[i][*numCols - 1] = '*';
    }
}