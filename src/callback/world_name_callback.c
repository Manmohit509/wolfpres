/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** world_name_callback
*/

#include <stdlib.h>
#include <string.h>

#include "process.h"

static bool load_level(process_t *process, char const *save_name)
{
    char buffer[256] = {0};
    FILE *file = NULL;

    strcpy(buffer, "./worlds/");
    strcat(buffer, save_name);
    strcat(buffer, ".world");
    file = fopen(buffer, "r");
    if (!file) {
        return false;
    }
    if (process->level) {
        destroy_level(process->level, process->entity_logic);
    }
    process->level = load_level_from_file(file, process);
    fclose(file);
    if (!process->level) {
        logger_error(process->logger,
            "Impossible to load the world '%s'", buffer);
    }
    return process->level;
}

void world_name_callback(const char *text, void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->app)
        return;
    if (!load_level(process, text)) {
        return;
    }
    ui_app_set_active_page(process->app, "in_game");
}
