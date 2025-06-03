/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** parse_music_line
*/

#include <stdlib.h>
#include <string.h>

#include "asset_manager.h"
#include "utils.h"

static void handle_music(sound_parse_data_t *data, asset_manager_t *manager)
{
    sfMusic *music = sfMusic_createFromFile(data->path);
    music_asset_t *asset = NULL;

    if (!music) {
        log_warn("Music loading failed: %s\n", data->path);
        return;
    }
    asset = malloc(sizeof(sound_asset_t));
    if (!asset)
        return;
    asset->id = strdup(data->id);
    asset->music = music;
    hashmap_insert(manager->musics, asset->id, asset);
}

void parse_music_line(
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
    handle_music(&d, manager);
}
