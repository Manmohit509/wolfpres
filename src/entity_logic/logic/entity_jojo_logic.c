/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_jojo_logic
*/

#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "wolf3d.h"

void *jojo_data_constructor(UNUSED void *ptr)
{
    jojo_data_t *data = calloc(1, sizeof(jojo_data_t));
    return data;
}

void jojo_data_destructor(void *ptr)
{
    jojo_data_t *data = ptr;

    if (!data)
        return;
    if (data->sound)
        sfSound_destroy(data->sound);
    free(data);
}

static float angle_from_vector(sfVector2f v)
{
    return atan2f(v.y, v.x);
}

static void play_random_jojo_sound(jojo_data_t *data, process_t *process, sfVector2f pos)
{
    int index = rand() % 6 + 1;
    char sound_id[32];
    snprintf(sound_id, sizeof(sound_id), "jojo_%d_sound", index);
    sound_asset_t *asset = asset_manager_get_sound(process->assets, sound_id);

    if (!asset || !asset->buffer)
        return;

    if (data->sound)
        sfSound_destroy(data->sound);

    data->sound = sfSound_create();
    if (!data->sound)
        return;

    sfSound_setBuffer(data->sound, asset->buffer);
    sfSound_setLoop(data->sound, sfFalse);
    sfSound_setRelativeToListener(data->sound, sfFalse);
    sfSound_setMinDistance(data->sound, 8.0f);
    sfSound_setAttenuation(data->sound, 5.0f);
    sfSound_setVolume(data->sound, process->settings.sound_multiplier * 100);
    sfSound_setPosition(data->sound, (sfVector3f){pos.x, 0.0f, pos.y});
    sfSound_play(data->sound);
}

static void maybe_play_next_sound(jojo_data_t *data, process_t *process, sfVector2f pos)
{
    if (!data->is_agro)
        return;

    if (!data->sound || sfSound_getStatus(data->sound) == sfStopped)
        play_random_jojo_sound(data, process, pos);
    else
        sfSound_setPosition(data->sound, (sfVector3f){pos.x, 0.0f, pos.y});
}

static void handle_jojo_movement(entity_t *entity, jojo_data_t *data, process_t *p)
{
    sfVector2f delta = {0};

    if (!data->is_agro)
        return;

    entity->angle_deg = RAD_TO_DEG(angle_from_vector((sfVector2f){
        data->agro_pos.x - entity->pos.x,
        data->agro_pos.y - entity->pos.y}));
    entity->direction = compute_orientation(entity->angle_deg);
    delta = (sfVector2f){
        entity->direction.x * p->clock.delta_t * JOJO_SPEED,
        entity->direction.y * p->clock.delta_t * JOJO_SPEED};
    entity->angle_deg = RAD_TO_DEG(vector2f_to_angle(entity->direction)) + 180;

    entity->sprite_state = ((int)sfTime_asMilliseconds(p->clock.last_time) / 500) % 2 + 1;
    entity->pos.x += delta.x;
    entity->pos.y += delta.y;

    maybe_play_next_sound(data, p, entity->pos);

    if (compute_distance(entity->pos, data->agro_pos) <= 0.5f) {
        entity->sprite_state = 0;
        data->is_agro = false;
    }
}

static void compute_pathfinding(entity_t *entity, jojo_data_t *data, process_t *process)
{
    viewer_t view = {
        .angle = entity->angle_deg,
        .direction = entity->direction,
        .fov = JOJO_FOV,
        .pos = entity->pos,
    };
    entity_t *player = entity_manager_get_by_tag(process->level->entities, "player");

    if (!player)
        return;
    if (is_wall_between(process->level->map, &view, player->pos) ||
        fabsf(compute_angle(entity->direction, (sfVector2f){
            player->pos.x - entity->pos.x,
            player->pos.y - entity->pos.y})) / 2 > view.fov)
        return;

    if (!data->is_agro) {
        data->is_agro = true;
        data->agro_pos = player->pos;
    } else {
        data->agro_pos = player->pos;
    }
}

static void handle_damage(entity_t *entity, jojo_data_t *data, process_t *process)
{
    entity_t *player = entity_manager_get_by_tag(process->level->entities, "player");

    if (!player)
        return;
    if (data->aggression_cooldown > 0) {
        data->aggression_cooldown -= process->clock.delta_t;
        if (data->aggression_cooldown < 0)
            data->aggression_cooldown = 0;
        return;
    }
    if (compute_distance(player->pos, entity->pos) > JOJO_AGGRESSION_RANGE)
        return;

    data->aggression_cooldown = JOJO_AGGRESSION_COOLDOWN;
    player->health -= JOJO_AGGRESSION_DAMAGE;
    if (player->health < 0)
        player->health = 0;
}

void entity_jojo_logic(entity_t *entity, void *data)
{
    jojo_data_t *jojo_data = entity->data;
    process_t *process = data;

    if (!jojo_data)
        return;

    if (entity->health <= 0) {
        entity->sprite_state = 3;
        if (jojo_data->sound) {
            sfSound_stop(jojo_data->sound);
            sfSound_destroy(jojo_data->sound);
            jojo_data->sound = NULL;
        }
        return;
    }

    compute_pathfinding(entity, jojo_data, process);
    handle_jojo_movement(entity, jojo_data, process);
    handle_damage(entity, jojo_data, process);
}
