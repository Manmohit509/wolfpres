/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** renderer
*/

#ifndef RENDERER_H
    #define RENDERER_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>

    #define DIS_MUL 64

typedef struct ray_cast_result_s {
    double dist;
    sfVector2f coords;
    sfVector2f ray;
    sfVector2i i_coords;
    bool is_vertical_hit;
    double angle;
} ray_cast_result_t;

#endif /* RENDERER_H */
