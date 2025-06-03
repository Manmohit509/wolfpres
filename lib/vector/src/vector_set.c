/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_set
*/

#include "vector.h"

int vector_set(void **vec, size_t index, void *value)
{
    const _vector_t *vector = *vec - sizeof(_vector_t);

    if (index >= vector->used_capacity) {
        return OUT_OF_BAND;
    }
    copy_n_bytes(*vec + vector->block_size * index, value, vector->block_size);
    return SUCCESS;
}
