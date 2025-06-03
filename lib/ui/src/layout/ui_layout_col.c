/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** layout_col
*/

#include "ui/layout.h"

static float align_x_in_area(
    float container_x,
    float container_width,
    float box_width,
    ui_align_x_t align)
{
    switch (align) {
        case UI_ALIGN_LEFT:
            return container_x;
        case UI_ALIGN_CENTER:
            return container_x + (container_width - box_width) / 2.0f;
        case UI_ALIGN_RIGHT:
            return container_x + container_width - box_width;
        default:
            return container_x;
    }
}

static float align_y_axis(
    float container_y,
    float container_height,
    float group_height,
    ui_align_y_t align)
{
    switch (align) {
        case UI_ALIGN_TOP:
            return container_y;
        case UI_ALIGN_MIDDLE:
            return container_y + (container_height - group_height) / 2.0f;
        case UI_ALIGN_BOTTOM:
            return container_y + container_height - group_height;
        default:
            return container_y;
    }
}

static float ui_layout_col_compute_group_height(ui_layout_config_t *config)
{
    float total = 0.0f;
    ui_widget_t *w = NULL;
    ui_rect_t *r = NULL;

    if (!config->use_fixed_size)
        return config->rect.height;
    for (int i = 0; i < config->count; ++i) {
        w = config->widgets[i];
        if (!w || !w->data)
            continue;
        r = (ui_rect_t *)w->data;
        total += r->height;
    }
    total += config->padding_y * (config->count - 1);
    return total;
}

static void ui_layout_col_place_one(
    ui_widget_t *widget,
    ui_layout_config_t *config,
    ui_page_t *page,
    float *y)
{
    ui_rect_t *r = (ui_rect_t *)widget->data;
    float height = config->use_fixed_size ? r->height
        : (config->rect.height - config->padding_y *
            (config->count - 1)) / config->count;
    float width = config->use_fixed_size ? r->width : config->rect.width;
    float x = align_x_in_area(config->rect.x, config->rect.width, width,
        config->align_x);

    r->x = x;
    r->y = *y;
    r->width = width;
    r->height = height;
    widget->pos = (sfVector2f){r->x, r->y};
    ui_page_add_widget(page, widget);
    *y += height + config->padding_y;
}

static void ui_layout_col_place_widgets(
    ui_page_t *page,
    ui_layout_config_t *config,
    float start_y)
{
    float y = start_y;
    ui_widget_t *w = NULL;

    for (int i = 0; i < config->count; ++i) {
        w = config->widgets[i];
        if (!w || !w->data)
            continue;
        ui_layout_col_place_one(w, config, page, &y);
    }
}

void ui_layout_col(ui_page_t *page, ui_layout_config_t *config)
{
    float group_height = 0;
    float start_y = 0;

    if (!config || !config->widgets || config->count <= 0)
        return;
    group_height = ui_layout_col_compute_group_height(config);
    start_y = align_y_axis(
        config->rect.y, config->rect.height, group_height, config->align_y);
    ui_layout_col_place_widgets(page, config, start_y);
}
