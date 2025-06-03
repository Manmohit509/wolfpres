/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** widget_destroy
*/

#include "ui/widget.h"

void ui_widget_destroy(ui_widget_t *self)
{
    if (!self || !self->destroy)
        return;
    self->destroy(self);
}
