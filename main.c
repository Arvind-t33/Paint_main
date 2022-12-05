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
            commandValid = getCommand(Canvas);
        }
        showCanvas(Canvas);
    }



    // char horiChar = '-';
    // char vertiChar = '|';
    // char rdChar = '/';
    // char ldChar = '\\';
    // char interChar = '+';

    // printf("%c\n", ldChar);

    //printf("The number of arguments are: %i\n", argc);
    return 0;
}
