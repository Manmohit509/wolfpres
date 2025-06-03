/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** slider
*/

#ifndef UI_SLIDER_H
    #define UI_SLIDER_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "ui/widget.h"
    #include "ui/geometry.h"

typedef void (*ui_slider_callback_t)(float value, void *user_data);

typedef struct {
    ui_rect_t rect;
    const char *background_texture_path;
    const char *cursor_texture_path;
    sfVector2f zero_point;
    sfVector2f full_point;
    sfFloatRect cursor_box;
    ui_slider_callback_t on_change;
    void *user_data;
} ui_slider_config_t;

typedef struct {
    ui_rect_t rect;
    sfFloatRect abs_rect;

    sfTexture *background_texture;
    sfSprite *background_sprite;

    sfTexture *cursor_texture;
    sfSprite *cursor_sprite;
    sfFloatRect cursor_box;
    sfVector2f zero_point;
    sfVector2f full_point;

    bool dragging;
    float value;

    ui_slider_callback_t on_change;
    void *user_data;
} ui_slider_t;

ui_widget_t *ui_slider_create(const ui_slider_config_t *cfg);
void ui_slider_destroy(ui_widget_t *widget);
void ui_slider_draw(ui_widget_t *widget, sfRenderTexture *target);
void ui_slider_handle_event(
    ui_widget_t *widget,
    sfEvent *event,
    sfRenderTexture *target);

#endif /* UI_SLIDER_H */
