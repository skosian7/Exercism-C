 
#ifndef EXERCISM_C_CIRCULAR_BUFFER_H
#define EXERCISM_C_CIRCULAR_BUFFER_H
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

typedef int buffer_value_t;
typedef struct{
    buffer_value_t *buffer;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t elements_count;
}circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *buffer_to_delete);

int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
uint16_t read(circular_buffer_t *buffer, buffer_value_t *value);

void clear_buffer(circular_buffer_t *buffer);


#endif //EXERCISM_C_CIRCULAR_BUFFER_H