/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** settings_load
*/

#include <stdio.h>

#include "settings.h"

settings_t settings_load(void)
{
    FILE *file = fopen(SAVE_PATH, "r");
    settings_t settings;

    if (file == NULL) {
        return settings_default();
    }
    if (fread(&settings, 1, sizeof(settings_t), file) != sizeof(settings_t)) {
        return settings_default();
    }
    return settings;
}
