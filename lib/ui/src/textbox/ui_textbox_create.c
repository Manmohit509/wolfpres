/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_textbox_create
*/

#include <stdlib.h>
#include <string.h>

#include "ui/textbox.h"

static int config_background(
    ui_textbox_t *textbox,
    ui_textbox_config_t const *cfg)
{
    textbox->rect = cfg->rect;
    textbox->background_texture = sfTexture_createFromFile(
        cfg->bg_texture_path,
        NULL);
    if (textbox->background_texture == NULL) {
        return EXIT_FAILURE;
    }
    textbox->background_sprite = sfSprite_create();
    if (textbox->background_sprite == NULL) {
        return EXIT_FAILURE;
    }
    sfSprite_setTexture(textbox->background_sprite,
        textbox->background_texture,
        sfTrue);
    return EXIT_SUCCESS;
}

static int config_text(
    ui_textbox_t *textbox,
    ui_textbox_config_t const *cfg)
{
    textbox->font = sfFont_createFromFile(cfg->font_path);
    if (textbox->font == NULL) {
        return EXIT_FAILURE;
    }
    textbox->text = sfText_create();
    if (textbox->text == NULL) {
        return EXIT_FAILURE;
    }
    sfText_setFont(textbox->text, textbox->font);
    sfText_setFillColor(textbox->text, sfWhite);
    textbox->text_offset = cfg->text_offset;
    textbox->default_text_color = cfg->default_text_color;
    textbox->default_text = cfg->default_text ?
        strdup(cfg->default_text) : NULL;
    return EXIT_SUCCESS;
}

static int config_buffer(
    ui_textbox_t *textbox,
    ui_textbox_config_t const *cfg)
{
    textbox->text_color = sfWhite;
    textbox->max_chars = cfg->max_chars;
    textbox->buffer = calloc(cfg->max_chars + 1, sizeof(char));
    if (textbox->buffer == NULL) {
        return EXIT_FAILURE;
    }
    textbox->on_submit = cfg->on_submit;
    textbox->user_data = cfg->user_data;
    return EXIT_SUCCESS;
}

static void setup_methods(ui_widget_t *widget)
{
    widget->draw = ui_textbox_draw;
    widget->handle_event = ui_textbox_handle_event;
    widget->destroy = ui_textbox_destroy;
}

ui_widget_t *ui_textbox_create(ui_textbox_config_t const *cfg)
{
    ui_widget_t *widget = malloc(sizeof(ui_widget_t));
    ui_textbox_t *textbox = NULL;

    if (widget == NULL)
        return NULL;
    textbox = calloc(1, sizeof(ui_textbox_t));
    if (textbox == NULL) {
        free(widget);
        return NULL;
    }
    widget->data = textbox;
    setup_methods(widget);
    if (config_background(textbox, cfg) != EXIT_SUCCESS ||
        config_text(textbox, cfg) != EXIT_SUCCESS ||
        config_buffer(textbox, cfg) != EXIT_SUCCESS) {
        ui_textbox_destroy(widget);
        return NULL;
    }
    return widget;
}
