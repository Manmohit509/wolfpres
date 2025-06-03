/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_handle_attack
*/

#include <math.h>
#include <string.h>

#include "process.h"
#include "attack.h"

static bool is_in_melee_range(entity_t *a, entity_t *b)
{
    float dx = b->pos.x - a->pos.x;
    float dy = b->pos.y - a->pos.y;
    float dist = sqrt(dx * dx + dy * dy);

    return dist <= MELEE_RANGE;
}

static bool is_in_front(entity_t *player, entity_t *target)
{
    sfVector2f to_target = {
        target->pos.x - player->pos.x,
        target->pos.y - player->pos.y
    };
    float dot = player->direction.x * to_target.x +
        player->direction.y * to_target.y;

    return dot > 0;
}

static void handle_melee(process_t *process, entity_t *player)
{
    entity_node_t *node = process->level->entities->head;
    entity_t *e = NULL;

    while (node) {
        e = &node->entity;
        if (e != player && e->is_active &&
            strcmp(e->tag, "player") != 0 &&
            is_in_melee_range(player, e) &&
            is_in_front(player, e)) {
            e->health -= MELEE_DAMAGE;
            return;
        }
        node = node->next;
    }
}

static void handle_projectile(process_t *process, entity_t *player)
{
    entity_t proj = {
        .pos = player->pos,
        .direction = player->direction,
        .speed = PROJECTILE_SPEED,
        .angle_deg = player->angle_deg,
        .health = 1,
        .is_active = true,
        .tag = strdup(PROJECTILE_TAG),
        .data = NULL
    };

    entity_manager_add(process->level->entities, proj, process->entity_logic,
        process);
}

void player_handle_attack(process_t *process, entity_t *player)
{
    player_data_t const *data = NULL;

    if (!player || !player->data || !process || !process->level)
        return;
    data = player->data;
    if (data->current_weapon == WEAPON_MELEE)
        handle_melee(process, player);
    if (data->current_weapon == WEAPON_RANGED)
        handle_projectile(process, player);
}
