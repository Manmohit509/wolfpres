/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** asset_manager_get_music
*/

#include "asset_manager.h"

music_asset_t *asset_manager_get_music(
    asset_manager_t *manager,
    const char *id)
{
    return (music_asset_t *) hashmap_get(manager->musics, id);
}
