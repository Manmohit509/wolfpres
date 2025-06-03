/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_enum_selector_create
*/

#include <stdbool.h>
#include <stdlib.h>
#include "ui/enum_selector.h"

static bool allocate_textures(ui_enum_selector_t *s, int count)
{
    s->textures_off = calloc(count, sizeof(sfTexture *));
    s->textures_on = calloc(count, sizeof(sfTexture *));
    s->textures_hover = calloc(count, sizeof(sfTexture *));
    return s->textures_off && s->textures_on && s->textures_hover;
}

static bool load_all_textures(ui_enum_selector_t *s)
{
    for (int i = 0; i < s->entry_count; ++i) {
        s->textures_off[i] = sfTexture_createFromFile(
            s->entries[i].texture_off, NULL);
        s->textures_on[i] = sfTexture_createFromFile(
            s->entries[i].texture_on, NULL);
        s->textures_hover[i] = sfTexture_createFromFile(
            s->entries[i].texture_hover, NULL);
        if (!s->textures_off[i] || !s->textures_on[i] || !s->textures_hover[i])
            return false;
    }
    return true;
}

static void setup_const(
    ui_enum_selector_t *s,
    ui_enum_selector_config_t const *cfg)
{
    s->rect = cfg->rect;
    s->entries = cfg->entries;
    s->entry_count = cfg->entry_count;
    s->current_index = 0;
    s->hovered = false;
    s->pressed = false;
    s->on_change = cfg->on_change;
    s->user_data = cfg->user_data;
}

static void setup_widget_methods(ui_widget_t *widget)
{
    widget->draw = ui_enum_selector_draw;
    widget->handle_event = ui_enum_selector_handle_event;
    widget->destroy = ui_enum_selector_destroy;
}

ui_widget_t *ui_enum_selector_create(ui_enum_selector_config_t const *cfg)
{
    ui_widget_t *widget = malloc(sizeof(ui_widget_t));
    ui_enum_selector_t *s = calloc(1, sizeof(ui_enum_selector_t));

    if (!widget || !s) {
        free(widget);
        free(s);
        return NULL;
    }
    setup_const(s, cfg);
    s->sprite = sfSprite_create();
    if (!allocate_textures(s, s->entry_count) ||
        !load_all_textures(s) ||
        !s->sprite) {
        ui_enum_selector_destroy(widget);
        return NULL;
    }
    widget->data = s;
    setup_widget_methods(widget);
    return widget;
}
