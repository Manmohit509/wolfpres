/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** settings
*/

#ifndef SETTINGS_H
    #define SETTINGS_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>

    #define SAVE_PATH ".settings"

typedef enum quality_e {
    LOW = 16,
    MEDIUM = 8,
    HIGH = 1
} quality_t;

typedef struct settings_s {
    double sound_multiplier;
    float music_multiplier;
    quality_t render_quality;
    sfVector2u screen_size;
    sfVector2f scale_size;
    double sensitivity;
} settings_t;

settings_t settings_default(void);
settings_t settings_load(void);
bool settings_save(settings_t settings);

#endif /* SETTINGS_H */
