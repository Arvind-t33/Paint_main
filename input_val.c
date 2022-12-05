#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "input_val.h"

bool isInputValid(int numArgs, char *inputArgs[]){
    const int correctNumArgs = 3;
    if (numArgs == correctNumArgs){
        if (isAllArgsNum(numArgs, inputArgs)) {
            return true;
        }
        else {
            return false;
        }
        
    }
    else if (numArgs == 1) {
        return false;
    }
    else {
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
    }
        
    return false;
}

bool isAllArgsNum(int numArgs, char* inputArgs[]){
    for(int i = 1; i < numArgs; i++){ // 
        char *a = inputArgs[i]; // Creates new arrays for each element to separate them, then makes sure every character of them is a number
        for (unsigned int j = 0; j < (unsigned int)strlen(a); j++) {
            if(!isdigit((unsigned char) a[j])){
                return false;
            }
        }
    }
    return true;
}


