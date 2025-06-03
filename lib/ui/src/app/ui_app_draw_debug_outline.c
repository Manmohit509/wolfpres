/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_draw_debug_outline
*/

#include "ui/app.h"

void ui_app_draw_debug_outline(
    ui_app_t *app,
    sfRenderTexture *target,
    sfColor color)
{
    ui_widget_t *w = NULL;
    ui_page_t *page = NULL;

    if (!app || !target)
        return;
    page = ui_app_current_page(app);
    if (!page)
        return;
    for (int i = 0; i < page->count; ++i) {
        w = page->widgets[i];
        if (w)
            ui_widget_debug_outline(w, target, color);
    }
}
