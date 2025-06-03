/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** create_entity_from_line
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "entity_manager.h"
#include "entity_logic.h"

static entity_type_t get_type(char const *type_str)
{
    if (strcmp(type_str, "player") == 0)
        return ENTITY_PLAYER;
    if (strcmp(type_str, "enemy") == 0)
        return ENTITY_ENEMY;
    if (strcmp(type_str, "object") == 0)
        return ENTITY_OBJECT;
    if (strcmp(type_str, "projectile") == 0)
        return ENTITY_PROJECTILE;
    return ENTITY_UNKNOWN;
}

entity_t create_entity_from_line(
    const char *line,
    entity_logic_t *logic,
    void *data)
{
    char type_str[32] = {0};
    float x = 0;
    float y = 0;
    float angle = 0;
    int parsed = sscanf(line, "%31s %f %f %f", type_str, &x, &y, &angle);
    entity_type_t type = parsed < 3 ? ENTITY_UNKNOWN : get_type(type_str);
    float rad = angle * (M_PI / 180.0f);
    sfVector2f dir = {cosf(rad), sinf(rad)};
    entity_t entity = {0};

    if (parsed < 4)
        return (entity_t){0};
    entity = (entity_t) {
        .type = type, .pos = {x, y},
        .direction = dir, .speed = 0.0f, .angle_deg = angle,
        .health = 100, .is_active = 1,
        .tag = strdup(type_str), .data = NULL
    };
    entity.data = entity_logic_construct_data(logic, type_str, data);
    return entity;
}
