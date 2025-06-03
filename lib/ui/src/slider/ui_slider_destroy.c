/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_slider_destroy
*/
#include <stdlib.h>

#include "ui/slider.h"

void ui_slider_destroy(ui_widget_t *widget)
{
    ui_slider_t *s = NULL;

    if (!widget)
        return;
    s = widget->data;
    free(widget);
    if (!s)
        return;
    if (s->background_texture)
        sfTexture_destroy(s->background_texture);
    if (s->cursor_texture)
        sfTexture_destroy(s->cursor_texture);
    if (s->background_sprite)
        sfSprite_destroy(s->background_sprite);
    if (s->cursor_sprite)
        sfSprite_destroy(s->cursor_sprite);
    free(s);
}
