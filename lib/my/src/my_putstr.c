/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_putstr
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return write(1, str, i);
}
