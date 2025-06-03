/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_create
*/

#include <stdlib.h>

#include "ui/app.h"

ui_app_t *ui_app_create(void)
{
    ui_app_t *app = calloc(1, sizeof(ui_app_t));

    if (!app)
        return NULL;
    app->pages = hashmap_create(32);
    if (!app->pages) {
        free(app);
        return NULL;
    }
    app->stack_capacity = 4;
    app->stack = calloc(app->stack_capacity, sizeof(char *));
    if (!app->stack) {
        hashmap_destroy(app->pages, NULL);
        free(app);
        return NULL;
    }
    app->stack_size = 0;
    return app;
}
