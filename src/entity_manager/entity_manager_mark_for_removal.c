/*
** EPITECH PROJECT, 2025
** Gwolf
** File description:
** entity_manager_mark_for_removal
*/


#include <stdlib.h>

#include "entity_manager.h"

void entity_manager_mark_for_removal(
    entity_manager_t *manager,
    entity_t *target)
{
    for (entity_node_t *node = manager->head; node != NULL; node = node->next) {
        if (&node->entity == target) {
            node->marked_for_removal = true;
            return;
        }
    }
}
