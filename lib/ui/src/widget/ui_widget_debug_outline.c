/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** widget_debug_outline
*/

#include <stdio.h>

#include "ui/widget.h"
#include "ui/geometry.h"

void ui_widget_debug_outline(
    ui_widget_t *self,
    sfRenderTexture *target,
    sfColor color)
{
    ui_rect_t *rect = (ui_rect_t *)self->data;
    sfFloatRect bounds = ui_rect_to_pixels(*rect, target);
    sfRectangleShape *outline = NULL;

    outline = sfRectangleShape_create();
    if (!outline)
        return;
    sfRectangleShape_setPosition(outline,
        (sfVector2f){bounds.left, bounds.top});
    sfRectangleShape_setSize(outline,
        (sfVector2f){bounds.width, bounds.height});
    sfRectangleShape_setFillColor(outline, sfTransparent);
    sfRectangleShape_setOutlineColor(outline, color);
    sfRectangleShape_setOutlineThickness(outline, 2.0f);
    sfRenderTexture_drawRectangleShape(target, outline, NULL);
    sfRectangleShape_destroy(outline);
}
