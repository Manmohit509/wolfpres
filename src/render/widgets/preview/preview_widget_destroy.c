/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** preview_widget_destroy
*/

#include <stdlib.h>

#include "render/widgets.h"

void preview_widget_destroy(ui_widget_t *widget)
{
    if (!widget)
        return;

    if (widget->data)
        free(widget->data);
    free(widget);
}
