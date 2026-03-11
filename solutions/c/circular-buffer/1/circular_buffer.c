 #include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity) {
    circular_buffer_t *circular_buffer = malloc(sizeof(circular_buffer_t));
    if (circular_buffer == NULL) {
        return NULL;
    }
    circular_buffer->buffer = malloc(sizeof(buffer_value_t) * capacity);
    if (circular_buffer->buffer == NULL) {
        free(circular_buffer);
        return NULL;
    }

    circular_buffer->capacity = capacity;
    circular_buffer->head = 0;
    circular_buffer->tail = 0;
    circular_buffer->elements_count = 0;

    return circular_buffer;
}

void delete_buffer(circular_buffer_t *buffer_to_delete) {
    if (buffer_to_delete == NULL) {
        return;
    }

    free(buffer_to_delete->buffer);
    free(buffer_to_delete);
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
    if (buffer == NULL) {return EXIT_FAILURE;}

    if (buffer->elements_count == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;;
    }

    buffer->buffer[buffer->head] = value;
    //update the head
    buffer->head = (buffer->head + 1) % buffer->capacity;
    //update the elements count
    buffer->elements_count++;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
    if (buffer == NULL) {return EXIT_FAILURE;}

    if (buffer->elements_count == buffer->capacity) {
        buffer->tail = (buffer->tail + 1) % buffer->capacity;
        buffer->elements_count--;
    }
    buffer->buffer[buffer->head] = value;
    //update the head
    if (buffer->head == buffer->capacity - 1) {
        buffer->head = 0;
    }else {
        buffer->head++;
    }
    //update the elements count
    buffer->elements_count++;
    return EXIT_SUCCESS;
}

uint16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
    if (buffer == NULL) {
        return EXIT_FAILURE;
    }

    if (buffer->elements_count == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    *value = buffer->buffer[buffer->tail];
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    buffer->elements_count--;
    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer) {
    if (buffer == NULL || buffer->elements_count==0) {return;}
    buffer->elements_count --;
    if (buffer->head == 0) {
        buffer->head = buffer->capacity - 1;
    }else {
        buffer->head--;
    }
}