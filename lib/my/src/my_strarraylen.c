/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strarraylen
*/

#include <stddef.h>

int my_strarraylen(char const *const *array)
{
    int i = 0;

    while (array[i]) {
        i++;
    }
    return i;
}
