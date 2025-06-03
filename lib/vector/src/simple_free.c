/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** simple_free
*/

#include <stdlib.h>

void simple_free(void *ptr)
{
    void **real_ptr = ptr;

    free(*real_ptr);
}
