/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** register_in_game_page
*/

#include "render/widgets.h"
#include "ui/ui.h"
#include "wolf3d.h"
#include "render/pages.h"

static bool add_preview_widget(ui_page_t *page, process_t *process)
{
    ui_widget_t *widget = preview_widget_create(process);

    if (!widget) {
        return false;
    }
    ui_page_add_widget(page, widget);
    return true;
}

int register_in_game_page(process_t *process)
{
    ui_page_t *page = ui_page_create();

    if (!page) {
        return FAILURE_EXIT;
    }
    if (!add_preview_widget(page, process)) {
        ui_page_destroy(page);
        return FAILURE_EXIT;
    }
    ui_app_add_page(process->app, "in_game", page);
    return SUCCESS_EXIT;
}
