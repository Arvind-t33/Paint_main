#ifndef add
    #define add
    #include "main.h"
   
    void add_main(CanvasBoard Canvas, int *numRows, int *numCols, char choice, int num);
    bool is_rc_inBounds(CanvasBoard Canvas, char choice, int num);

    void addRow(CanvasBoard Canvas, int *numRows, int *numCols, int num);
    void addCol(CanvasBoard Canvas, int *numRows, int *numCols, int num);

    void appendRow(CanvasBoard Canvas, int *numRows, int *numCols);
    void appendCol(CanvasBoard Canvas, int *numRows, int *numCols);

#endif 