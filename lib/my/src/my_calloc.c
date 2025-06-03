/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_calloc
*/

#include <stdlib.h>

void *my_calloc(const size_t size)
{
    char *ptr = NULL;

    if (size == 0) {
        return NULL;
    }
    ptr = malloc(size);
    for (size_t i = 0; i < size; i++) {
        ptr[i] = '\0';
    }
    return ptr;
}
