/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_strdup
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(char const *str)
{
    size_t size = my_strlen(str);
    char *cpy = malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; i++) {
        cpy[i] = str[i];
    }
    cpy[size] = '\0';
    return cpy;
}
