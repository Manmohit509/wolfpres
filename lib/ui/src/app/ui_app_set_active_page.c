/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_set_active_page
*/

#include <stdlib.h>
#include <string.h>
#include "ui/app.h"

void ui_app_set_active_page(ui_app_t *app, const char *name)
{
    if (!app || !name || !hashmap_get(app->pages, name))
        return;
    for (int i = 0; i < app->stack_size; ++i)
        free(app->stack[i]);
    app->stack_size = 0;
    if (app->stack_capacity <= 0) {
        app->stack_capacity = 4;
        app->stack = malloc(sizeof(char *) * app->stack_capacity);
    }
    app->stack[app->stack_size] = strdup(name);
    app->stack_size++;
}
