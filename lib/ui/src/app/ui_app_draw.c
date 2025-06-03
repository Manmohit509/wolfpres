/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_draw
*/

#include "ui/app.h"

void ui_app_draw(ui_app_t *app, sfRenderTexture *target)
{
    ui_page_t *page = NULL;

    if (!app || !target)
        return;
    page = ui_app_current_page(app);
    if (page)
        ui_page_draw(page, target);
}
