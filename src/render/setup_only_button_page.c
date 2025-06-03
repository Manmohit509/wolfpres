/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setup_home_page
*/

#include <stdbool.h>
#include <stdlib.h>

#include "utils.h"
#include "display.h"
#include "all_page.h"

static bool setup_but_render(app_t *app, page_t *page,
    info_buttons_t const *but)
{
    component_t *component = NULL;

    for (size_t i = 0; but[i].path != NULL; ++i) {
        component = component_button_create(&(but[i]), app);
        if (component == NULL) {
            return false;
        }
        register_component(app, page, component);
    }
    return true;
}

bool setup_only_but_page(app_t *app, page_info_t const *i_page)
{
    page_t *page = page_create();

    if (page == NULL) {
        return false;
    }
    if (!setup_but_render(app, page, i_page->all_but)) {
        return false;
    }
    app_register_page(app, page);
    if (app->current_page == NULL)
        app->current_page = page;
    get_data(app)->pages.home = page;
    return true;
}
