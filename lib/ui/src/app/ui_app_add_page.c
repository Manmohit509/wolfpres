/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_add_page
*/

#include <stdlib.h>

#include "ui/app.h"

void ui_app_add_page(ui_app_t *app, const char *name, ui_page_t *page)
{
    if (!app || !name || !page)
        return;
    hashmap_insert(app->pages, name, page);
}
