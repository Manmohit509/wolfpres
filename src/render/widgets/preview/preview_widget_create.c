/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** preview_widget_create
*/

#include <stdlib.h>

#include "render/widgets.h"

ui_widget_t *preview_widget_create(process_t *process)
{
    ui_widget_t *widget = calloc(1, sizeof(ui_widget_t));
    preview_data_t *data = calloc(1, sizeof(preview_data_t));

    if (!widget || !data) {
        free(widget);
        free(data);
        return NULL;
    }
    data->process = process;
    widget->data = data;
    widget->destroy = preview_widget_destroy;
    widget->handle_event = preview_widget_handle_event;
    widget->draw = preview_widget_draw;
    return widget;
}