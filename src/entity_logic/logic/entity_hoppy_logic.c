/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_hoppy_logic
*/

#include <stdlib.h>

#include "utils.h"
#include "wolf3d.h"

static void setup_hoppy_sound(sfSound *sound)
{
    sfSound_setLoop(sound, sfTrue);
    sfSound_play(sound);
    sfSound_setRelativeToListener(sound, sfFalse);
    sfSound_setVolume(sound, 100.0f);
    sfSound_setMinDistance(sound, 1.0f);
    sfSound_setAttenuation(sound, 25.0f);
}

void *hoppy_data_constructor(void *ptr)
{
    process_t *process = ptr;
    hoppy_data_t *data = NULL;
    sound_asset_t *s_asset = asset_manager_get_sound(process->assets,
        "cat_sound");

    if (!s_asset)
        return NULL;
    data = malloc(sizeof(hoppy_data_t));
    if (!data) {
        return NULL;
    }
    data->sound = sfSound_create();
    if (data->sound == NULL) {
        free(data);
        return NULL;
    }
    sfSound_setBuffer(data->sound, s_asset->buffer);
    setup_hoppy_sound(data->sound);
    return data;
}

void hoppy_data_destructor(void *ptr)
{
    hoppy_data_t *data = ptr;

    if (data == NULL) {
        return;
    }
    if (data->sound != NULL) {
        sfSound_destroy(data->sound);
    }
    free(data);
}

void entity_hoppy_logic(entity_t *entity, void *data)
{
    process_t *process = data;
    hoppy_data_t *d = entity->data;

    if (entity->data == NULL) {
        return;
    }
    if (d->sound) {
        sfSound_setPosition(d->sound,
            (sfVector3f) {entity->pos.x, 0.0f, entity->pos.y});
        sfSound_setVolume(d->sound, process->settings.sound_multiplier * 100);
    }
    entity->angle_deg -= ROTATE_SPEED * process->clock.delta_t *
        ROTATE_SPEED;
    entity->angle_deg = format_rotation(entity->angle_deg);
}
