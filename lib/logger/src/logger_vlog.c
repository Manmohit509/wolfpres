/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** logger_vlog
*/

#include <stdio.h>
#include <unistd.h>

#include "logger.h"

void logger_vlog(
    logger_t *logger,
    log_level_t level,
    char const *fmt, va_list args)
{
    int colored = isatty(fileno(logger->output));

    if (!logger || level < logger->level)
        return;
    if (logger->name)
        fprintf(logger->output, "[%s] ", logger->name);
    if (colored)
        fprintf(logger->output, "%s", level_to_color(level));
    fprintf(logger->output, "[%s] ", level_to_string(level));
    if (colored)
        fprintf(logger->output, "\033[0m");
    vfprintf(logger->output, fmt, args);
    fprintf(logger->output, "\n");
    fflush(logger->output);
}
