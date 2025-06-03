/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** widget
*/

#ifndef UI_WIDGET_H
    #define UI_WIDGET_H

    #include <SFML/Graphics.h>

typedef struct ui_widget_s ui_widget_t;

// function type executed to draw the widget
typedef void (*ui_widget_draw_func_t)(
    ui_widget_t *self,
    sfRenderTexture *target);
// function type executed to handle the widget interactions
typedef void (*ui_widget_event_func_t)(ui_widget_t *self, sfEvent *event,
    sfRenderTexture *target);
// function to destroy the widget and the data contained inside
typedef void (*ui_widget_destroy_func_t)(ui_widget_t *self);

struct ui_widget_s {
    sfVector2f pos;
    ui_widget_draw_func_t draw;
    ui_widget_event_func_t handle_event;
    ui_widget_destroy_func_t destroy;
    void *data; // specific data (ex: button_t*, slider_t*)
};

void ui_widget_draw(ui_widget_t *self, sfRenderTexture *target);
void ui_widget_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target);
void ui_widget_debug_outline(
    ui_widget_t *self,
    sfRenderTexture *target,
    sfColor color);

void ui_widget_destroy(ui_widget_t *self);

#endif /* UI_WIDGET_H */
