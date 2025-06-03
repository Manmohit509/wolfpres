/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_enum_selector_draw
*/

#include "ui/enum_selector.h"

static sfTexture *get_texture_for_state(ui_enum_selector_t *selector)
{
    int i = selector->current_index;

    if (selector->pressed)
        return selector->textures_on[i];
    if (selector->hovered)
        return selector->textures_hover[i];
    return selector->textures_off[i];
}

static sfVector2f get_scaled_size(sfVector2u tex_size, sfFloatRect rect)
{
    float scale_x = rect.width / (float)tex_size.x;
    float scale_y = rect.height / (float)tex_size.y;
    float scale = (scale_x < scale_y) ? scale_x : scale_y;

    return (sfVector2f){
        tex_size.x * scale,
        tex_size.y * scale
    };
}

static sfVector2f get_centered_position(sfVector2f size, sfFloatRect rect)
{
    return (sfVector2f){
        rect.left + (rect.width - size.x) / 2.f,
        rect.top + (rect.height - size.y) / 2.f
    };
}

void ui_enum_selector_draw(ui_widget_t *widget, sfRenderTexture *target)
{
    ui_enum_selector_t *selector = widget->data;
    sfFloatRect abs_rect = ui_rect_to_pixels(selector->rect, target);
    sfTexture *tex = get_texture_for_state(selector);
    sfVector2u tex_size = sfTexture_getSize(tex);
    sfVector2f scaled = get_scaled_size(tex_size, abs_rect);
    sfVector2f pos = get_centered_position(scaled, abs_rect);

    selector->abs_rect = abs_rect;
    sfSprite_setTexture(selector->sprite, tex, sfTrue);
    sfSprite_setScale(selector->sprite,
        (sfVector2f){scaled.x / tex_size.x, scaled.y / tex_size.y});
    sfSprite_setPosition(selector->sprite, pos);
    sfRenderTexture_drawSprite(target, selector->sprite, NULL);
}
