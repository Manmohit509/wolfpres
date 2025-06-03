/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** enum_selector
*/

#ifndef UI_ENUM_SELECTOR_H
    #define UI_ENUM_SELECTOR_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "ui/widget.h"
    #include "ui/geometry.h"

typedef struct {
    const char *value;
    const char *texture_off;
    const char *texture_on;
    const char *texture_hover;
} enum_entry_t;

typedef void (*enum_selector_callback_t)(
    const char *value, int index, void *user_data
);

typedef struct {
    ui_rect_t rect;
    enum_entry_t const *entries;
    int entry_count;
    enum_selector_callback_t on_change;
    void *user_data;
} ui_enum_selector_config_t;

typedef struct {
    ui_rect_t rect;
    enum_entry_t const *entries;
    int entry_count;

    int current_index;
    sfTexture **textures_off;
    sfTexture **textures_on;
    sfTexture **textures_hover;
    sfSprite *sprite;

    bool hovered;
    bool pressed;

    enum_selector_callback_t on_change;
    void *user_data;

    sfFloatRect abs_rect;
} ui_enum_selector_t;

ui_widget_t *ui_enum_selector_create(ui_enum_selector_config_t const *cfg);
void ui_enum_selector_destroy(ui_widget_t *widget);
void ui_enum_selector_draw(ui_widget_t *widget, sfRenderTexture *target);
void ui_enum_selector_handle_event(
    ui_widget_t *widget,
    sfEvent *event,
    sfRenderTexture *target
);

#endif /* UI_ENUM_SELECTOR_H */
