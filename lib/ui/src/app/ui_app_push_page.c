/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_push_page
*/

#include <stdlib.h>
#include <string.h>
#include "ui/app.h"

void ui_app_push_page(ui_app_t *app, const char *name)
{
    char **reallocated_stack = NULL;

    if (!app || !name || !hashmap_get(app->pages, name))
        return;
    if (app->stack_size >= app->stack_capacity) {
        app->stack_capacity = app->stack_capacity > 0 ?
            app->stack_capacity * 2 : 4;
        reallocated_stack = realloc(app->stack, sizeof(char *) *
            app->stack_capacity);
        if (!reallocated_stack) {
            free(app->stack);
            app->stack = NULL;
            return;
        }
        app->stack = reallocated_stack;
    }
    app->stack[app->stack_size] = strdup(name);
    app->stack_size++;
}
