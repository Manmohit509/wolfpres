/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** musics_slider_callback
*/

#include "process.h"
#include "utils.h"

void musics_slider_callback(float value, void *user_data)
{
    process_t *process = user_data;

    if (process == NULL)
        return;
    process->settings.music_multiplier = value;
    update_music_volume(process);
}
