#ifndef resize
    #define resize
    #include "main.h"
        void resize_main(CanvasBoard Canvas, int* resize_arguments, int* numRowsPointer, int* numColsPointer);
        bool isValidResize(CanvasBoard Canvas, int rows, int cols);
        void resizeBoard(CanvasBoard Canvas, int newRows, int newCols, int* numRowsPointer, int* numColsPointer);

#endif