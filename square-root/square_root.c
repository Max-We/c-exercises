#include "square_root.h"

int square_root(int number) {
    long int root = number;

    int low = 0;
    int high = number;

    do {
        if (number == root * root) {
            return root;
        } else if (number > root * root) {
            low = root;
        } else {
            high = root;
        }
        root = (low + high) / 2;
    } while (root > 0 && high - low > 1);

    return -1;
}


// int main() {
//     int res = square_root(255*255);
// }