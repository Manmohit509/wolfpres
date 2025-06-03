/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** parse_entity_line
*/

#include <stdlib.h>
#include <string.h>

#include "asset_manager.h"
#include "utils.h"

static void handle_entity(
    entity_parse_data_t *data,
    asset_manager_t *manager)
{
    sfTexture *texture = sfTexture_createFromFile(data->path, NULL);
    entity_asset_t *asset = NULL;

    if (!texture) {
        log_warn("Entity texture loading failed: %s\n", data->path);
        return;
    }
    asset = malloc(sizeof(entity_asset_t));
    if (!asset)
        return;
    asset->id = strdup(data->id);
    asset->texture = texture;
    asset->face_count = data->face_count;
    asset->state_count = data->state_count;
    asset->height = data->height;
    asset->width = data->width;
    hashmap_insert(manager->entities, asset->id, asset);
}

void parse_entity_line(
    asset_manager_t *manager,
    FILE *file,
    char const *asset_path)
{
    char id[64] = {0};
    char path[256] = {0};
    char full[512] = {0};
    entity_parse_data_t d = {.id = id, .path = full};

    if (fscanf(file, "%63s %255s %d %d %d %d",
        id, path, &d.width, &d.height, &d.face_count, &d.state_count) != 6)
        return;
    snprintf(full, sizeof(full), "%s%s", asset_path, path);
    handle_entity(&d, manager);
}
