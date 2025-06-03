/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** vector_is_empty
*/

#include "vector.h"

bool vector_is_empty(void *vec)
{
    return vector_size(vec) == 0;
}
