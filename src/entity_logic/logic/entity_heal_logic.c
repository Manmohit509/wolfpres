/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_heal_logic
*/

#include <stdlib.h>

#include "utils.h"
#include "wolf3d.h"

void heal_data_destructor(void *ptr)
{
    heal_data_t *data = ptr;

    if (!data)
        return;
    if (data->sound)
        sfSound_destroy(data->sound);
    free(data);
}

void *heal_data_constructor(void *ptr)
{
    process_t *process = ptr;
    sound_asset_t *asset = asset_manager_get_sound(process->assets, "deo_sound");
    heal_data_t *data = calloc(1, sizeof(heal_data_t));

    if (!data)
        return NULL;
    if (!asset || !asset->buffer)
        return data;
    data->sound = sfSound_create();
    if (!data->sound)
        return data;
    sfSound_setBuffer(data->sound, asset->buffer);
    sfSound_setRelativeToListener(data->sound, sfTrue);
    return data;
}

void entity_heal_logic(entity_t *entity, void *data)
{
    process_t *process = data;
    entity_t *player = entity_manager_get_by_tag(process->level->entities, "player");
    heal_data_t *heal_data = entity->data;

    if (!player || !heal_data)
        return;
    sfSound_setVolume(heal_data->sound, process->settings.sound_multiplier * 100);
    if (heal_data->is_using) {
        if (sfSound_getStatus(heal_data->sound) != sfPlaying) {
            entity_manager_mark_for_removal(process->level->entities, entity);
        }
        return;
    }
    if (compute_distance(player->pos, entity->pos) > 0.5f)
        return;

    if (player->health >= 100)
        return;
    player->health += 20;
    heal_data->is_using = true;
    if (player->health > 100)
        player->health = 100;
    if (heal_data->sound) {
        sfSound_play(heal_data->sound);
    }
}

