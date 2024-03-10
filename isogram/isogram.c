#include "isogram.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {
    if(!phrase) {
        return false;
    }

    long unsigned int length = strlen(phrase);
    if (length == 0) {
        return true;
    }

    for(long unsigned int i = 0; i < length - 1; i++) {
        for(long unsigned int j = 0; j < length; j++) {
            char current = tolower(phrase[i]);
            if (current == tolower(phrase[j]) && i != j && phrase[i] >= 'a' && phrase[i] <= 'z') {
                return false;
            }
        }
    }
    return true;
}