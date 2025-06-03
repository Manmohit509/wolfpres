/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** parse_sound_line
*/

#include <stdlib.h>
#include <string.h>

#include "asset_manager.h"
#include "utils.h"

static void handle_sound(sound_parse_data_t *data, asset_manager_t *manager)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(data->path);
    sound_asset_t *asset = NULL;

    if (!buffer) {
        log_warn("Sound loading failed: %s\n", data->path);
        return;
    }
    asset = malloc(sizeof(sound_asset_t));
    if (!asset)
        return;
    asset->id = strdup(data->id);
    asset->buffer = buffer;
    hashmap_insert(manager->sounds, asset->id, asset);
}

void parse_sound_line(
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
    handle_sound(&d, manager);
}
