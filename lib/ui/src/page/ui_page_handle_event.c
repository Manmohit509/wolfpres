/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** page_handle_event
*/

#include "ui/page.h"

void ui_page_handle_event(
    ui_page_t *page,
    sfEvent *event,
    sfRenderTexture *target)
{
    for (int i = 0; i < page->count; ++i) {
        ui_widget_handle_event(page->widgets[i], event, target);
    }
}
