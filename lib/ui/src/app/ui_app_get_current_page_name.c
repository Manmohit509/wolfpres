/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ui_app_get_current_page_name
*/

#include "ui/app.h"

char const *ui_app_get_current_page_name(ui_app_t *app)
{
    if (!app || !app->stack) {
        return NULL;
    }
    return app->stack[0];
}
