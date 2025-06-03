/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_putstraray
*/

#include "my.h"

int my_putstrarray(char const *const *array, char const *separator)
{
    int count = 0;

    for (size_t i = 0; array[i] != NULL; i++) {
        count += my_putstr(array[i]);
        count += array[i + 1] == NULL ? 0 : my_putstr(separator);
    }
    return count;
}
