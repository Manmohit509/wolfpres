/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** ui_image_fill_create
*/

#include <stdlib.h>

#include "ui/image_fill.h"

static void *cleanup(
    ui_image_fill_t *img,
    ui_widget_t *w)
{
    if (img) {
        if (img->sprite)
            sfSprite_destroy(img->sprite);
        if (img->texture)
            sfTexture_destroy(img->texture);
        free(img);
    }
    if (w) {
        free(w);
    }
    return NULL;
}

static void setup_methods(ui_widget_t *w)
{
    w->draw = ui_image_fill_draw;
    w->handle_event = NULL;
    w->destroy = ui_image_fill_destroy;
}

ui_widget_t *ui_image_fill_create(
    const char *texture_path,
    ui_rect_t rect,
    image_display_mode_t mode)
{
    ui_image_fill_t *img = calloc(1, sizeof(ui_image_fill_t));
    ui_widget_t *w = calloc(1, sizeof(ui_widget_t));

    if (!img || !w)
        return cleanup(img, w);
    img->rect = rect;
    img->mode = mode;
    img->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!img->texture)
        return cleanup(img, w);
    img->sprite = sfSprite_create();
    if (!img->sprite)
        return cleanup(img, w);
    sfSprite_setTexture(img->sprite, img->texture, sfTrue);
    w->data = img;
    setup_methods(w);
    return w;
}
