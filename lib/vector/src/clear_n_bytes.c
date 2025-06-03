/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** clear_n_bytes
*/

#include <stddef.h>

void clear_n_bytes(void *ptr, const size_t size)
{
    char *char_ptr = ptr;

    for (size_t i = 0; i < size; i++) {
        char_ptr[i] = '\0';
    }
}
