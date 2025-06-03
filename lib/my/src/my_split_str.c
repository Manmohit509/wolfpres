/*
** EPITECH PROJECT, 2024
** myradar
** File description:
** split_str.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "my.h"

static int get_item_count(char const *str, char const *delimiters)
{
    bool previous_was_delim = true;
    bool is_delim = false;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        is_delim = my_has_char(delimiters, str[i]);
        if (previous_was_delim && !is_delim) {
            count++;
        }
        previous_was_delim = is_delim;
    }
    return count;
}

static int get_word_size(
    char const *str,
    char const *delimiters,
    const int *cur_i)
{
    int word_size = 0;

    for (int i = *cur_i; !my_has_char(delimiters, str[i]); i++) {
        word_size++;
    }
    return word_size;
}

static char *get_next_word(char const *str, char const *delimiters, int *cur_i)
{
    int const word_size = get_word_size(str, delimiters, cur_i);
    char *word = NULL;

    if (word_size == 0) {
        *cur_i = *cur_i + 1;
        return NULL;
    }
    word = malloc(sizeof(char) * (word_size + 1));
    if (word == NULL) {
        return NULL;
    }
    for (int i = 0; i < word_size; i++) {
        word[i] = str[*cur_i];
        *cur_i = *cur_i + 1;
    }
    word[word_size] = '\0';
    return word;
}

char **my_str_split(char const *str, char const *delimiters)
{
    char **word_array = NULL;
    int const str_size = my_strlen(str);
    int word_count = 0;
    int cur_i = 0;
    int cur_word_i = 0;

    if (str == NULL || delimiters == NULL)
        return NULL;
    word_count = get_item_count(str, delimiters);
    word_array = malloc(sizeof(char *) * (word_count + 1));
    if (word_array == NULL)
        return NULL;
    while (cur_word_i < word_count && str_size > cur_i) {
        word_array[cur_word_i] = get_next_word(str, delimiters, &cur_i);
        if (word_array[cur_word_i] == NULL)
            continue;
        cur_word_i++;
    }
    word_array[cur_word_i] = NULL;
    return word_array;
}
