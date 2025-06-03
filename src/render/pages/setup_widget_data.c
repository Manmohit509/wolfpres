/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** setup_widget_data
*/

#include "render/pages.h"

void setup_widget_data(ui_widget_t *widget, void *data)
{
    ui_image_button_t *d = NULL;

    if (widget == NULL || widget->data == NULL) {
        return;
    }
    d = widget->data;
    d->user_data = data;
}
