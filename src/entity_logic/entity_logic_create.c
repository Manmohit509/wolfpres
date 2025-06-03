/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic_create
*/

#include <math.h>
#include <stdlib.h>

#include "entity_logic.h"

entity_logic_t *entity_logic_create(void)
{
    entity_logic_t *logic = malloc(sizeof(entity_logic_t));

    if (!logic)
        return NULL;
    logic->constructors = hashmap_create(64);
    logic->destructors = hashmap_create(64);
    logic->head = NULL;
    if (!logic->constructors || !logic->destructors) {
        entity_logic_destroy(logic);
        return NULL;
    }
    return logic;
}
