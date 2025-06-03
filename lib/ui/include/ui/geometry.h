/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** geometry
*/

#ifndef UI_GEOMETRY_H
    #define UI_GEOMETRY_H

    #include <SFML/Graphics.h>

typedef struct {
    float x;      // between 0.0 and 1.0 (0% and 100% of the screen size)
    float y;
    float width;
    float height;
} ui_rect_t;

// convert a `ui_rect_t` (propertially) to `sfFloatRect` (absolute pixels)
sfFloatRect ui_rect_to_pixels(
    ui_rect_t rect,
    sfRenderTexture const *target);

// converta pixel position to relative coords (between 0.0 and 1.0)
sfVector2f ui_point_to_proportions(
    sfVector2i point,
    sfRenderTexture const *target);

sfVector2f interpolate(sfVector2f a, sfVector2f b, float t);
sfVector2f compute_sprite_size(sfVector2u tex_size, float scale);

#endif /* UI_GEOMETRY_H */
