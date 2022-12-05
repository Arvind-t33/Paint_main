#include <stdio.h>
#include <stdbool.h>
#include "get_command.h"
#include "quit.h"
#include "print_statements.h"
#include "check_write.h"
#include "check_add.h"
#include "write.h"


bool getCommand(CanvasBoard Canvas) {
    char command;

    bool writeInputValid = true;
    int numWriteArgs = 4;
    int write_vals[numWriteArgs];

    bool addInputValid = true;
    int numAddArgs = 2;
    char rc_choice;
    int num_rc;
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
    
        
    