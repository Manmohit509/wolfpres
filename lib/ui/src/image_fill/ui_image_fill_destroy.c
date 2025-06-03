/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_image_fill_destroy
*/

#include <stdlib.h>

#include "ui/image_fill.h"

void ui_image_fill_destroy(ui_widget_t *widget)
{
    ui_image_fill_t *img = NULL;

    if (!widget)
        return;
    img = widget->data;
    if (img) {
        if (img->sprite)
            sfSprite_destroy(img->sprite);
        if (img->texture)
            sfTexture_destroy(img->texture);
        free(img);
    }
    free(widget);
}
