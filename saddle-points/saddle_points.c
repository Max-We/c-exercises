#include "saddle_points.h"
#include <stdlib.h>
#include <stdbool.h>

saddle_points_t *saddle_points(int rows, int cols, uint8_t matrix[rows][cols]) {
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {

    //     }
    // }
    saddle_points_t *result = malloc(*saddle_points_t);

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            uint8_t value = matrix[i][j];
            bool isHighest = true;
            bool isLowest = true;
            // horizontal
            for (int row=0; row<rows; row++) {
                if (value < matrix[row][j]) {
                    isHighest = false;
                }
            }
            // vertical
            for (int col=0; col<cols; col++) {
                if (value > matrix[i][col]) {
                    isLowest = false;
                }
            }

            if(isLowest && isHighest) {
                result->count++;
            }
        }
    }


    return result;
}

void free_saddle_points(saddle_points_t *saddlePoints) {
    free(saddlePoints);
}