/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** entity_manager_print
*/

#include <stdio.h>

#include "entity_manager.h"

void entity_manager_print(const entity_manager_t *manager)
{
    entity_node_t const *node = NULL;
    entity_t const *e = NULL;

    if (!manager)
        return;
    node = manager->head;
    while (node) {
        e = &node->entity;
        printf("Entity [%s] @ (%.2f, %.2f),"
            " angle: %.1f°, active: %d, HP: %d\n",
            e->tag ? e->tag : "null",
            e->pos.x, e->pos.y,
            e->angle_deg,
            e->is_active,
            e->health);
        node = node->next;
    }
}
