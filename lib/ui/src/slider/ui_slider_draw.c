/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_slider_draw
*/

#include "ui/slider.h"
#include "ui/geometry.h"

static void update_abs_rect(ui_slider_t *s, sfRenderTexture *target)
{
    s->abs_rect = ui_rect_to_pixels(s->rect, target);
}

static float compute_uniform_scale(sfVector2f area, sfVector2u texture_size)
{
    float scale_x = area.x / (float)texture_size.x;
    float scale_y = area.y / (float)texture_size.y;

    return (scale_x < scale_y) ? scale_x : scale_y;
}

static sfVector2f compute_sprite_position(sfFloatRect area, sfVector2f size)
{
    return (sfVector2f){
        area.left + (area.width - size.x) / 2.f,
        area.top + (area.height - size.y) / 2.f
    };
}

static void draw_background_sprite(
    ui_slider_t *s,
    sfRenderTexture *target,
    sfVector2f *out_sprite_pos,
    sfVector2f *out_sprite_size)
{
    sfVector2u tex_size = sfTexture_getSize(s->background_texture);
    float scale = compute_uniform_scale(
        (sfVector2f){s->abs_rect.width, s->abs_rect.height}, tex_size);
    sfVector2f size = compute_sprite_size(tex_size, scale);
    sfVector2f pos = compute_sprite_position(s->abs_rect, size);

    sfSprite_setTexture(s->background_sprite, s->background_texture, sfTrue);
    sfSprite_setScale(s->background_sprite, (sfVector2f){scale, scale});
    sfSprite_setPosition(s->background_sprite, pos);
    sfRenderTexture_drawSprite(target, s->background_sprite, NULL);
    *out_sprite_pos = pos;
    *out_sprite_size = size;
}

static sfVector2f compute_slider_axis_point(
    sfVector2f origin,
    sfVector2f size,
    sfVector2f anchor)
{
    return (sfVector2f){
        origin.x + size.x * anchor.x,
        origin.y + size.y * anchor.y
    };
}

static sfFloatRect compute_cursor_box(
    sfVector2f pos,
    sfVector2f size,
    sfFloatRect relative)
{
    return (sfFloatRect){
        pos.x + size.x * relative.left,
        pos.y + size.y * relative.top,
        size.x * relative.width,
        size.y * relative.height
    };
}

static float compute_cursor_scale(sfVector2f box_size, sfVector2u tex_size)
{
    float sx = box_size.x / (float)tex_size.x;
    float sy = box_size.y / (float)tex_size.y;

    return (sx < sy) ? sx : sy;
}

static sfVector2f compute_centered_position(sfVector2f anchor, sfVector2f size)
{
    return (sfVector2f){
        anchor.x - size.x / 2.f,
        anchor.y - size.y / 2.f
    };
}

static void draw_cursor_sprite(
    ui_slider_t *s,
    sfRenderTexture *target,
    sfVector2f origin,
    sfVector2f size)
{
    sfVector2f point_zero =
        compute_slider_axis_point(origin, size, s->zero_point);
    sfVector2f point_full =
        compute_slider_axis_point(origin, size, s->full_point);
    sfVector2f cursor_pos = interpolate(point_zero, point_full, s->value);
    sfFloatRect box = compute_cursor_box(origin, size, s->cursor_box);
    sfVector2u tex_size = sfTexture_getSize(s->cursor_texture);
    float scale = compute_cursor_scale(
        (sfVector2f){box.width, box.height}, tex_size);
    sfVector2f final_size = compute_sprite_size(tex_size, scale);
    sfVector2f final_pos = compute_centered_position(cursor_pos, final_size);

    sfSprite_setTexture(s->cursor_sprite, s->cursor_texture, sfTrue);
    sfSprite_setScale(s->cursor_sprite, (sfVector2f){scale, scale});
    sfSprite_setPosition(s->cursor_sprite, final_pos);
    sfRenderTexture_drawSprite(target, s->cursor_sprite, NULL);
}

void ui_slider_draw(ui_widget_t *widget, sfRenderTexture *target)
{
    ui_slider_t *s = widget->data;
    sfVector2f sprite_pos = {0};
    sfVector2f sprite_size = {0};

    update_abs_rect(s, target);
    draw_background_sprite(s, target, &sprite_pos, &sprite_size);
    draw_cursor_sprite(s, target, sprite_pos, sprite_size);
}
