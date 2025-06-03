/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_create
*/

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"


void *vector_create(const size_t init_size, const size_t block_size)
{
    _vector_t *vector = NULL;

    if (block_size <= 0 || init_size <= 0) {
        return NULL;
    }
    vector = malloc(sizeof(_vector_t) + block_size * (init_size + 1));
    if (vector == NULL) {
        return NULL;
    }
    vector->capacity = init_size;
    vector->used_capacity = 0;
    vector->block_size = block_size;
    clear_n_bytes(vector + 1, block_size * (init_size + 1));
    return vector + 1;
}
