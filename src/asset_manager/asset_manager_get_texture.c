/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** asset_manager_get_texture
*/

#include "asset_manager.h"

texture_asset_t *asset_manager_get_texture(
    asset_manager_t *manager,
    const char *id)
{
    return (texture_asset_t *) hashmap_get(manager->textures, id);
}
