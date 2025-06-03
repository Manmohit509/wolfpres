/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** widget_draw
*/

#include "ui/widget.h"

void ui_widget_draw(ui_widget_t *self, sfRenderTexture *target)
{
    if (!self || !self->draw)
        return;
    self->draw(self, target);
}
