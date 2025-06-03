/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_pop_page
*/

#include <stdlib.h>
#include "ui/app.h"

void ui_app_pop_page(ui_app_t *app)
{
    if (!app || app->stack_size <= 0)
        return;
    free(app->stack[--app->stack_size]);
    app->stack[app->stack_size] = NULL;
}
