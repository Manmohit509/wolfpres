/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_pop_back
*/

#include "vector.h"

int vector_pop_back(void *vec)
{
    _vector_t *vector = vec - sizeof(_vector_t);

    if (vector->used_capacity == 0) {
        return VECTOR_EMPTY_ERR;
    }
    clear_n_bytes(vec + vector->block_size * (vector->capacity - 1),
        vector->block_size);
    vector->used_capacity--;
    return SUCCESS;
}
