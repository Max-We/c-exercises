#include "hamming.h"
#include "string.h"

int compute(const char *lhs, const char *rhs) {
    size_t len = strlen(lhs);
    if (len != strlen(rhs)) {
        return -1;
    }

    int distance = 0;
    for (int i = 0; i < (int) strlen(lhs); i++) {
        if (lhs[i] != rhs[i]) {
            distance++;
        }
    }
    return distance;
}