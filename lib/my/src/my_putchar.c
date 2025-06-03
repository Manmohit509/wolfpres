/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}
