/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_size
*/

#include "vector.h"

size_t vector_size(void const *vec)
{
    const _vector_t *vector = vec;

    vector--;
    return vector->used_capacity;
}
