#ifndef add
    #define add
    #include "main.h"
   
    void add_main(CanvasBoard Canvas, int *numRowsPointer, int *numColsPointer, char rc_choice, int index_to_add);
    bool is_rc_inBounds(CanvasBoard Canvas, char choice, int index_to_add);
    void addRow(CanvasBoard Canvas, int *numRowsPointer, int index_to_add);
    void addCol(CanvasBoard Canvas, int *numColsPointer, int index_to_add);

#endif 