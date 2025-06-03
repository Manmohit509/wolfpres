/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_strcmp
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, size_t size)
{
    size_t i = 0;

    for (; i < size - 1 && s1[i] == s2[i] && s1[i] != '\0'; i++);
    return s1[i] - s2[i];
}
