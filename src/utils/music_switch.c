/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** music_switch
*/

#include <string.h>

#include "process.h"
#include "utils.h"

static void music_off(
    char const *key,
    void *value,
    void *userdata)
{
    music_asset_t *asset = value;

    if (asset == NULL || asset->music == NULL) {
        return;
    }
    if (strcmp(userdata, key) == 0) {
        if (sfMusic_getStatus(asset->music) != sfPlaying)
            sfMusic_play(asset->music);
    } else if (sfMusic_getStatus(asset->music) == sfPlaying) {
        sfMusic_pause(asset->music);
    }
}

void music_switch(process_t *process, char const *id)
{
    hashmap_foreach(process->assets->musics, &music_off, (char *) id);
}
