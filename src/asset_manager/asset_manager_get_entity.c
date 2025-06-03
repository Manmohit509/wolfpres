/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** asset_manager_get_entity
*/

#include "asset_manager.h"

entity_asset_t *asset_manager_get_entity(
    asset_manager_t *manager,
    const char *id)
{
    return (entity_asset_t *) hashmap_get(manager->entities, id);
}
