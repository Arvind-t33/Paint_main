#include <stdbool.h> // FIXME: check dependencies later
#include <stdio.h>
#include "main.h" 
#include "write.h"

void draw_main(CanvasBoard Canvas, int* array){
    int startRow = array[0];
    int startCol = array[1];
    int endRow = array[2];
    int endCol = array[3];
    write_line(Canvas, startRow, startCol, endRow, endCol);
}
void write_line(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col){
    if(!isInBounds(Canvas, start_row, start_col, end_row, end_col)){
        printf("Improper draw command.\n");
    }
    else{
        if(isShortLine(start_row, start_col, end_row, end_col)){
            drawShortLine(Canvas, start_row, start_col, end_row, end_col); 
        }
        else if(isHorizontalLine(start_row, start_col, end_row, end_col)){
            drawHorizontalLine(Canvas, start_row, start_col, end_row, end_col); 
        }
        else if (isVerticalLine(start_row, start_col, end_row, end_col)){
            drawVerticalLine(Canvas, start_row, start_col, end_row, end_col); 
        }
        else if (isRightDiagonalLine(start_row, start_col, end_row, end_col)){
            drawRightDiagonalLine(Canvas, start_row, start_col, end_row, end_col);
        }
        else if (isLeftDiagonalLine(start_row, start_col, end_row, end_col)){
            drawLeftDiagonalLine(Canvas, start_row, start_col, end_row, end_col);
        }
        else{
            printf("Improper draw command.\n");
        }
    }
    return; // Potential FIXME: May need to return some value to inform success/failure to higher function. 
}
bool isInBounds(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col){
    if((start_row >= 0) && (start_row < Canvas.rows) && (start_col >= 0) && (start_col) <= (Canvas.cols)){
        if((end_row >= 0) && (end_row < Canvas.rows) && (end_col >= 0) && (end_col) <= (Canvas.cols)){
            return true;
        }
    }
    return false;
}

bool isStraightLine(int start_row, int start_col, int end_row, int end_col){
    bool isShort = isShortLine(start_row, start_col, end_row, end_col);
    bool isHorizontal = isHorizontalLine(start_row, start_col, end_row, end_col);
    bool isVertical = isVerticalLine(start_row, start_col, end_row, end_col);
    bool isRightDiagonal = isRightDiagonalLine(start_row, start_col, end_row, end_col);
    bool isLeftDiagonal = isLeftDiagonalLine(start_row, start_col, end_row, end_col);

    if(isShort || isHorizontal || isVertical || isRightDiagonal || isLeftDiagonal){
        return true;
    }
    else{
        printf("FIXME: not a straight line prompt\n"); // FIXME: find correct prompt
    }
    return false; 
}
bool isShortLine(int start_row, int start_col, int end_row, int end_col){
    if((start_row == end_row) && (start_col == end_col)){
        return true;
    }
    return false;
}
bool isHorizontalLine(int start_row, int start_col, int end_row, int end_col){
    if((start_row == end_row) && (start_col != end_col)){
        return true;
    }
    return false;
}
bool isVerticalLine(int start_row, int start_col, int end_row, int end_col){
    if((start_row != end_row) && (start_col == end_col)){
        return true;
    }
    return false;
}
bool isRightDiagonalLine(int start_row, int start_col, int end_row, int end_col){
    if((end_col - start_col) == (end_row - start_row)){
        return true;
    }
    return false;
}
bool isLeftDiagonalLine(int start_row, int start_col, int end_row, int end_col){
    if((end_col - start_col) == (start_row - end_row)){
        return true;
    }
    return false;
}

void drawShortLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col){
    (void)end_row;
    (void)end_col;
    char current = Canvas.body[start_row][start_col];
    if(current == '*' || current == '-'){
        Canvas.body[start_row][start_col] = '-';
    }
    else{
        Canvas.body[start_row][start_col] = '+';
    }
    return;
}
void drawHorizontalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col){
    (void)end_row;
    int left, right;
    if(start_col < end_col){
        left = start_col;
        right = end_col;
    }
    else{
        left = end_col;
        right = start_col;
    }
    for(int j = left; j <= right; j++){
        int i = start_row;
        char current = Canvas.body[i][j];
        if(current == '*' || current == '-'){
            Canvas.body[i][j] = '-';
        }
        else{
            Canvas.body[i][j] = '+';
        }
    }
    return;
}
void drawVerticalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col){
    (void)end_col;
    int bot, top;
    if(start_row < end_row){
        bot = start_row;
        top = end_row;
    }
    else{
        bot = end_row;
        top = start_row;
    }
    for(int i = bot; i <= top; i++){
        int j = start_col;
        char current = Canvas.body[i][j];
        if(current == '*' || current == '|'){
            Canvas.body[i][j] = '|';
        }
        else{
            Canvas.body[i][j] = '+';
        }
    }
    return;
}
void drawRightDiagonalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col){
    int bot, left, top, right;
    if(start_row < end_row){
        bot = start_row;
        left = start_col;
        top = end_row;
        right = end_col;
    }
    else{
        bot = end_row;
        left = end_col;
        top = start_row;
        right = start_col;
    }
    (void)right;
    int j = left;
    for(int i = bot; i <= top; i++){
        char current = Canvas.body[i][j];
        if(current == '*' || current == '/'){
            Canvas.body[i][j] = '/';
        }
        else{
            Canvas.body[i][j] = '+';
        }
        j++;
    }
    return;
}
void drawLeftDiagonalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col){
    int bot, left, top, right;
    if(start_row < end_row){
        bot = start_row;
        right = start_col;
        top = end_row;
        left = end_col;
    }
    else{
        bot = end_row;
        right = end_col;
        top = start_row;
        left = start_col;
    }
    (void)left;
    int j = right;
    for(int i = bot; i <= top; i++){
        char current = Canvas.body[i][j];
        if(current == '*' || current == '\\'){
            Canvas.body[i][j] = '\\';
        }
        else{
            Canvas.body[i][j] = '+';
        }
        j--;
    }
    return;
}
