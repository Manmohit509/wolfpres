/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** asset_manager_get_font
*/

#include "asset_manager.h"

font_asset_t *asset_manager_get_font(
    asset_manager_t *manager,
    const char *id)
{
    return (font_asset_t *) hashmap_get(manager->fonts, id);
}
