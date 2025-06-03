/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** logger
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "logger.h"

void logger_log(logger_t *logger, log_level_t level, char const *fmt, ...)
{
    int colored = isatty(fileno(logger->output));
    va_list args = {0};

    if (!logger || level < logger->level)
        return;
    if (logger->name)
        fprintf(logger->output, "[%s] ", logger->name);
    if (colored)
        fprintf(logger->output, "%s", level_to_color(level));
    fprintf(logger->output, "[%s] ", level_to_string(level));
    if (colored)
        fprintf(logger->output, "\033[0m");
    va_start(args, fmt);
    vfprintf(logger->output, fmt, args);
    va_end(args);
    fprintf(logger->output, "\n");
    fflush(logger->output);
}

void logger_debug(logger_t *logger, char const *fmt, ...)
{
    va_list args = {0};

    if (!logger || LOG_LEVEL_DEBUG < logger->level)
        return;
    va_start(args, fmt);
    logger_vlog(logger, LOG_LEVEL_DEBUG, fmt, args);
    va_end(args);
}

void logger_info(logger_t *logger, char const *fmt, ...)
{
    va_list args = {0};

    if (!logger || LOG_LEVEL_INFO < logger->level)
        return;
    va_start(args, fmt);
    logger_vlog(logger, LOG_LEVEL_INFO, fmt, args);
    va_end(args);
}

void logger_warn(logger_t *logger, char const *fmt, ...)
{
    va_list args = {0};

    if (!logger || LOG_LEVEL_WARN < logger->level)
        return;
    va_start(args, fmt);
    logger_vlog(logger, LOG_LEVEL_WARN, fmt, args);
    va_end(args);
}

void logger_error(logger_t *logger, char const *fmt, ...)
{
    va_list args = {0};

    if (!logger || LOG_LEVEL_ERROR < logger->level)
        return;
    va_start(args, fmt);
    logger_vlog(logger, LOG_LEVEL_ERROR, fmt, args);
    va_end(args);
}
