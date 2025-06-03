/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic_construct_data
*/

#include "entity_logic.h"

void *entity_logic_construct_data(
    entity_logic_t *logic,
    const char *tag,
    void *data)
{
    void *(*ctor)(void *) = hashmap_get(logic->constructors, tag);

    return ctor ? ctor(data) : NULL;
}
