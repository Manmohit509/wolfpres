/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** image_fill
*/

#ifndef UI_IMAGE_FILL_WIDGET_H
    #define UI_IMAGE_FILL_WIDGET_H

    #include "ui/widget.h"
    #include "ui/geometry.h"

typedef enum {
    IMAGE_MODE_SCALE,
    IMAGE_MODE_STRETCH,
    IMAGE_MODE_UPSCALE
} image_display_mode_t;

typedef struct {
    ui_rect_t rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfFloatRect abs_rect;
    image_display_mode_t mode;
} ui_image_fill_t;

ui_widget_t *ui_image_fill_create(
    const char *texture_path,
    ui_rect_t rect,
    image_display_mode_t mode
);

void ui_image_fill_destroy(ui_widget_t *widget);
void ui_image_fill_draw(ui_widget_t *widget, sfRenderTexture *target);

#endif /* UI_IMAGE_FILL_WIDGET_H */
