/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic_destroy_data
*/

#include <stdlib.h>

#include "entity_logic.h"

void entity_logic_destroy_data(entity_logic_t *logic, entity_t *entity)
{
    void (*dtor)(void *) = NULL;

    if (!entity || !entity->data) {
        return;
    }
    dtor = hashmap_get(logic->destructors, entity->tag);
    if (dtor) {
        dtor(entity->data);
        entity->data = NULL;
    }
}
