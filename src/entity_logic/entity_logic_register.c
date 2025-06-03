/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic_register
*/

#include <stdlib.h>
#include <string.h>

#include "entity_logic.h"

void entity_logic_register(
    entity_logic_t *logic,
    const char *tag,
    void (*callback)(entity_t *, void *))
{
    logic_callback_t *new_cb = NULL;

    if (!logic || !tag || !callback)
        return;
    new_cb = malloc(sizeof(logic_callback_t));
    if (!new_cb)
        return;
    new_cb->tag = strdup(tag);
    new_cb->callback = callback;
    new_cb->next = logic->head;
    logic->head = new_cb;
}
