/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_current_page
*/

#include "ui/app.h"

ui_page_t *ui_app_current_page(ui_app_t *app)
{
    const char *name = NULL;

    if (!app || app->stack_size <= 0)
        return NULL;
    name = app->stack[app->stack_size - 1];
    if (name == NULL) {
        return NULL;
    }
    return hashmap_get(app->pages, name);
}
