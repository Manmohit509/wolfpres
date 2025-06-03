/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic_register_tag
*/

#include "entity_logic.h"

void entity_logic_register_tag(
    entity_logic_t *logic,
    const char *tag,
    void *(*constructor)(void *),
    void (*destructor)(void *))
{
    if (constructor)
        hashmap_insert(logic->constructors, tag, constructor);
    if (destructor)
        hashmap_insert(logic->destructors, tag, destructor);
}
