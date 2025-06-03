/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** vector_erase
*/

#include <string.h>
#include <stddef.h>

#include "vector.h"

void vector_erase(void *vec, size_t const index)
{
    _vector_t *vector = ((_vector_t *) vec) - 1;
    char *char_vector = vec;

    if (index >= vector->used_capacity) {
        return;
    }
    if (vector->used_capacity > 1) {
        copy_n_bytes(
            char_vector + index * vector->block_size,
            char_vector + (index + 1) * vector->block_size,
            vector->block_size * (vector->used_capacity - index));
    }
    if (vector->used_capacity > 0) {
        vector->used_capacity--;
    }
}
