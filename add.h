#ifndef add
    #define add
    #include "main.h"
   
    void add_main(CanvasBoard* CanvasPointer, char rc_choice, int index_to_add);
    bool is_rc_inBounds(CanvasBoard* CanvasPointer, char choice, int index_to_add);
    void addRow(CanvasBoard* CanvasPointer, int index_to_add);
    void addCol(CanvasBoard* CanvasPointer, int index_to_add);

#endif 