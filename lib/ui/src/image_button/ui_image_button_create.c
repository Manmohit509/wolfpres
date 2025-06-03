/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** image_button_create
*/

#include <stdlib.h>
#include "ui/image_button.h"

static ui_widget_t *create_widget(
    ui_image_button_config_t const *cfg,
    ui_image_button_t *btn)
{
    sfVector2u tex_size = sfTexture_getSize(btn->texture_default);
    ui_widget_t *w = calloc(1, sizeof(ui_widget_t));

    if (!w) {
        sfTexture_destroy(btn->texture_default);
        sfTexture_destroy(btn->texture_hover);
        sfTexture_destroy(btn->texture_pressed);
        free(btn);
        return NULL;
    }
    btn->aspect_ratio = (float)tex_size.x / (float)tex_size.y;
    btn->on_click = cfg->on_click;
    btn->user_data = cfg->user_data;
    w->data = btn;
    w->draw = ui_image_button_draw;
    w->handle_event = ui_image_button_handle_event;
    w->destroy = ui_image_button_destroy;
    return w;
}

static bool setup_textures(
    ui_image_button_config_t const *cfg,
    ui_image_button_t *btn)
{
    btn->texture_default = sfTexture_createFromFile(cfg->texture_normal, NULL);
    if (!btn->texture_default) {
        return false;
    }
    btn->texture_hover = sfTexture_createFromFile(cfg->texture_hover, NULL);
    if (!btn->texture_hover) {
        sfTexture_destroy(btn->texture_default);
        return false;
    }
    btn->texture_pressed =
        sfTexture_createFromFile(cfg->texture_pressed, NULL);
    if (!btn->texture_pressed) {
        sfTexture_destroy(btn->texture_default);
        sfTexture_destroy(btn->texture_hover);
        return false;
    }
    sfSprite_setTexture(btn->sprite, btn->texture_default, sfTrue);
    return true;
}

static ui_widget_t *handle_internal_creation(
    ui_image_button_config_t const *cfg,
    ui_image_button_t *btn)
{
    btn->sprite = sfSprite_create();
    if (!btn->sprite) {
        free(btn);
        return NULL;
    }
    if (!setup_textures(cfg, btn)) {
        free(btn);
        return NULL;
    }
    return create_widget(cfg, btn);
}

ui_widget_t *ui_image_button_create(ui_image_button_config_t const *cfg)
{
    ui_image_button_t *btn = NULL;

    if (!cfg)
        return NULL;
    btn = calloc(1, sizeof(ui_image_button_t));
    if (!btn)
        return NULL;
    btn->rect = cfg->rect;
    return handle_internal_creation(cfg, btn);
}
