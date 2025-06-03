/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_update_interaction
*/

#include <string.h>

#include "player.h"
#include "process.h"
#include "utils.h"

static void handle_update(
    entity_t *entity,
    void *ptr)
{
    struct inter_param_s *param = ptr;

    if (compute_distance(param->pos, entity->pos) > 1 &&
        strcmp(entity->tag, "joffreystein")) {
        param->player_data->stress += 1;
    }
    if (compute_distance(param->pos, entity->pos) > 0.5) {
        return;
    }
    if (strcmp(entity->tag, "computer") == 0) {
        param->player_data->interaction_type = INTERACTION_COMPUTER;
    } else if (strcmp(entity->tag, "hoppy") == 0) {
        param->player_data->interaction_type = INTERACTION_HOPPY;
    }
}

void player_update_interaction(
    process_t *process,
    sfVector2f pos,
    player_data_t *player_data)
{
    struct inter_param_s param = {
        .pos = pos,
        .player_data = player_data
    };

    player_data->interaction_type = INTERACTION_NONE;
    entity_manager_for_each(process->level->entities, handle_update, &param);
}
