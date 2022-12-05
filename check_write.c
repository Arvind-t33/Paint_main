#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "check_write.h"
#include "input_val.h"

bool get_input(int numArgs, int writeArgs[numArgs]) {  //FIXME: if we enter non-digit values for rows and columns, it behaves as expected, but asks for input many times.
                            // we can fix it by reading the rest of the input until the newline in case invalid input is entered, so that input 
                            // isnt scanned again in main.c


    int num = -1;
    char c;
    int numScanned;
    int countArgs = 0;
    bool isValid = true;
    //printf("get_input was just called\n");

    while ((c != '\n') && (isValid)) {
        //("scanned input and isValid is %s\n", isValid ? "true" : "false");
        numScanned = scanf(" %i%c", &num, &c);
        //printf("countArgs = %i\n", countArgs);
        if (countArgs >= numArgs) {
            printf("Improper draw command.\n");
            isValid = false;
            return false;
        }
        else if (numScanned >= 1) {
            //("numScanned = %i\n", numScanned);
            // printf("The number is: %i\n", num);
            // printf("The character is: %c\n", c);
            if (isspace(c) == 0) {
                //printf("c was not a space\n");
                printf("Improper draw command.\n");
                isValid = false;
                return false;
            }
        }

        if (num >= 0) {
            //printf("countArgs = %i\n", countArgs);
            writeArgs[countArgs] = num;
            //printf("the current value is: %i\n", num);
        }
        // if (writeArgs[numArgs] > 1000) { // remove this
        //     printf("this is true\n");
        //     isValid = true;
        // }
        countArgs++;
    }

    if (countArgs < numArgs) {
            //printf("countArgs = %i\n", countArgs);
            printf("Improper draw command.\n");
            isValid = false;
            return false;
        }
    return true;
}