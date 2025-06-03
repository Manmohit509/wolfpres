/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setup_game_page
*/

#include <stdbool.h>

#include "utils.h"
#include "page.h"
#include "display.h"

static void render(app_t const *app,
    component_custom_t const UNUSED *component)
{
    process_t *process = get_data(app);
    entity_t *entity = entity_manager_get_by_tag(process->level->entities,
        "player");
    viewer_t viewer = {0};

    if (entity == NULL) {
        return;
    }
    viewer = (viewer_t) {
        .pos = {entity->pos.x, entity->pos.y},
        .direction = entity->direction,
        .angle = entity->angle_deg,
        .fov = 60,
        .px_count = 512
    };
    process_render(process, &viewer, entity);
}

static bool setup_game_render(app_t *app, page_t *page)
{
    component_t *component = component_custom_create(&render);

    if (component == NULL) {
        return false;
    }
    register_component(app, page, component);
    return true;
}

bool setup_game_page(app_t *app, page_info_t UNUSED const *i_page)
{
    page_t *page = page_create();

    if (page == NULL) {
        return false;
    }
    if (!setup_game_render(app, page)) {
        return false;
    }
    app_register_page(app, page);
    get_data(app)->pages.game = page;
    return true;
}
