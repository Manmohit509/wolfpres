/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** textbox
*/

#ifndef UI_TEXTBOX_H
    #define UI_TEXTBOX_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "ui/widget.h"
    #include "ui/geometry.h"

typedef void (*textbox_submit_callback_t)(const char *text, void *user_data);

typedef struct {
    ui_rect_t rect;
    sfVector2f text_offset;
    const char *default_text;
    sfColor default_text_color;
    const char *bg_texture_path;
    const char *font_path;
    size_t max_chars;
    textbox_submit_callback_t on_submit;
    void *user_data;
} ui_textbox_config_t;

typedef struct {
    ui_rect_t rect;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfVector2f text_offset;

    char *default_text;
    sfColor default_text_color;
    sfText *text;
    sfFont *font;
    sfColor text_color;
    size_t max_chars;

    char *buffer;
    size_t buffer_len;

    bool active;
    textbox_submit_callback_t on_submit;
    void *user_data;
    sfFloatRect abs_rect;
} ui_textbox_t;

ui_widget_t *ui_textbox_create(ui_textbox_config_t const *cfg);
void ui_textbox_destroy(ui_widget_t *widget);
void ui_textbox_draw(ui_widget_t *widget, sfRenderTexture *target);
void ui_textbox_handle_event(
    ui_widget_t *widget,
    sfEvent *event,
    sfRenderTexture *target
);

#endif /* UI_TEXTBOX_H */
