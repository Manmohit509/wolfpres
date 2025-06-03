/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** asset_manager_get_shader
*/

#include "asset_manager.h"

shader_asset_t *asset_manager_get_shader(
    asset_manager_t *manager,
    const char *id)
{
    return (shader_asset_t *) hashmap_get(manager->shaders, id);
}
