#ifndef delete
    #define delete
    #include "main.h"
        void delete_main(CanvasBoard Canvas, int* numRowsPointer, int* numColsPointer, char rc_choice, int num_rc);
        bool isValidDelete(CanvasBoard Canvas, char rc_choice, int num_rc);
        void delete_row(CanvasBoard Canvas, int row, int* numRowsPointer);
        void delete_col(CanvasBoard Canvas, int col, int* numColsPointer);

#endif