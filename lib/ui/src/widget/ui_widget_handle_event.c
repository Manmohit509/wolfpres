/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** widget_handle_event
*/

#include "ui/widget.h"

void ui_widget_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target)
{
    if (!self || !self->handle_event)
        return;
    self->handle_event(self, event, target);
}
