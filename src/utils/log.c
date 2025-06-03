/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** log
*/

#include <stdio.h>
#include <stdarg.h>

#include "utils.h"


static void log_base(
    const char *level,
    const char *color,
    const char *fmt,
    va_list args)
{
    fprintf(stderr, "%s[%s] ", color, level);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "%s\n", COLOR_RESET);
}

void log_info(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    log_base("INFO", COLOR_GREEN, fmt, args);
    va_end(args);
}

void log_debug(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    log_base("DEBUG", COLOR_GREEN, fmt, args);
    va_end(args);
}

void log_warn(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    log_base("WARN", COLOR_YELLOW, fmt, args);
    va_end(args);
}

void log_error(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    log_base("ERROR", COLOR_RED, fmt, args);
    va_end(args);
}
