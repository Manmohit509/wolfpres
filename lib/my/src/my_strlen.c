/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_strlen
*/

#include <stddef.h>

size_t my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL) {
        return 0;
    }
    for (; str[i] != '\0'; i++);
    return i;
}
