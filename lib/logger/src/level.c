/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** level
*/

#include "logger.h"

char const *level_to_color(log_level_t level)
{
    switch (level) {
        case LOG_LEVEL_DEBUG:
            return "\033[34m";
        case LOG_LEVEL_INFO:
            return "\033[32m";
        case LOG_LEVEL_WARN:
            return "\033[33m";
        case LOG_LEVEL_ERROR:
            return "\033[31m";
        default:
            return "\033[0m";
    }
}

char const *level_to_string(log_level_t level)
{
    switch (level) {
        case LOG_LEVEL_DEBUG:
            return "DEBUG";
        case LOG_LEVEL_INFO:
            return "INFO";
        case LOG_LEVEL_WARN:
            return "WARN";
        case LOG_LEVEL_ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}
