/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_enum_selector_handle_event
*/

#include "ui/enum_selector.h"

static void handle_mouse_move(ui_enum_selector_t *selector, sfEvent *event)
{
    sfVector2f mouse = {event->mouseMove.x, event->mouseMove.y};

    selector->hovered = sfFloatRect_contains(
        &selector->abs_rect, mouse.x, mouse.y);
}

static void handle_mouse_pressed(ui_enum_selector_t *selector, sfEvent *event)
{
    sfVector2f mouse = {event->mouseButton.x, event->mouseButton.y};

    if (event->mouseButton.button != sfMouseLeft)
        return;
    selector->pressed = sfFloatRect_contains(
        &selector->abs_rect, mouse.x, mouse.y);
}

static void handle_mouse_released(ui_enum_selector_t *selector, sfEvent *event)
{
    sfVector2f mouse = {event->mouseButton.x, event->mouseButton.y};
    bool was_pressed = selector->pressed;

    if (event->mouseButton.button != sfMouseLeft)
        return;
    selector->pressed = false;
    if (!was_pressed)
        return;
    if (!sfFloatRect_contains(&selector->abs_rect, mouse.x, mouse.y))
        return;
    selector->current_index = (selector->current_index + 1) %
        selector->entry_count;
    if (selector->on_change) {
        selector->on_change(
            selector->entries[selector->current_index].value,
            selector->current_index,
            selector->user_data
        );
    }
}

void ui_enum_selector_handle_event(
    ui_widget_t *widget,
    sfEvent *event,
    sfRenderTexture *target)
{
    ui_enum_selector_t *selector = widget->data;

    (void)target;
    if (event->type == sfEvtMouseMoved)
        handle_mouse_move(selector, event);
    if (event->type == sfEvtMouseButtonPressed)
        handle_mouse_pressed(selector, event);
    if (event->type == sfEvtMouseButtonReleased)
        handle_mouse_released(selector, event);
}
