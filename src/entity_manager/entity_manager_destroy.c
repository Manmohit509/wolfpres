/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** entity_manager_destroy
*/

#include <stdlib.h>

#include "entity_manager.h"

void entity_manager_destroy(
    entity_manager_t *manager,
    entity_logic_t *logic)
{
    entity_node_t *node = manager->head;
    entity_node_t *next = NULL;

    while (node) {
        next = node->next;
        entity_logic_destroy_data(logic, &node->entity);
        free(node->entity.tag);
        free(node);
        node = next;
    }
    free(manager);
}
