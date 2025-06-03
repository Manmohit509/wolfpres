/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_bwrite
*/

#include <unistd.h>

#include "my.h"

int my_bwrite(int fd, char const *str)
{
    return write(fd, str, my_strlen(str));
}
