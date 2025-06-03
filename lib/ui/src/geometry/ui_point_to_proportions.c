/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** point_to_proportions
*/

#include "ui/geometry.h"

sfVector2f ui_point_to_proportions(
    sfVector2i const point,
    sfRenderTexture const *target)
{
    sfVector2u const size = sfRenderTexture_getSize(target);
    sfVector2f const rel = {
        .x = (float) point.x / (float) size.x,
        .y = (float) point.y / (float) size.y,
    };

    return rel;
}
