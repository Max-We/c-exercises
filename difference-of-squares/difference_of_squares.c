#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number){
    unsigned int result = 0;
    for (unsigned int i = 1; i <= number; i++) {
        result += i*i;
    }
}

unsigned int square_of_sum(unsigned int number){
    unsigned int sum = (number * number + number) / 2;
    return sum * sum;
}

unsigned int difference_of_squares(unsigned int number){
    return square_of_sum(number) - sum_of_squares(number);
}
