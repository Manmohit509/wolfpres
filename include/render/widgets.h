/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** widgets
*/

#ifndef RENDER_WIDGETS_H
    #define RENDER_WIDGETS_H

    #include "ui/widget.h"
    #include "process.h"


typedef struct preview_data_s {
    process_t *process;
} preview_data_t;

ui_widget_t *preview_widget_create(process_t *process);
void preview_widget_destroy(ui_widget_t *widget);
void preview_widget_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target);
void preview_widget_draw(ui_widget_t *self, sfRenderTexture *target);

#endif /* RENDER_WIDGETS_H */
