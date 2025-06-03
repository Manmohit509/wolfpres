/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** parse_font_line
*/

#include <stdlib.h>
#include <string.h>

#include "asset_manager.h"
#include "utils.h"

static void handle_font(sound_parse_data_t *data, asset_manager_t *manager)
{
    sfFont *font = sfFont_createFromFile(data->path);
    font_asset_t *asset = NULL;

    if (!font) {
        log_warn("Font loading failed: %s\n", data->path);
        return;
    }
    asset = malloc(sizeof(font_asset_t));
    if (!asset) {
        sfFont_destroy(font);
        return;
    }
    asset->id = strdup(data->id);
    asset->font = font;
    hashmap_insert(manager->fonts, asset->id, asset);
}

void parse_font_line(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path)
{
    char id[64] = {0};
    char path[256] = {0};
    char full[512] = {0};
    sound_parse_data_t d = {.id = id, .path = full};

    if (fscanf(file, "%63s %255s", id, path) != 2)
        return;
    snprintf(full, sizeof(full), "%s%s", asset_path, path);
    handle_font(&d, manager);
}
