/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_resize
*/

#include <stdio.h>

#include "vector.h"

static void copy_content(
    void *src,
    void *dest,
    size_t src_size,
    size_t dest_size)
{
    copy_n_bytes(dest, src, V_MIN(dest_size, src_size));
}

int vector_resize(void **vec, const size_t new_size)
{
    _vector_t *vector = *vec;
    _vector_t *new_vector = NULL;

    vector--;
    if (vector->capacity == new_size) {
        return SUCCESS;
    }
    new_vector = vector_create(new_size, vector->block_size);
    if (new_vector == NULL) {
        return ALLOC_FAIL_ERR;
    }
    new_vector--;
    new_vector->used_capacity = vector->used_capacity;
    copy_content(vector + 1, new_vector + 1,
        vector->used_capacity * vector->block_size,
        new_vector->capacity * new_vector->block_size);
    vector_destroy(++vector, NULL);
    *vec = new_vector + 1;
    return SUCCESS;
}
