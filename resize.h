#ifndef resize
    #define resize
    #include "main.h"
        void resize_main(CanvasBoard* CanvasPointer, int *resize_arguments);
        bool isValidResize(CanvasBoard* CanvasPointer, int rows, int cols);
        void resizeBoard(CanvasBoard* CanvasPointer, int newRows, int newCols);

#endif