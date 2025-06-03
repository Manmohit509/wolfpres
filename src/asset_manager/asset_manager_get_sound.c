/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** asset_manager_get_sound
*/

#include "asset_manager.h"

sound_asset_t *asset_manager_get_sound(
    asset_manager_t *manager,
    const char *id)
{
    return (sound_asset_t *) hashmap_get(manager->sounds, id);
}
