/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** asset_manager_load_textures_from_file
*/

#include <stdlib.h>
#include <string.h>

#include "asset_manager.h"
#include "utils.h"

static void handle_line(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path,
    char const *type)
{
    for (size_t i = 0; rules[i].type != NULL; i++) {
        if (strcmp(type, rules[i].type) == 0) {
            rules[i].parse(manager, file, asset_path);
            return;
        }
    }
    log_warn("Unknown asset type: %s\n", type);
}

int asset_manager_load_textures_from_file(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path)
{
    char type[32] = {0};

    if (!manager || !file)
        return EXIT_FAILURE;
    while (fscanf(file, "%31s", type) == 1) {
        handle_line(manager, file, asset_path, type);
    }
    return EXIT_SUCCESS;
}
