/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** parse_texture_line
*/

#include <stdlib.h>
#include <string.h>

#include "asset_manager.h"
#include "utils.h"

static void handle_texture(
    texture_parse_data_t *data,
    asset_manager_t *manager)
{
    sfTexture *texture = sfTexture_createFromFile(data->path, NULL);
    texture_asset_t *asset = NULL;

    if (!texture) {
        log_warn("Texture loading failed: %s\n", data->path);
        return;
    }
    asset = malloc(sizeof(texture_asset_t));
    if (!asset)
        return;
    asset->id = strdup(data->id);
    asset->texture = texture;
    hashmap_insert(manager->textures, asset->id, asset);
}

void parse_texture_line(
    asset_manager_t *manager,
    FILE *file,
    char const *asset_path)
{
    char id[64] = {0};
    char path[256] = {0};
    char full[512] = {0};
    texture_parse_data_t data = {.id = id, .path = full};

    if (fscanf(file, "%63s %255s", id, path) != 2)
        return;
    snprintf(full, sizeof(full), "%s%s", asset_path, path);
    handle_texture(&data, manager);
}
