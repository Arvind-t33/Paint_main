#ifndef WRITE
    #define WRITE

        void erase_main(CanvasBoard Canvas, int* eraseVals);
        void erase_square(CanvasBoard Canvas, int row, int col);
        void draw_main(CanvasBoard Canvas, int* array);
        void write_line(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col);
        bool isInBounds(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col);

        bool isStraightLine(int start_row, int start_col, int end_row, int end_col);
        bool isShortLine(int start_row, int start_col, int end_row, int end_col);
        bool isHorizontalLine(int start_row, int start_col, int end_row, int end_col);
        bool isVerticalLine(int start_row, int start_col, int end_row, int end_col);
        bool isRightDiagonalLine(int start_row, int start_col, int end_row, int end_col);
        bool isLeftDiagonalLine(int start_row, int start_col, int end_row, int end_col);

        void drawShortLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col);
        void drawHorizontalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col);
        void drawVerticalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col);
        void drawRightDiagonalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col);
        void drawLeftDiagonalLine(CanvasBoard Canvas, int start_row, int start_col, int end_row, int end_col);
#endif