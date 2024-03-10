#include "pascals_triangle.h"
#include <stdlib.h>
#include <stdio.h>

void free_triangle(uint8_t **triangle, size_t rows) {
    for (size_t row = 0; row < rows; row++) {
        free(triangle[row]); triangle[row] = NULL;
    }
    free(triangle); triangle = NULL;
}

uint8_t **create_triangle(size_t rows){
    if (rows == 0) {
        uint8_t **triangle = create_triangle(1);
        triangle[0][0] = 0;
        return triangle;
    }

    uint8_t **triangle = calloc(rows, sizeof(uint8_t*));

    for (size_t i=0; i<rows; i++){
        triangle[i] = calloc((rows), sizeof(uint8_t));

        if (i == 0 && rows > 1) {
            triangle[0][0] = 1;
            continue;
        }

        for (size_t j=0; j<=rows; j++) {
            if (j == 0) {
                triangle[i][j] = 1;
                continue;
            }
            uint8_t left = (i > 0 && j > 0) ? triangle[i-1][j-1] : 0;
            uint8_t right = i > 0 ? triangle[i-1][j] : 0;
            triangle[i][j] =  left + right;
        }
    }
    return triangle;
}

// int main() {
//     size_t rows = 10;
//     uint8_t **result = create_triangle(rows);
//     for (int i = 0; i<rows; i++) {
//         printf("\n");
//         for (int j = 0; j<rows; j++) {
//             printf("%d ", result[i][j]);
//         }
//     }
// }