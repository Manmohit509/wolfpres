/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** logger
*/

#ifndef LOGGER_H
    #define LOGGER_H

    #include <stdio.h>

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_NONE
} log_level_t;

typedef struct logger_s {
    FILE *output;
    log_level_t level;
    char *name;
} logger_t;

// creation and destruction
logger_t *logger_create(FILE *output, log_level_t level, char const *name);
logger_t *logger_create_file(
    char const *filename,
    log_level_t level,
    char const *name);
void logger_destroy(logger_t *logger);

void logger_vlog(
    logger_t *logger,
    log_level_t level,
    char const *fmt, va_list args);

// log methods
void logger_log(logger_t *logger, log_level_t level, char const *fmt, ...);
void logger_debug(logger_t *logger, char const *fmt, ...);
void logger_info(logger_t *logger, char const *fmt, ...);
void logger_warn(logger_t *logger, char const *fmt, ...);
void logger_error(logger_t *logger, char const *fmt, ...);

char const *level_to_color(log_level_t level);
char const *level_to_string(log_level_t level);

#endif /* LOGGER_H */
