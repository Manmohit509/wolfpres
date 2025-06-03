/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_destroy
*/

#include <stdlib.h>

#include "vector.h"

void vector_destroy(void *vec, void (*free_method)(void *data_ptr))
{
    _vector_t *vector = vec;
    char *char_vector = vec;
    const size_t vec_size = vector_size(vec);

    vector = vector - 1;
    if (free_method != NULL) {
        for (size_t i = 0; i < vec_size; i++) {
            free_method(char_vector + vector->block_size * i);
        }
    }
    free(vector);
}
