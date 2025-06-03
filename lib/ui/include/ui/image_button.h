/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** button
*/

#ifndef UI_IMAGE_BUTTON_H
    #define UI_IMAGE_BUTTON_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "ui/widget.h"
    #include "ui/geometry.h"

typedef struct ui_image_button_config_s {
    char const *texture_normal;
    char const *texture_hover;
    char const *texture_pressed;
    ui_rect_t rect;
    void (*on_click)(void *user_data);
    void *user_data;
} ui_image_button_config_t;

typedef struct ui_image_button_s {
    ui_rect_t rect;             // max area
    sfTexture *texture_default;
    sfTexture *texture_hover;
    sfTexture *texture_pressed;
    sfSprite *sprite;
    sfFloatRect abs_rect;       // draw area (after scaling)
    float aspect_ratio;         // texture ratio
    void (*on_click)(void *user_data);
    void *user_data;
    bool hovered;
    bool pressed;
} ui_image_button_t;

ui_widget_t *ui_image_button_create(ui_image_button_config_t const *cfg);

void ui_image_button_destroy(ui_widget_t *widget);
void ui_image_button_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target);
void ui_image_button_draw(ui_widget_t *self, sfRenderTexture *target);

#endif /* UI_IMAGE_BUTTON_H */
