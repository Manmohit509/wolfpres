/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_set_weapon
*/

#include "entity.h"

void player_set_weapon(entity_t *player, weapon_type_t new_weapon)
{
    player_data_t *data = player->data;

    if (data->current_weapon == new_weapon || data->is_anim_playing)
        return;
    data->current_weapon = new_weapon;
    data->is_anim_playing = new_weapon != WEAPON_NONE;
    data->anim_state = ANIM_INSPECT;
    data->anim_timer = 0.0f;
    if (data->inspect_anim[data->current_weapon].sound) {
        sfSound_play(data->inspect_anim[data->current_weapon].sound);
    }
}
