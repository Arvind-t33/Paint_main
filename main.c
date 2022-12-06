#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "input_val.h"
#include "setup_canvas.h"
#include "get_command.h"


int main(int argc, char *argv[]) {

    char startChar = '*';
    CanvasBoard Canvas;
    CanvasBoard* CanvasP = &Canvas;
    if (isInputValid(argc, argv)) {
        Canvas.rows = atoi(argv[1]);
        Canvas.cols = atoi(argv[2]);
    }
    else {
        Canvas.rows = 10;
        Canvas.cols = 10;
    }
    Canvas.body = createCanvas(Canvas.rows, Canvas.cols, startChar);
    showCanvas(Canvas);
    bool commandValid = false;
    while (true){
        if (!commandValid) {
            commandValid = getCommand(Canvas, CanvasP);
        }
        printf("numCols = %i", Canvas.cols); // FIXME: delete
        printf("numRows = %i\n", Canvas.rows);
        showCanvas(Canvas);
    }
    return 0;
}
