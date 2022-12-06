#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool get_resize_input(int numArgs, int resizeArgs[numArgs]) {
    int scannedNum = -1;
    char spaceChar;
    int numScanned;
    int countArgs = 0;

    while (spaceChar != '\n') {
        if (countArgs == 0) {
            numScanned = scanf(" %i%c", &scannedNum, &spaceChar);
        }
        else if (countArgs == 1) {
            numScanned = scanf(" %i%c", &scannedNum, &spaceChar);
        }
        else if (countArgs >= numArgs) {
            printf("Improper resize command.\n");
            return false;
        }

        if (isspace(spaceChar) == 0) {
            printf("Improper resize command.\n");
            return false;
        }
        if (scannedNum < 0) {
            printf("Improper resize command.\n");
            return false;
        }

        if (numScanned < 0) {
            printf("Improper resize command.\n");
            return false;
        }

        resizeArgs[countArgs] = scannedNum;

        countArgs++;
    }

    if (countArgs < numArgs) {
        printf("Improper resize command.\n");
        return false;
    }

    return true;
}