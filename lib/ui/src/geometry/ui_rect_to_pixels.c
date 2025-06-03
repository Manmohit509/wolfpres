/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** rect_to_pixels
*/

#include "ui/geometry.h"

sfFloatRect ui_rect_to_pixels(
    ui_rect_t const rect,
    sfRenderTexture const *target)
{
    sfVector2u const size = sfRenderTexture_getSize(target);
    sfFloatRect const abs = {
        .left = rect.x * (float) size.x,
        .top = rect.y * (float) size.y,
        .width = rect.width * (float) size.x,
        .height = rect.height * (float) size.y,
    };

    return abs;
}
