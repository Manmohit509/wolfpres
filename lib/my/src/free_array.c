/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** free_array
*/

#include <stdlib.h>

void free_array(void **array, void (*free_method)(void *))
{
    if (free_method != NULL) {
        for (size_t i = 0; array[i] != NULL; i++) {
            free_method(array[i]);
        }
    }
    free(array);
}
