/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_putnbr
*/

#include "my.h"

int my_putnbr(int nb)
{
    int remainder = 0;
    int quotient = 0;
    int char_count = 0;

    if (nb < 0) {
        char_count += my_putchar('-');
        nb = nb * -1;
    }
    remainder = nb % 10;
    quotient = (nb - remainder) / 10;
    if (quotient >= 1) {
        char_count += my_putnbr(quotient);
    }
    return char_count + my_putchar('0' + remainder);
}
