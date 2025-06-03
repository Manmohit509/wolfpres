/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** destroy_level
*/

#include <stdlib.h>

#include "level.h"

void destroy_level(level_t *lvl, entity_logic_t *logic)
{
    if (!lvl)
        return;
    if (lvl->map)
        destroy_map(lvl->map);
    if (lvl->entities)
        entity_manager_destroy(lvl->entities, logic);
    free(lvl);
}
