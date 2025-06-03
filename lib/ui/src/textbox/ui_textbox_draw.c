/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_textbox_draw
*/

#include "ui/textbox.h"

static void setup_sprite_propertions(
    ui_textbox_t *textbox)
{
    sfVector2u tex_size = sfTexture_getSize(textbox->background_texture);
    float scale_x = textbox->abs_rect.width / tex_size.x;
    float scale_y = textbox->abs_rect.height / tex_size.y;
    float scale = (scale_x < scale_y) ? scale_x : scale_y;
    sfVector2f sprite_size = {tex_size.x * scale, tex_size.y * scale};
    sfVector2f sprite_pos = {textbox->abs_rect.left +
            (textbox->abs_rect.width - sprite_size.x) / 2.0f,
        textbox->abs_rect.top +
            (textbox->abs_rect.height - sprite_size.y) / 2.0f};
    sfVector2f text_pos = {
        sprite_pos.x + sprite_size.x * textbox->text_offset.x,
        sprite_pos.y + sprite_size.y * textbox->text_offset.y};
    unsigned int char_size = sprite_size.y * 0.4f;

    sfText_setCharacterSize(textbox->text, char_size);
    sfText_setPosition(textbox->text, text_pos);
    sfSprite_setScale(textbox->background_sprite, (sfVector2f){scale, scale});
    sfSprite_setPosition(textbox->background_sprite, sprite_pos);
}

static void setup_text_theme(ui_textbox_t *textbox)
{
    const char *string_to_draw = textbox->buffer[0] == '\0' && !textbox->active
    ? textbox->default_text
    : textbox->buffer;
    sfColor color_to_use = textbox->buffer[0] == '\0' && !textbox->active
        ? textbox->default_text_color
        : textbox->text_color;

    sfText_setString(textbox->text, string_to_draw);
    sfText_setFillColor(textbox->text, color_to_use);
}

void ui_textbox_draw(ui_widget_t *widget, sfRenderTexture *target)
{
    ui_textbox_t *textbox = widget->data;

    textbox->abs_rect = ui_rect_to_pixels(textbox->rect, target);
    setup_sprite_propertions(textbox);
    sfRenderTexture_drawSprite(target, textbox->background_sprite, NULL);
    setup_text_theme(textbox);
    sfRenderTexture_drawText(target, textbox->text, NULL);
}
