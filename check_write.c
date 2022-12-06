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

    while ((c != '\n') && (isValid)) {
        numScanned = scanf(" %i%c", &num, &c);
        if (countArgs >= numArgs) {
            printf("Improper draw command.\n");
            isValid = false;
            return false;
        }
        else if (numScanned >= 1) {
            if (isspace(c) == 0) {
                printf("Improper draw command.\n");
                isValid = false;
                return false;
            }
        }

        if (num >= 0) {
            writeArgs[countArgs] = num;
        }
        countArgs++;
    }

    if (countArgs < numArgs) {
            printf("Improper draw command.\n");
            isValid = false;
            return false;
        }
    return true;
}