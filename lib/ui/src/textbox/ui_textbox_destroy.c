/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_textbox_destroy
*/

#include <stdlib.h>

#include "ui/textbox.h"

static void destroy_content(ui_textbox_t const *textbox)
{
    if (textbox->buffer)
        free(textbox->buffer);
    if (textbox->text)
        sfText_destroy(textbox->text);
    if (textbox->font)
        sfFont_destroy(textbox->font);
    if (textbox->background_sprite)
        sfSprite_destroy(textbox->background_sprite);
    if (textbox->background_sprite)
        sfTexture_destroy(textbox->background_texture);
    if (textbox->default_text)
        free(textbox->default_text);
}

void ui_textbox_destroy(ui_widget_t *widget)
{
    ui_textbox_t *textbox = NULL;

    if (!widget)
        return;
    textbox = widget->data;
    free(widget);
    if (!textbox)
        return;
    destroy_content(textbox);
    free(textbox);
}
