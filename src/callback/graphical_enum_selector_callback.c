/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** graphical_enum_selector_callback
*/

#include <string.h>

#include "process.h"

static quality_t get_quality_from_str(char const *str)
{
    if (strcmp(str, "low") == 0) {
        return LOW;
    }
    if (strcmp(str, "medium") == 0) {
        return MEDIUM;
    }
    if (strcmp(str, "high") == 0) {
        return HIGH;
    }
    return MEDIUM;
}

void graphical_enum_selector_callback(
    const char *value,
    int index,
    void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->app) {
        return;
    }
    process->settings.render_quality = get_quality_from_str(value);
    logger_info(process->logger, "Enum changed to: %s (index %d)",
        value, index);
}
