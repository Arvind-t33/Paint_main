#ifndef delete
    #define delete
    #include "main.h"
        void delete_main(CanvasBoard* CanvasPointer, char rc_choice, int num_rc);
        bool isValidDelete(CanvasBoard* CanvasPointer, char rc_choice, int num_rc);
        void delete_row(CanvasBoard* CanvasPointer, int row);
        void delete_col(CanvasBoard* CanvasPointer, int col);

#endif