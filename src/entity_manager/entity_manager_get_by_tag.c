/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** entity_manager_get_by_tag
*/

#include <string.h>

#include "entity_manager.h"

entity_t *entity_manager_get_by_tag(entity_manager_t *manager, const char *tag)
{
    entity_node_t *node = manager->head;

    while (node) {
        if (node->entity.tag && strcmp(node->entity.tag, tag) == 0)
            return &node->entity;
        node = node->next;
    }
    return NULL;
}
