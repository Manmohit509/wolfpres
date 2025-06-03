/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_clear
*/

#include "vector.h"

void vector_clear(void *vec)
{
    _vector_t *vector = vec - sizeof(_vector_t);

    clear_n_bytes(vec, vector->capacity * vector->block_size);
    vector->used_capacity = 0;
}
