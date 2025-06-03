/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** entity_manager_for_each
*/

#include "entity_manager.h"

void entity_manager_for_each(
    entity_manager_t *manager,
    void (*callback)(entity_t *, void *),
    void *userdata)
{
    entity_node_t *node = manager->head;

    while (node) {
        callback(&node->entity, userdata);
        node = node->next;
    }
}
