/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** logger_destroy
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "logger.h"

void logger_destroy(logger_t *logger)
{
    if (!logger)
        return;
    if (logger->output && logger->output != stderr)
        fclose(logger->output);
    if (logger->name)
        free(logger->name);
    free(logger);
}
