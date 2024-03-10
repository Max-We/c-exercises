#include "circular_buffer.h"
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

circular_buffer_t *new_circular_buffer(size_t length) {
    if (!length || length==0) return NULL;

    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    buffer->i_write = 0;
    buffer->i_read = 0;
    buffer->length = length;
    buffer->diff = 0; // 0: empty; !0: has content
    buffer->values = malloc(sizeof(buffer_value_t) * length);

    return buffer;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
    if (!buffer) { errno = EINVAL; return EXIT_FAILURE;}
    if (buffer->diff != 0 && buffer->i_read == buffer->i_write) {errno=ENOBUFS; return EXIT_FAILURE;}
    
    buffer->values[buffer->i_write++] = value;
    buffer->i_write %= buffer->length;
    buffer->diff++;

    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
    if (!buffer) { errno = EINVAL; return EXIT_FAILURE;}
    if (buffer->diff == 0 && (buffer->i_read == buffer->i_write)) {errno=ENODATA; return EXIT_FAILURE;}

    *value = buffer->values[buffer->i_read++];
    buffer->i_read %= buffer->length;
    buffer->diff--;

    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
    if (!buffer) { errno = EINVAL; return EXIT_FAILURE;}

    buffer->values[buffer->i_write++] = value;
    buffer->i_write %= buffer->length;
    buffer->i_read = buffer->i_write;

    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer) {
    buffer->i_write = 0;
    buffer->i_read = 0;
    buffer->diff = 0;
}

void delete_buffer(circular_buffer_t *buffer) {
    free(buffer);
}
