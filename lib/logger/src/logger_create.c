/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** logger_create
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

logger_t *logger_create(FILE *output, log_level_t level, char const *name)
{
    logger_t *logger = malloc(sizeof(logger_t));

    if (!logger)
        return NULL;
    logger->output = output ? output : stderr;
    logger->level = level;
    if (name) {
        logger->name = strdup(name);
    }
    return logger;
}
