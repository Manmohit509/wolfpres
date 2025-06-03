/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** preview_widget_handle_event
*/

#include "render/widgets.h"
#include "utils.h"

void preview_widget_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target)
{
    preview_data_t *preview_data = self->data;

    (void) event;
    (void) target;
    music_switch(preview_data->process, "bg_music");
}