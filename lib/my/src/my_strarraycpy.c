/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_strarraycpy
*/

#include <stdlib.h>

#include "my.h"

char **my_strarraycpy(char const *const *array)
{
    size_t size = 0;
    char **new_array = NULL;

    while (array[size]) {
        size++;
    }
    new_array = malloc(sizeof(char *) * (size + 1));
    for (size_t i = 0; i < size; i++) {
        new_array[i] = my_strdup(array[i]);
        if (new_array[i] == NULL) {
            free_array((void **) new_array, &free);
            return NULL;
        }
    }
    new_array[size] = NULL;
    return new_array;
}
