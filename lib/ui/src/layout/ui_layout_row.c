/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** layout_row
*/
#include "ui/layout.h"
#include "ui/page.h"
#include "ui/widget.h"

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

static float ui_layout_row_compute_group_width(ui_layout_config_t *config)
{
    float total = 0.0f;
    ui_widget_t *w = NULL;
    ui_rect_t *r = NULL;

    if (!config->use_fixed_size)
        return config->rect.width;
    for (int i = 0; i < config->count; ++i) {
        w = config->widgets[i];
        if (!w || !w->data)
            continue;
        r = (ui_rect_t *)w->data;
        total += r->width;
    }
    total += config->padding_x * (config->count - 1);
    return total;
}

static void ui_layout_row_place_one(
    ui_widget_t *widget,
    ui_layout_config_t *config,
    ui_page_t *page,
    float *x)
{
    ui_rect_t *r = (ui_rect_t *)widget->data;
    float width = config->use_fixed_size
        ? r->width : (config->rect.width - config->padding_x *
            (config->count - 1)) / config->count;
    float height = config->use_fixed_size
        ? r->height : config->rect.height;
    float y = align_y_axis(config->rect.y, config->rect.height,
        height, config->align_y);

    r->x = *x;
    r->y = y;
    r->width = width;
    r->height = height;
    widget->pos = (sfVector2f){r->x, r->y};
    ui_page_add_widget(page, widget);
    *x += width + config->padding_x;
}

static void ui_layout_row_place_widgets(
    ui_page_t *page,
    ui_layout_config_t *config,
    float start_x)
{
    float x = start_x;
    ui_widget_t *w = NULL;

    for (int i = 0; i < config->count; ++i) {
        w = config->widgets[i];
        if (!w || !w->data)
            continue;
        ui_layout_row_place_one(w, config, page, &x);
    }
}

void ui_layout_row(ui_page_t *page, ui_layout_config_t *config)
{
    float group_width = 0;
    float start_x = 0;

    if (!config || !config->widgets || config->count <= 0)
        return;
    group_width = ui_layout_row_compute_group_width(config);
    start_x = align_x_in_area(
        config->rect.x, config->rect.width, group_width, config->align_x);
    ui_layout_row_place_widgets(page, config, start_x);
}
