/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** add_default_menu
*/

#include "render/pages.h"
#include "wolf3d.h"

static int add_bg_widget(ui_page_t *page)
{
    ui_rect_t proportions = {0.0f, 0.0f, 1.0f, 1.0f};
    image_display_mode_t mode = IMAGE_MODE_UPSCALE;
    ui_widget_t *w = ui_image_fill_create(
        "./assets/gui/bg.png",
        proportions,
        mode);

    if (w == NULL) {
        return FAILURE_EXIT;
    }
    ui_page_add_widget(page, w);
    return SUCCESS_EXIT;
}

static int add_title_widget(ui_page_t *page)
{
    ui_rect_t proportions = {0.5f, 0.0f, 0.5f, 0.2};
    image_display_mode_t mode = IMAGE_MODE_SCALE;
    ui_widget_t *w = ui_image_fill_create(
        "./assets/gui/title.png",
        proportions,
        mode);

    if (w == NULL) {
        return FAILURE_EXIT;
    }
    ui_page_add_widget(page, w);
    return SUCCESS_EXIT;
}

int add_default_menu(ui_page_t *page)
{
    if (add_bg_widget(page) != SUCCESS_EXIT ||
        add_title_widget(page) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
