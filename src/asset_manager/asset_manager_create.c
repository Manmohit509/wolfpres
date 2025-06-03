/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** asset_manager_create
*/

#include <stdlib.h>

#include "asset_manager.h"

asset_manager_t *asset_manager_create(void)
{
    asset_manager_t *manager = malloc(sizeof(asset_manager_t));

    if (!manager)
        return NULL;
    manager->textures = hashmap_create(ASSET_MAPS_BUCKET_COUNT);
    manager->entities = hashmap_create(ASSET_MAPS_BUCKET_COUNT);
    manager->sounds = hashmap_create(ASSET_MAPS_BUCKET_COUNT);
    manager->shaders = hashmap_create(ASSET_MAPS_BUCKET_COUNT);
    manager->fonts = hashmap_create(ASSET_MAPS_BUCKET_COUNT);
    manager->musics = hashmap_create(ASSET_MAPS_BUCKET_COUNT);
    if (!manager->textures || !manager->entities || !manager->sounds ||
        !manager->shaders || !manager->fonts || !manager->musics) {
        asset_manager_destroy(manager);
        return NULL;
    }
    return manager;
}
