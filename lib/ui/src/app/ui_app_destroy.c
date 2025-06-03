/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_app_destroy
*/

#include <stdlib.h>

#include "ui/app.h"

void ui_app_destroy(ui_app_t *app)
{
    if (!app)
        return;
    for (int i = 0; i < app->stack_size; ++i)
        free(app->stack[i]);
    free(app->stack);
    hashmap_destroy(app->pages, (void (*)(void *))ui_page_destroy);
    free(app);
}
