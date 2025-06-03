/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** logger_create_file
*/

#include <stdio.h>
#include <stddef.h>

#include "logger.h"

logger_t *logger_create_file(
    char const *filename,
    log_level_t level,
    char const *name)
{
    FILE *f = fopen(filename, "a");

    if (!f)
        return NULL;
    return logger_create(f, level, name);
}
