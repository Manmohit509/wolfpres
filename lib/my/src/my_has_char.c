/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_has_char
*/

#include <stdio.h>
#include <stdbool.h>

bool my_has_char(char const *str, char const c)
{
    if (c == '\0') {
        return true;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}
