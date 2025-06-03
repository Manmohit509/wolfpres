/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** clear_n_bytes
*/

#include <stddef.h>

void copy_n_bytes(void *dest, const void *src, const size_t size)
{
    char *dest_str = dest;
    const char *src_str = src;

    for (size_t i = 0; i < size; i++) {
        dest_str[i] = src_str[i];
    }
}
