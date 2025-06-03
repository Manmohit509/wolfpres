/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_handle_event
*/

#include "ui/app.h"

void ui_app_handle_event(
    ui_app_t *app,
    sfEvent *event,
    sfRenderTexture *target)
{
    ui_page_t *page = NULL;

    if (!app || !event || !target)
        return;
    page = ui_app_current_page(app);
    if (page)
        ui_page_handle_event(page, event, target);
}
