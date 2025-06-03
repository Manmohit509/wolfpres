/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** settings_default
*/

#include "settings.h"

settings_t settings_default(void)
{
    settings_t settings = {
        .sound_multiplier = 1.0f,
        .music_multiplier = 1.0f,
        .render_quality = MEDIUM,
        .sensitivity = 1.0f,
        .screen_size = {1920, 1080},
        .scale_size = {1, 1}
    };

    return settings;
}
