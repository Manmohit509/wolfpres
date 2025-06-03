/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** setup_widget_data
*/

#include "render/pages.h"

void setup_widgets_data(ui_widget_t **widget, int count, void *data)
{
    if (widget == NULL || count <= 0) {
        return;
    }
    for (int i = 0; i < count; i++) {
        setup_widget_data(widget[i], data);
    }
}
