#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "check_add.h"

bool get_add_input(int numArgs, char *choice, int *num) {  
    /*FIXME: if we enter non-digit values for rows and columns, it behaves as expected, but asks for input many times.
    we can fix it by reading the rest of the input until the newline in case invalid input is entered, so that input 
    isnt scanned again in main.c*/

    int scannedNum = -1;
    char c;
    int numScanned;
    int countArgs = 0;
    char spaceChar;
    bool isValid = true;
    *num = -1;

    while ((c != '\n') && (isValid)) {
        if (countArgs == 0) {
            numScanned = scanf(" %c%c", &c, &spaceChar);
        }
        else if (countArgs == 1){
            numScanned = scanf(" %i%c", &scannedNum, &c);
        }
        if (countArgs >= numArgs) {
            printf("Improper add command.\n");
            isValid = false;
            return false;
        }

        if (countArgs == 0) {
            if (!((c == 'r') || (c == 'c'))) {
                printf("Improper add command.\n");
                isValid = false;
                return false;
            }
            else if (spaceChar == '\n') {
                printf("Improper add command.\n");
                isValid = false;
                return false; 
            }
        }
        else if ((countArgs > 0) && (numScanned >= 1)) {
            if (isspace(c) == 0) {
                printf("Improper add command.\n");
                isValid = false;
                return false;
            } 
        }

        if (countArgs == 0) {
            *choice = c;
        }
        else if(countArgs == 1) {
            *num = scannedNum;
        }

        if (numScanned < 0) {
            printf("Improper add command.\n");
            isValid = false;
            return false;
        }

        countArgs++;

    }

    if (countArgs < numArgs) {
            printf("Improper add command.\n");
            isValid = false;
            return false;
    }

    return true;
}