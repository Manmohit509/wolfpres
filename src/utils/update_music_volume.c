/*
** EPITECH PROJECT, 2025
** Gwolf
** File description:
** update_music_volume
*/

#include "process.h"

static void update_volume(char const *key, void *value, void *userdata)
{
    settings_t *settings = userdata;
    music_asset_t *music = value;

    (void) key;
    if (!value || !settings) {
        return;
    }
    sfMusic_setVolume(music->music, settings->music_multiplier * 100);
    if (sfMusic_getStatus(music->music) == sfPaused) {
        sfMusic_play(music->music);
    }
}

void update_music_volume(process_t *process)
{
    hashmap_foreach(process->assets->musics, update_volume, &process->settings);
}
