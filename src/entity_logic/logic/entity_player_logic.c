
/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_player_logic
*/

#include <stdlib.h>

#include "utils.h"
#include "wolf3d.h"

static void setup_animation(
    entity_asset_t *texture,
    sound_asset_t *sound,
    animation_t *animation)
{
    if (texture && texture->texture) {
        animation->texture = texture->texture;
        animation->frame_count = texture->face_count;
        animation->frame_duration = 0.01f;
        animation->frames = (sfIntRect)
            {0, 0, texture->width, texture->height};
    }
    if (sound && sound->buffer) {
        animation->sound = sfSound_create();
        if (animation->sound)
            sfSound_setBuffer(animation->sound, sound->buffer);
    }
    animation->frame_duration = 0.1f;
}

static void full_setup(
    animation_t *animation,
    char const *texture_id,
    char const *sound_id,
    process_t const *process)
{
    entity_asset_t *texture = asset_manager_get_entity(process->assets,
        texture_id);
    sound_asset_t *sound = asset_manager_get_sound(process->assets,
        sound_id);

    setup_animation(texture, sound, animation);
}

static void setup_textures(player_data_t *data, process_t const *process)
{
    full_setup(&data->attack_anim[MELEE_ID],
        "attack_melee_weapon", "whoosh_sound", process);
    full_setup(&data->inspect_anim[MELEE_ID],
        "inspect_melee_weapon", "boing_sound", process);
    full_setup(&data->attack_anim[RANGE_ID],
        "attack_range_weapon", "paper_sound", process);
    full_setup(&data->inspect_anim[RANGE_ID],
        "inspect_range_weapon", "book_sound", process);
}

static void destroy_animation(animation_t *animation)
{
    if (animation->sound) {
        sfSound_destroy(animation->sound);
    }
}

void player_data_destructor(void *ptr)
{
    player_data_t *data = ptr;

    if (data == NULL) {
        return;
    }
    destroy_animation(&data->attack_anim[0]);
    destroy_animation(&data->attack_anim[1]);
    destroy_animation(&data->inspect_anim[0]);
    destroy_animation(&data->inspect_anim[1]);
    sfSound_destroy(data->running);
    sfSound_destroy(data->breathing);
    sfSound_destroy(data->out_of_breathing);
    free(data);
}

static sfSound *get_sound(process_t const *process, char *sound_id)
{
    sfSound *result = sfSound_create();
    sound_asset_t *sound = asset_manager_get_sound(process->assets, sound_id);

    if (!sound)
        return NULL;
    sfSound_setBuffer(result, sound->buffer);
    return result;
}


static void setup_sound(player_data_t *data, process_t const *process)
{
    data->running = get_sound(process, "running");
    data->out_of_breathing = get_sound(process, "out_of_breath");
    data->breathing = get_sound(process, "heavy_breathing");
}

void *player_data_constructor(void *ptr)
{
    process_t *process = ptr;
    player_data_t *data = calloc(1, sizeof(player_data_t));

    if (!data || !process) {
        free(data);
        return NULL;
    }
    data->current_weapon = WEAPON_NONE;
    data->player_speed = PLAYER_SPEED;
    data->is_running = false;
    setup_textures(data, process);
    setup_sound(data, process);
    return data;
}

static void stamina_logic(entity_t *entity, void *data)
{
    process_t *process = data;
    player_data_t *player = NULL;

    if (entity == NULL || entity->data == NULL) {
        return;
    }
    player = entity->data;
    if (process->inputs.backward_key == false && process->inputs.forward_key == false && process->inputs.left_key == false && process->inputs.right_key == false) {
        player->stamina += process->clock.delta_t * 15;
        if (player->stamina > 100)
        player->stamina = 100;
    }
    if (process->inputs.backward_key == true || process->inputs.forward_key == true || process->inputs.left_key == true || process->inputs.right_key == true) {
        player->stamina += process->clock.delta_t * 5;
        if (player->stamina > 100)
        player->stamina = 100;
    }
}

static void update_volume(player_data_t *data, process_t *process)
{
    sfSound_setVolume(data->attack_anim[0].sound, process->settings.sound_multiplier * 100);
    sfSound_setVolume(data->attack_anim[1].sound, process->settings.sound_multiplier * 100);
    sfSound_setVolume(data->inspect_anim[0].sound, process->settings.sound_multiplier * 100);
    sfSound_setVolume(data->inspect_anim[1].sound, process->settings.sound_multiplier * 100);
}

void entity_player_logic(entity_t *entity, void *data)
{
    process_t *process = data;

    stamina_logic(entity, data);
    handle_movement(entity, process);
    update_sound_listener(entity);
    update_volume(entity->data, process);
    player_update_interaction(process, entity->pos, entity->data);
}
