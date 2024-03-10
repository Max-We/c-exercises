#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// why are value and reverse defined with * prefix
// why return return char instead of char []
char *reverse(const char *value) {
    int len = strlen(value);
    char *result = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        result[len - 1 - i] = value[i];
    }

    result[len] = '\0';

    return result;
}

int main()
{
    printf(reverse("hallo"));
    return 0;
}
