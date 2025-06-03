/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** entity_manager_add
*/

#include <stdlib.h>

#include "entity_manager.h"
#include "entity_logic.h"

entity_t *entity_manager_add(
    entity_manager_t *manager,
    entity_t entity,
    entity_logic_t *logic,
    void *data)
{
    entity_node_t *node = NULL;

    if (!manager)
        return NULL;
    node = calloc(1,sizeof(entity_node_t));
    if (!node)
        return NULL;
    node->entity = entity;
    if (!node->entity.data)
        node->entity.data = entity_logic_construct_data(logic, entity.tag, data);
    node->next = manager->head;
    manager->head = node;
    manager->count++;
    return &node->entity;
}
