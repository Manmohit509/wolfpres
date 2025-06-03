/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_textbox_handle_event
*/

#include "ui/textbox.h"

static void textbox_update_display(ui_textbox_t *textbox)
{
    sfText_setString(textbox->text, textbox->buffer);
}

static void textbox_on_text_entered(ui_textbox_t *textbox, sfEvent *event)
{
    if (event->text.unicode < 32 || event->text.unicode == 127)
        return;
    if (textbox->buffer_len + 1 >= textbox->max_chars)
        return;
    textbox->buffer[textbox->buffer_len] = (char)event->text.unicode;
    textbox->buffer_len++;
    textbox->buffer[textbox->buffer_len] = '\0';
    textbox_update_display(textbox);
}

static void textbox_on_key_pressed(ui_textbox_t *textbox, sfEvent *event)
{
    if (event->key.code == sfKeyReturn && textbox->on_submit) {
        textbox->on_submit(textbox->buffer, textbox->user_data);
        textbox->buffer[0] = '\0';
        textbox->buffer_len = 0;
        textbox_update_display(textbox);
    }
    if (event->key.code == sfKeyBackspace && textbox->buffer_len > 0) {
        textbox->buffer_len--;
        textbox->buffer[textbox->buffer_len] = '\0';
        textbox_update_display(textbox);
    }
}

void ui_textbox_handle_event(
    ui_widget_t *widget,
    sfEvent *event,
    sfRenderTexture *target)
{
    ui_textbox_t *textbox = widget->data;

    (void) target;
    if (event->type == sfEvtMouseButtonPressed) {
        textbox->active = sfFloatRect_contains(&textbox->abs_rect,
            event->mouseButton.x, event->mouseButton.y);
    }
    if (!textbox->active)
        return;
    if (event->type == sfEvtTextEntered)
        textbox_on_text_entered(textbox, event);
    if (event->type == sfEvtKeyPressed)
        textbox_on_key_pressed(textbox, event);
}
