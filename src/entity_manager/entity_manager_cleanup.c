/*
** EPITECH PROJECT, 2025
** Gwolf
** File description:
** entity_manager_cleanup
*/

#include <stdlib.h>

#include "entity_manager.h"

static bool safe_remove(
    entity_node_t *prev,
    entity_node_t *curr,
    entity_manager_t *manager,
    entity_logic_t *logic)
{
    if (prev)
        prev->next = curr->next;
    else
        manager->head = curr->next;
    entity_logic_destroy_data(logic, &curr->entity);
    free(curr->entity.tag);
    free(curr);
    manager->count--;
    return true;
}

void entity_manager_cleanup(entity_manager_t *manager, entity_logic_t *logic)
{
    entity_node_t *prev = NULL;
    entity_node_t *curr = manager->head;

    while (curr != NULL) {
        entity_node_t *next = curr->next;

        if (curr->marked_for_removal) {
            safe_remove(prev, curr, manager, logic);
        } else {
            prev = curr;
        }

        curr = next;
    }
}
