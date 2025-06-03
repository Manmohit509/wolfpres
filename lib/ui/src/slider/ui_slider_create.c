/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_slider_create
*/

#include <stdlib.h>
#include "ui/slider.h"

static bool allocate_widget_and_data(
    ui_widget_t **widget,
    ui_slider_t **slider)
{
    *widget = malloc(sizeof(ui_widget_t));
    *slider = calloc(1, sizeof(ui_slider_t));
    return *widget && *slider;
}

static bool load_slider_textures(
    ui_slider_t *slider,
    const ui_slider_config_t *cfg)
{
    slider->background_texture =
        sfTexture_createFromFile(cfg->background_texture_path, NULL);
    slider->cursor_texture =
        sfTexture_createFromFile(cfg->cursor_texture_path, NULL);
    return slider->background_texture && slider->cursor_texture;
}

static bool create_slider_sprites(ui_slider_t *slider)
{
    slider->background_sprite = sfSprite_create();
    slider->cursor_sprite = sfSprite_create();
    return slider->background_sprite && slider->cursor_sprite;
}

static void set_slider_sprites(ui_slider_t *slider)
{
    sfSprite_setTexture(
        slider->background_sprite,
        slider->background_texture,
        sfTrue);
    sfSprite_setTexture(
        slider->cursor_sprite,
        slider->cursor_texture,
        sfTrue);
}

static void configure_slider(
    ui_slider_t *slider,
    const ui_slider_config_t *cfg)
{
    slider->rect = cfg->rect;
    slider->zero_point = cfg->zero_point;
    slider->full_point = cfg->full_point;
    slider->value = 0.f;
    slider->on_change = cfg->on_change;
    slider->user_data = cfg->user_data;
    slider->cursor_box = cfg->cursor_box;
}

static void setup_methods(ui_widget_t *widget)
{
    widget->draw = ui_slider_draw;
    widget->handle_event = ui_slider_handle_event;
    widget->destroy = ui_slider_destroy;
}

ui_widget_t *ui_slider_create(const ui_slider_config_t *cfg)
{
    ui_widget_t *widget = NULL;
    ui_slider_t *slider = NULL;

    if (!allocate_widget_and_data(&widget, &slider))
        return NULL;
    if (!load_slider_textures(slider, cfg)) {
        ui_slider_destroy(widget);
        return NULL;
    }
    if (!create_slider_sprites(slider)) {
        ui_slider_destroy(widget);
        return NULL;
    }
    set_slider_sprites(slider);
    configure_slider(slider, cfg);
    widget->data = slider;
    setup_methods(widget);
    return widget;
}
