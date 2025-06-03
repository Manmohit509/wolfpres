/*
** EPITECH PROJECT, 2025
** Gwolf
** File description:
** handle_movements
*/


#include <string.h>

#include "callback.h"
#include "listeners.h"
#include "wolf3d.h"

static void handle_z_s(process_t *process, sfEvent const *event)
{
    if (event->key.code == sfKeyZ) {
        process->inputs.forward_key = event->type == sfEvtKeyPressed;
    }
    if (event->key.code == sfKeyS) {
        process->inputs.backward_key = event->type == sfEvtKeyPressed;
    }
    if (event->key.code == sfKeyR) {
        process->inputs.reload_key = event->type == sfEvtKeyPressed;
    }
    if (event->key.code == sfKeySpace) {
        process->inputs.shoot_key = event->type == sfEvtKeyPressed;
    }
    if (event->key.code == sfKeyEscape) {
        process->inputs.escape_key = event->type == sfEvtKeyPressed;
    }
}

static void handle_q_d(process_t *process, sfEvent const *event)
{
    if (event->key.code == sfKeyD) {
        process->inputs.right_key = event->type == sfEvtKeyPressed;
    }
    if (event->key.code == sfKeyQ) {
        process->inputs.left_key = event->type == sfEvtKeyPressed;
    }
}

static void handle_run(sfEvent *event, process_t *process)
{
    entity_t *e = entity_manager_get_by_tag(process->level->entities, "player");
    player_data_t *data = NULL;

    if (e == NULL || e->data == NULL) {
        return;
    }
    data = e->data;
    if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyZ) && data->stamina > 0) {
        data->is_running = true;
        data->player_speed = 6.5f;
    } else {
        data->is_running = false;
        data->player_speed = 3.5f;
    }
}

void handle_movements(sfEvent *event, process_t *process)
{
    if (!process || !process->computer || process->computer->started == true || !process->level)
        return;
    if (process->level) {
        handle_run(event, process);
    }
    if (strcmp(ui_app_get_current_page_name(process->app), "settings") == 0) {
        if (event->type == sfEvtKeyReleased &&
            event->key.code == sfKeyEscape) {
            go_back_callback(process);
        }
        return;
    }
    if (strcmp(ui_app_get_current_page_name(process->app), "in_game") != 0) {
        return;
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEscape) {
        ui_app_push_page(process->app, "settings");
        return;
    }
    handle_q_d(process, event);
    handle_z_s(process, event);
}
