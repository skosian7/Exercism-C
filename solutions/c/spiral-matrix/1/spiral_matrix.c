#include "spiral_matrix.h"



spiral_matrix_t *spiral_matrix_create(int size) {

    //create spiral_matrix_t my_matrix and initialize its components

    spiral_matrix_t *my_matrix = malloc(sizeof(spiral_matrix_t));
    my_matrix->size = size;
    if (size <= 0) {
        my_matrix->matrix = NULL;
        return my_matrix;
    }
    my_matrix->matrix = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        my_matrix->matrix[i] = malloc(sizeof(int) * size);
    }

    int top = 0, bottom = size - 1, left = 0, right = size - 1, value = 1;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++) {
             my_matrix->matrix[top][i] = value++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            my_matrix->matrix[i][right] = value++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                my_matrix->matrix[bottom][i] = value++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i --) {
                my_matrix->matrix[i][left] = value++;
            }
            left++;
        }

    }

    return my_matrix;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}
