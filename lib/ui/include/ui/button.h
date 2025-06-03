/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** button
*/

#ifndef UI_BUTTON_H
    #define UI_BUTTON_H

    #include <stdbool.h>

    #include "ui/widget.h"
    #include "ui/geometry.h"

typedef struct ui_button_s {
    ui_rect_t rect;
    sfFloatRect abs_rect; // cache
    sfColor bg_color;
    sfText *label;
    sfFont *font;
    sfColor text_color;

    void (*on_click)(void *user_data);
    void *user_data;

    bool hovered;
    bool pressed;
} ui_button_t;


// create a widget with the button data inside
ui_widget_t *ui_button_create(
    char const *label_text,
    ui_rect_t rect,
    void (*on_click)(void *),
    void *user_data
);
void ui_button_draw(ui_widget_t *self, sfRenderTexture *target);
void ui_button_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target);

// destroy the widget and the data contained
void ui_button_destroy(ui_widget_t *widget);

#endif /* UI_BUTTON_H */
