/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** update_sound_listener
*/

#include "entity.h"

void update_sound_listener(entity_t *entity)
{
    sfListener_setPosition(
        (sfVector3f) {entity->pos.x, 0.0f, entity->pos.y});
    sfListener_setDirection(
        (sfVector3f) {entity->direction.x, 0.0f, entity->direction.y});
}
