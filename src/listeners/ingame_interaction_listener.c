/*
** EPITECH PROJECT, 2025
** Gwolf
** File description:
** ingame_interaction_listener
*/

#include <string.h>

#include "listeners.h"

void ingame_interaction_listener(sfEvent *event, process_t *process)
{
    entity_t *e = NULL;
    player_data_t *data = NULL;

    if (event->type != sfEvtKeyPressed)
        return;
    if (!process->app || !ui_app_get_current_page_name(process->app))
        return;
    if (strcmp(ui_app_get_current_page_name(process->app), "in_game") != 0)
        return;
    e = entity_manager_get_by_tag(
        process->level->entities, "player");
    if (!e || !e->data)
        return;
    data = e->data;
    if (event->key.code == sfKeyF && event->type == sfEvtKeyPressed) {
        data->has_flashlight = !data->has_flashlight;
    }
    if (event->key.code == sfKeyNum1 && event->key.code != sfKeyEscape)
        player_set_weapon(e, WEAPON_MELEE);
    if (event->key.code == sfKeyNum2)
        player_set_weapon(e, WEAPON_RANGED);
    if (event->key.code == sfKeyNum3)
        player_set_weapon(e, WEAPON_NONE);
    if (event->key.code == sfKeySpace)
        player_start_attack(e);
}
