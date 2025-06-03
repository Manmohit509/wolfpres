/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** image_button_destroy
*/

#include <stdlib.h>

#include "ui/image_button.h"

void ui_image_button_destroy(ui_widget_t *self)
{
    ui_image_button_t *btn = NULL;

    if (!self || !self->data)
        return;
    btn = self->data;
    if (btn->sprite)
        sfSprite_destroy(btn->sprite);
    if (btn->texture_default)
        sfTexture_destroy(btn->texture_default);
    if (btn->texture_hover)
        sfTexture_destroy(btn->texture_hover);
    if (btn->texture_pressed)
        sfTexture_destroy(btn->texture_pressed);
    free(btn);
    free(self);
}
