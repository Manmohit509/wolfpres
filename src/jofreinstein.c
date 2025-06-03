/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** joffreinsten
*/

#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "wolf3d.h"
#include "entity_logic.h"
#include "listeners.h"

static void (*handlers[])(sfEvent *, process_t *) = {
    handle_movements,
    ingame_interaction_listener,
    NULL
};

static void update_view(process_t *process, sfView *view)
{
    sfRenderWindow_setView(process->window.window, view);
    sfRenderTexture_setView(process->window.scene, view);
}

static int resize_scene(process_t *process, sfSizeEvent *event)
{
    sfVector2u size = {event->width, event->height};
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, size.x, size.y});

    if (view == NULL) {
        logger_error(process->logger,
            "[resize_scene] sfView creation return NULL");
        return FAILURE_EXIT;
    }
    sfRenderTexture_destroy(process->window.scene);
    process->window.scene = sfRenderTexture_create(
        size.x, size.y, sfFalse);
    if (process->window.scene == NULL) {
        logger_error(process->logger,
            "[resize_scene] sfRenderTexture creation NULL");
        sfView_destroy(view);
        return FAILURE_EXIT;
    }
    update_view(process, view);
    sfView_destroy(view);
    return SUCCESS_EXIT;
}

static int handle_events(process_t *process)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(process->window.window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(process->window.window);
        }
        if (event.type == sfEvtResized &&
            resize_scene(process, &event.size) != SUCCESS_EXIT) {
            return FAILURE_EXIT;
        }
        if (event.type == sfEvtKeyPressed && event.key.type == (sfEventType)sfKeyF11 &&
            process_set_window_fullscreen(process,
            !process->window.is_fullscreen)) {
            return FAILURE_EXIT;
        }
        for (size_t i = 0; handlers[i] != NULL; i++) {
            handlers[i](&event, process);
        }
        ui_app_handle_event(process->app, &event, process->window.scene);
    }
    return SUCCESS_EXIT;
}

static void render_process(process_t *process, sfSprite *sprite)
{
    sfRenderTexture_clear(process->window.scene, sfTransparent);
    ui_app_draw(process->app, process->window.scene);
    //ui_app_draw_debug_outline(process->app, process->window.scene, sfRed);
    sfRenderTexture_display(process->window.scene);
    sfSprite_setTexture(sprite,
        sfRenderTexture_getTexture(process->window.scene), sfTrue);
    sfRenderWindow_clear(process->window.window, sfBlack);
    sfRenderWindow_drawSprite(process->window.window, sprite, NULL);
    sfRenderWindow_display(process->window.window);
}

static void run_game_cycle(process_t *process)
{
    if (strcmp(ui_app_get_current_page_name(process->app), "in_game") != 0) {
        return;
    }
    entity_logic_apply(process->entity_logic,
        process->level->entities, process);
    entity_manager_cleanup(process->level->entities, process->entity_logic);
}

static void player_sound_effect(process_t *process)
{
    entity_t *player = entity_manager_get_by_tag(process->level->entities, "player");
    player_data_t *data = NULL;

    if (player == NULL || player->data == NULL) {
        return;
    }
    data = player->data;
    if (data->is_running) {
        if (sfSound_getStatus(data->running) != sfPlaying) {
            sfSound_setLoop(data->running, sfTrue);
            sfSound_play(data->running);
        }
    } else {
        sfSound_stop(data->running);
    }
    float stamina = data->stamina;

    if (stamina >= 99.0f) {
        sfSound_stop(data->breathing);
        sfSound_stop(data->out_of_breathing);

    } else if (stamina > 20.0f) {
        float normalized = (99.0f - stamina) / (99.0f - 20.0f);
        float volume = 5.0f + normalized * (100.0f - 5.0f);
        if (volume > 100.0f) volume = 100.0f;
        sfSound_setVolume(data->breathing, volume);
        if (sfSound_getStatus(data->breathing) != sfPlaying) {
            sfSound_setLoop(data->breathing, sfTrue);
            sfSound_play(data->breathing);
        }
        sfSound_stop(data->out_of_breathing);
    } else {
        sfSound_stop(data->breathing);
        sfSound_setVolume(data->out_of_breathing, 100.0f);
        if (sfSound_getStatus(data->out_of_breathing) != sfPlaying) {
            sfSound_setLoop(data->out_of_breathing, sfTrue);
            sfSound_play(data->out_of_breathing);
        }
    }
}

int run_app(process_t *process)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL) {
        logger_error(process->logger, "[run_app] sfSprite creation NULL");
        return FAILURE_EXIT;
    }
    while (sfRenderWindow_isOpen(process->window.window)) {
        process_update_clock(process);
        run_game_cycle(process);
        if (process->level)
            player_sound_effect(process);
        render_process(process, sprite);
        if (handle_events(process) != SUCCESS_EXIT) {
            sfSprite_destroy(sprite);
            return FAILURE_EXIT;
        }
    }
    sfSprite_destroy(sprite);
    return SUCCESS_EXIT;
}

int joffreystein(void)
{
    process_t process = {0};

    if (process_setup(&process) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
    }
    run_app(&process);
    process_cleanup(&process);
    return SUCCESS_EXIT;
}