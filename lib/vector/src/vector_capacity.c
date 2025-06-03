/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_capacity
*/

#include "vector.h"

size_t vector_capacity(void *vec)
{
    const _vector_t *vector = vec - sizeof(_vector_t);

    return vector->capacity;
}
