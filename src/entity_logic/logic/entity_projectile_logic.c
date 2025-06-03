/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_projectile_logic
*/

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "attack.h"
#include "process.h"
#include "utils.h"
#include "wolf3d.h"

static bool collides_with_entity(entity_t *proj, entity_t *target)
{
    float dx = proj->pos.x - target->pos.x;
    float dy = proj->pos.y - target->pos.y;
    float dist = sqrtf(dx * dx + dy * dy);

    if (!target->is_active || target == proj)
        return false;
    if (strcmp(target->tag, "player") == 0 ||
        strcmp(target->tag, "projectile") == 0)
        return false;
    return dist < PROJECTILE_RADIUS;
}

static bool collides_with_wall(game_map_t *map, sfVector2f pos)
{
    int x = (int)(pos.x);
    int y = (int)(pos.y);

    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        return true;
    return map->tiles[y][x] != 0;
}

void *projectile_data_constructor(UNUSED void *ptr)
{
    projectile_data_t *data = calloc(1,
        sizeof(projectile_data_t));

    if (!data) {
        return NULL;
    }
    return data;
}

void projectile_data_destructor(void *ptr)
{
    projectile_data_t *data = ptr;

    if (data == NULL) {
        return;
    }
    free(data);
}

static void handle_collision(
    entity_node_t *node,
    entity_t *proj,
    process_t *process,
    game_map_t *map)
{
    entity_t *target = NULL;

    if (collides_with_wall(map, proj->pos)) {
        entity_manager_mark_for_removal(process->level->entities, proj);
        return;
    }
    while (node) {
        target = &node->entity;
        if (target != proj && collides_with_entity(proj, target)) {
            target->health -= PROJECTILE_DAMAGE;
            entity_manager_mark_for_removal(process->level->entities, proj);
            return;
        }
        node = node->next;
    }
}

static void compute_rotation(
    entity_t *proj,
    projectile_data_t *d,
    process_t *process)
{
    proj->pos.x += proj->direction.x * proj->speed * process->clock.delta_t;
    proj->pos.y += proj->direction.y * proj->speed * process->clock.delta_t;
    d->rotation += 1 * process->clock.delta_t;
    if (d->rotation >= 1)
        d->rotation -= 1;
}

void entity_projectile_logic(entity_t *proj, void *data)
{
    process_t *process = data;
    game_map_t *map = NULL;
    projectile_data_t *d = NULL;

    if (!process)
        return;
    map = process->level->map;
    if (!proj->data || !proj->is_active)
        return;
    d = proj->data;
    compute_rotation(proj, d, process);
    proj->sprite_state = ((int) roundf(d->rotation * PROJ_ROT_SPEED)) % 8;
    handle_collision(process->level->entities->head, proj,
        process, map);
}
