#include "stdlib.h"
#include <stdio.h>
#include <time.h>

int generate_code(char *filename, double duration) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the output file %s", filename);
        return -1;
    }

    double start_time = time(NULL);
    double end_time = start_time + duration;
    while(time(NULL) < end_time) {
        fputc(rand() % 2, fp);
    }

    fclose(fp);
    return 0;
}

int main() {
    char *filename = "output.txt";
    double duration = 3;
    return generate_code(filename, duration);
}
