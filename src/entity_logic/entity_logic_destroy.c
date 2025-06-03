/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic_destroy
*/

#include <stdlib.h>

#include "entity_logic.h"

void entity_logic_destroy(entity_logic_t *logic)
{
    logic_callback_t *curr = NULL;
    logic_callback_t *next = NULL;

    if (!logic)
        return;
    curr = logic->head;
    while (curr) {
        next = curr->next;
        if (curr->tag)
            free(curr->tag);
        free(curr);
        curr = next;
    }
    if (logic->constructors) {
        hashmap_destroy(logic->constructors, NULL);
    }
    if (logic->destructors) {
        hashmap_destroy(logic->destructors, NULL);
    }
    free(logic);
}
