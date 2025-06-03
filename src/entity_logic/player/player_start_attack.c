/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_start_attack
*/

#include "entity.h"

void player_start_attack(entity_t *player)
{
    player_data_t *data = player->data;

    if (data->is_anim_playing || data->current_weapon == WEAPON_NONE)
        return;
    if (data->attack_anim[data->current_weapon].sound) {
        sfSound_play(data->attack_anim[data->current_weapon].sound);
    }
    data->is_anim_playing = true;
    data->anim_state = ANIM_ATTACK;
    data->anim_timer = 0.0f;
}
