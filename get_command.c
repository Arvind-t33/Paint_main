#include <stdio.h>
#include <stdbool.h>
#include "get_command.h"
#include "quit.h"
#include "print_statements.h"
#include "check_write.h"
#include "check_add.h"
#include "check_resize.h"
#include "write.h"
#include "add.h"
#include "delete.h"
#include "resize.h"



bool getCommand(CanvasBoard Canvas, CanvasBoard* CanvasPointer) { // goto main after
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

    bool resizeInputValid = true;
    int numResizeArgs = 2;
    int resize_vals[numResizeArgs];


    printf("Enter your command: "); 
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
                add_main(CanvasPointer, rc_choice, num_rc);
            }
            break;
        case 'r' :
            resizeInputValid = get_resize_input(numResizeArgs, resize_vals);
            if (resizeInputValid){
                resize_main(CanvasPointer, resize_vals);
            }
            break;
        case 'd' :
            deleteInputValid = get_add_input(numDeleteArgs, &rc_choice, &num_rc);
            if (deleteInputValid){
                delete_main(CanvasPointer, rc_choice, num_rc);
            }
            break; 
        default :
            printf("Unrecognized command. Type h for help.\n");
    }

    return false;

}
    
        
    