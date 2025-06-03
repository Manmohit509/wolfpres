/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** image_button_handle_event
*/

#include "ui/image_button.h"

static void handle_mouse_moved(ui_image_button_t *btn, sfEvent *event)
{
    sfVector2i mouse = {event->mouseMove.x, event->mouseMove.y};
    sfFloatRect bounds = sfSprite_getGlobalBounds(btn->sprite);

    btn->hovered = sfFloatRect_contains(&bounds, mouse.x, mouse.y);
}

static void handle_mouse_button_pressed(ui_image_button_t *btn, sfEvent *event)
{
    sfVector2i mouse = {event->mouseButton.x, event->mouseButton.y};
    sfFloatRect bounds = sfSprite_getGlobalBounds(btn->sprite);

    if (event->mouseButton.button == sfMouseLeft) {
        btn->pressed = sfFloatRect_contains(&bounds, mouse.x, mouse.y);
    }
}

static void handle_mouse_button_released(
    ui_image_button_t *btn,
    sfEvent *event)
{
    sfVector2i mouse = {event->mouseButton.x, event->mouseButton.y};
    sfFloatRect bounds = sfSprite_getGlobalBounds(btn->sprite);

    if (event->mouseButton.button == sfMouseLeft) {
        if (btn->pressed && sfFloatRect_contains(&bounds,
            mouse.x, mouse.y) && btn->on_click)
            btn->on_click(btn->user_data);
        btn->pressed = false;
    }
}

void ui_image_button_handle_event(
    ui_widget_t *self,
    sfEvent *event,
    sfRenderTexture *target)
{
    ui_image_button_t *btn = self->data;

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
