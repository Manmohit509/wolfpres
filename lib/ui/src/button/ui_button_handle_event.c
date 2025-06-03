/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_button_handle_event
*/

#include "ui/button.h"

static void handle_mouse_moved(ui_button_t *btn, sfEvent *event)
{
    sfVector2i mouse = {event->mouseMove.x, event->mouseMove.y};

    btn->hovered = sfFloatRect_contains(&btn->abs_rect, mouse.x, mouse.y);
}

static void handle_mouse_button_pressed(ui_button_t *btn, sfEvent *event)
{
    sfVector2i mouse = {event->mouseButton.x, event->mouseButton.y};

    if (event->mouseButton.button == sfMouseLeft) {
        btn->pressed = sfFloatRect_contains(&btn->abs_rect, mouse.x, mouse.y);
    }
}

static void handle_mouse_button_released(ui_button_t *btn, sfEvent *event)
{
    sfVector2i mouse = {event->mouseButton.x, event->mouseButton.y};

    if (event->mouseButton.button == sfMouseLeft) {
        if (btn->pressed && sfFloatRect_contains(&btn->abs_rect,
            mouse.x, mouse.y) && btn->on_click)
            btn->on_click(btn->user_data);
        btn->pressed = false;
    }
}

void ui_button_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target)
{
    ui_button_t *btn = self->data;

    btn->abs_rect = ui_rect_to_pixels(btn->rect, target);
    if (event->type == sfEvtMouseMoved) {
        handle_mouse_moved(btn, event);
    }
    if (event->type == sfEvtMouseButtonPressed) {
        handle_mouse_button_pressed(btn, event);
    }
    if (event->type == sfEvtMouseButtonReleased) {
        handle_mouse_button_released(btn, event);
    }
}
