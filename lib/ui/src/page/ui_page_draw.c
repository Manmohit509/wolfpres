/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** page_draw
*/

#include "ui/page.h"

void ui_page_draw(ui_page_t *page, sfRenderTexture *target)
{
    for (int i = 0; i < page->count; ++i) {
        ui_widget_draw(page->widgets[i], target);
    }
}
