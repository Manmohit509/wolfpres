/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_getdouble
*/

double my_getdouble(char const *str)
{
    int sign_mul = 1;
    double nbr = 0;
    int after_part_i = 1;
    int ptr = 0;

    if (str[0] == '-') {
        ptr++;
        sign_mul = -1;
    }
    for (; str[ptr] >= '0' && str[ptr] <= '9'; ptr++) {
        nbr = nbr * 10 + str[ptr] - '0';
    }
    if (str[ptr] != '.') {
        return nbr == 0 && ptr == 0 ? -1 : nbr * sign_mul;
    }
    for (ptr++; str[ptr] >= '0' && str[ptr] <= '9'; ptr++) {
        after_part_i = 10;
        nbr += ((double) (str[ptr] - '0')) / after_part_i;
    }
    return nbr * sign_mul;
}
