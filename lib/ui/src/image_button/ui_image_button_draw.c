/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** image_button_draw
*/

#include "ui/image_button.h"

static sfTexture *get_current_texture(ui_image_button_t *btn)
{
    sfTexture *texture = btn->texture_default;

    if (btn->pressed && btn->texture_pressed)
        texture = btn->texture_pressed;
    else if (btn->hovered && btn->texture_hover)
        texture = btn->texture_hover;
    return texture;
}

static void internal_draw(ui_image_button_t *btn, sfRenderTexture *target)
{
    sfFloatRect area = ui_rect_to_pixels(btn->rect, target);
    sfTexture *texture = get_current_texture(btn);
    sfVector2u size = sfTexture_getSize(texture);
    float aspect = (float)size.x / (float)size.y;
    float w = area.width;
    float h = w / aspect;
    float x = 0;
    float y = 0;

    if (h > area.height) {
        h = area.height;
        w = h * aspect;
    }
    x = area.left + (area.width - w) / 2.0f;
    y = area.top + (area.height - h) / 2.0f;
    btn->abs_rect = (sfFloatRect){x, y, w, h};
    sfSprite_setTexture(btn->sprite, texture, sfTrue);
    sfSprite_setPosition(btn->sprite, (sfVector2f){x, y});
    sfSprite_setScale(btn->sprite, (sfVector2f){w / size.x, h / size.y});
    sfRenderTexture_drawSprite(target, btn->sprite, NULL);
}

void ui_image_button_draw(ui_widget_t *self, sfRenderTexture *target)
{
    ui_image_button_t *btn = self->data;

    if (!btn || !target)
        return;
    internal_draw(btn, target);
}
