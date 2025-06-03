/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_button_draw
*/

#include <stdlib.h>
#include "ui/button.h"

static void draw_generic_rectangle(
    ui_button_t *btn,
    sfRenderTexture *target)
{
    sfFloatRect abs = ui_rect_to_pixels(btn->rect, target);
    sfRectangleShape *shape = sfRectangleShape_create();

    if (!shape) {
        return;
    }
    sfRectangleShape_setPosition(shape, (sfVector2f){abs.left, abs.top});
    sfRectangleShape_setSize(shape, (sfVector2f){abs.width, abs.height});
    sfRectangleShape_setFillColor(shape, btn->hovered ?
        sfColor_fromRGB(70, 70, 250) : btn->bg_color);
    sfRectangleShape_setOutlineThickness(shape, 2);
    sfRectangleShape_setOutlineColor(shape, sfColor_fromRGB(255, 0, 0));
    sfRenderTexture_drawRectangleShape(target, shape, NULL);
    sfRectangleShape_destroy(shape);
}

static void draw_generic_text(
    ui_button_t *btn,
    sfRenderTexture *target)
{
    sfFloatRect abs = ui_rect_to_pixels(btn->rect, target);
    sfFloatRect bounds = sfText_getLocalBounds(btn->label);
    sfVector2f text_pos = {
        abs.left + (abs.width - bounds.width) / 2 - bounds.left,
        abs.top + (abs.height - bounds.height) / 2 - bounds.top
    };

    sfText_setPosition(btn->label, text_pos);
    sfRenderTexture_drawText(target, btn->label, NULL);
}

void ui_button_draw(ui_widget_t *self, sfRenderTexture *target)
{
    ui_button_t *btn = self->data;

    draw_generic_rectangle(btn, target);
    draw_generic_text(btn, target);
}
