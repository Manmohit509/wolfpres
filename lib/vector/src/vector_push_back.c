/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_push_back
*/

#include "vector.h"

void vector_push_back(void **vec, void *value_ptr)
{
    _vector_t *vector = *vec - sizeof(_vector_t);

    if (vector->used_capacity >= vector->capacity) {
        vector_resize(vec, vector->capacity * 2);
        vector = *vec - sizeof(_vector_t);
    }
    copy_n_bytes(((char *) *vec) + vector->used_capacity * vector->block_size,
        value_ptr, vector->block_size);
    vector->used_capacity++;
}
