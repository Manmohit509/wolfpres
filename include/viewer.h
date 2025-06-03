/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity
*/

#ifndef VIEWER_H
    #define VIEWER_H

    #include <SFML/Graphics.h>

typedef struct viewer_s {
    sfVector2f direction;
    sfVector2f pos;
    double angle;
    size_t fov;
    size_t px_count;
} viewer_t;

#endif /* VIEWER_H */
