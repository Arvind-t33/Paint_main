#include <stdio.h>
#include <stdbool.h>
#include "get_command.h"
#include "quit.h"
#include "print_statements.h"
#include "check_write.h"
#include "check_add.h"
#include "write.h"
#include "add.h"
#include "delete.h"


bool getCommand(CanvasBoard Canvas, int *numRowsPointer, int *numColsPointer) {
    char command;

    bool writeInputValid = true;
    int numWriteArgs = 4;
    int write_vals[numWriteArgs];

    bool addInputValid = true;
    int numAddArgs = 2;
    char rc_choice;
    int num_rc;

    bool deleteInputValid = true;
    int numDeleteArgs = 2;
    
    //printf("getCommand was called\n");
    printf("Enter your command: \n"); // Added a newline cuz it looks jank if you dont
    scanf(" %c", &command);

    switch(command) {
        case 'q' :
            freeCanvas(Canvas);
            break;
        case 'h' :
            print_help();
            break;
        case 'w' :
            writeInputValid = get_input(numWriteArgs, write_vals);
            if (writeInputValid) {
                draw_main(Canvas, write_vals);
            }
            break;
        /*case 'e' :
            eraseInputValid = get_erase_input(numEraseArgs, erase_vals); // FIXME: need to set these
            if (eraseInputValid){
                erase_main(Canvas, erase_vals);
            }
            break; */
        case 'a' :
            addInputValid = get_add_input(numAddArgs, &rc_choice, &num_rc);
            if (addInputValid) {
                add_main(Canvas, numRowsPointer, numColsPointer, rc_choice, num_rc);
            }
            break;
        /* case 'r' :
            resizeInputValid = get_resize_input(numResizeArgs, resize_vals);
            if (resizeInputValid){
                resize_main(Canvas, resize_vals, numRowsPointer, numColsPointer);
            }
            break; */
        case 'd' :
            deleteInputValid = get_add_input(numDeleteArgs, &rc_choice, &num_rc);
            if (deleteInputValid){
                delete_main(Canvas, numRowsPointer, numColsPointer, rc_choice, num_rc);
            }
            break; 
    }

    // for (int i = 0; i < numWriteArgs; i++) {
    //     printf("the array at index %i is %i\n", i, write_vals[i]);
    // }


    if ((!writeInputValid) || (!addInputValid)) {
        return false;
    }
    return false;

}
    
        
    