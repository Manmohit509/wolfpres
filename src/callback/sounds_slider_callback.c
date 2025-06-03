/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** musics_sounds_callback
*/

#include "process.h"

void sounds_slider_callback(float value, void *user_data)
{
    process_t *process = user_data;

    if (process == NULL)
        return;
    process->settings.sound_multiplier = value;
}
