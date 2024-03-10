#include <stddef.h>
#include <stdint.h>

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

typedef int16_t buffer_value_t;

typedef struct {
    buffer_value_t *values;
    size_t i_write;
    size_t i_read;
    size_t length;
    int diff;
} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t);

// wenn mna array hat, element mit arr[i] ausließt, bekommt man dann
// ptr oder value direkt?
int16_t write(circular_buffer_t *buffer, buffer_value_t tvalue);

int16_t read(circular_buffer_t *buffer, buffer_value_t *value);

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);

void clear_buffer(circular_buffer_t *buffer);

void delete_buffer(circular_buffer_t *buffer);

#endif
