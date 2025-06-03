/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic_apply
*/

#include <string.h>

#include "entity_logic.h"

static void handle_cb(
    entity_node_t *node,
    entity_logic_t *logic,
    void *userdata)
{
    logic_callback_t *cb = NULL;

    for (cb = logic->head; cb != NULL; cb = cb->next) {
        if (node->entity.tag && strcmp(node->entity.tag, cb->tag) == 0) {
            cb->callback(&node->entity, userdata);
        }
    }
}

static void handle(
    entity_logic_t *logic,
    entity_node_t *node,
    void *userdata)
{
    while (node != NULL) {
        entity_node_t *next = node->next;
        handle_cb(node, logic, userdata);
        node = next;
    }
}

void entity_logic_apply(
    entity_logic_t *logic,
    entity_manager_t *manager,
    void *userdata)
{
    if (!logic || !manager)
        return;
    handle(logic, manager->head, userdata);
}
