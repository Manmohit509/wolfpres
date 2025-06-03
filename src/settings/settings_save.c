/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** settings_save
*/

#include <stdio.h>

#include "settings.h"

bool settings_save(settings_t settings)
{
    FILE *file = fopen(SAVE_PATH, "w");

    if (file == NULL) {
        return false;
    }
    if (fwrite(&settings, 1, sizeof(settings_t), file) != sizeof(settings_t)) {
        return false;
    }
    return true;
}
