/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H

    #define UNUSED __attribute__((unused))

    #define SUCCESS 0
    #define FAILURE 84

    #include <stdbool.h>
    #include <stddef.h>

int my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int nb);
bool my_has_char(char const *str, char c);

double my_getdouble(char const *str);

char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t size);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
size_t my_strlen(char const *str);
char **my_str_split(char const *str, char const *delimiters);

char **my_strarraycpy(char const *const *array);
int my_putstrarray(char const *const *array, char const *separator);
char **my_str_split(char const *str, char const *delimiters);

void free_array(void **array, void (*free_method)(void *));

int my_bwrite(int fd, char const *str);
int my_strarraylen(char const *const *array);
void *my_calloc(size_t size);

#endif /* INCLUDED_MY_H */
