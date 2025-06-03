/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_image_fill_draw
*/

#include <math.h>

#include "ui/image_fill.h"

static void handle_stretch_size(
    sfVector2f *size,
    sfVector2f *pos,
    sfFloatRect area)
{
    size->x = area.width;
    size->y = area.height;
    pos->x = area.left;
    pos->y = area.top;
}

static void handle_scale_size(
    sfVector2f *size,
    sfVector2f *pos,
    sfFloatRect area,
    sfVector2u tex_size)
{
    sfVector2f scale_r = {
        area.width / (float) tex_size.x,
        area.height / (float) tex_size.y
    };
    float scale = fminf(scale_r.x, scale_r.y);

    size->x = (float) tex_size.x * scale;
    size->y = (float) tex_size.y * scale;
    pos->x = area.left + (area.width - size->x) / 2.0f;
    pos->y = area.top;
}

static void handle_upscale_size(
    sfVector2f *size,
    sfVector2f *pos,
    sfFloatRect area,
    sfVector2u tex_size)
{
    sfVector2f scale_r = {
        area.width / (float) tex_size.x,
        area.height / (float) tex_size.y
    };
    float scale = fmaxf(scale_r.x, scale_r.y);

    size->x = (float) tex_size.x * scale;
    size->y = (float) tex_size.y * scale;
    pos->x = area.left + (area.width - size->x) / 2.0f;
    pos->y = area.top;
}

static void setup_scale(sfSprite *sprite, sfVector2f size, sfVector2u tex_size)
{
    sfSprite_setScale(sprite, (sfVector2f){
        size.x / (float) tex_size.x,
        size.y / (float) tex_size.y
    });
}

void ui_image_fill_draw(ui_widget_t *widget, sfRenderTexture *target)
{
    ui_image_fill_t *img = widget->data;
    sfFloatRect area = ui_rect_to_pixels(img->rect, target);
    sfVector2u tex_size = sfTexture_getSize(img->texture);
    sfVector2f size = {0};
    sfVector2f pos = {0};

    if (img->mode == IMAGE_MODE_SCALE)
        handle_scale_size(&size, &pos, area, tex_size);
    if (img->mode == IMAGE_MODE_STRETCH)
        handle_stretch_size(&size, &pos, area);
    if (img->mode == IMAGE_MODE_UPSCALE)
        handle_upscale_size(&size, &pos, area, tex_size);
    img->abs_rect = (sfFloatRect){pos.x, pos.y, size.x, size.y};
    sfSprite_setPosition(img->sprite, pos);
    setup_scale(img->sprite, size, tex_size);
    sfRenderTexture_drawSprite(target, img->sprite, NULL);
}
