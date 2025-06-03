/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_button_create
*/

#include <stdlib.h>
#include "ui/button.h"

static void configure_button(
    ui_button_t *btn,
    ui_rect_t rect,
    void (*on_click)(void *),
    void *user_data)
{
    btn->rect = rect;
    btn->on_click = on_click;
    btn->user_data = user_data;
    btn->bg_color = sfColor_fromRGB(50, 50, 200);
    btn->text_color = sfWhite;
    sfText_setFont(btn->label, btn->font);
    sfText_setCharacterSize(btn->label, 24);
    sfText_setFillColor(btn->label, btn->text_color);
}

static void configure_widget(ui_widget_t *widget, ui_button_t *button)
{
    widget->data = button;
    widget->draw = ui_button_draw;
    widget->handle_event = ui_button_handle_event;
    widget->destroy = ui_button_destroy;
}

ui_widget_t *ui_button_create(
    char const *label_text,
    ui_rect_t rect,
    void (*on_click)(void *),
    void *user_data)
{
    ui_button_t *btn = calloc(1, sizeof(ui_button_t));
    ui_widget_t *w = NULL;

    if (!btn)
        return NULL;
    w = calloc(1, sizeof(ui_widget_t));
    if (!w) {
        free(btn);
        return w;
    }
    configure_widget(w, btn);
    btn->font = sfFont_createFromFile("assets/font.ttf");
    btn->label = sfText_create();
    if (!btn->font || !btn->label) {
        ui_widget_destroy(w);
        return NULL;
    }
    configure_button(btn, rect, on_click, user_data);
    sfText_setString(btn->label, label_text);
    return w;
}
