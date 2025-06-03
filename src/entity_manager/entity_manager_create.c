/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** entity_manager_create
*/

#include <stdlib.h>

#include "entity_manager.h"

entity_manager_t *entity_manager_create(void)
{
    entity_manager_t *manager = malloc(sizeof(*manager));

    if (!manager)
        return NULL;
    manager->head = NULL;
    manager->count = 0;
    return manager;
}
