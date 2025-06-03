/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** register_singleplayer_page
*/

#include "wolf3d.h"
#include "render/pages.h"

static int add_buttons_bar_widgets(ui_page_t *page, process_t *process)
{
    ui_widget_t *load_game = ui_image_button_create(&load_game_btn_cfg);
    ui_widget_t *create_game = ui_image_button_create(&create_game_btn_cfg);
    ui_widget_t *go_back = ui_image_button_create(&go_back_btn_cfg);
    ui_widget_t *array[] = {
        load_game, create_game, go_back};
    ui_layout_config_t cfg = {
        .widgets = array,
        .count = 3,
        .padding_y = 0.05f,
        .align_y = UI_ALIGN_TOP,
        .rect = {0.0f, 0.2f, 0.3f, 0.7f},
        .use_fixed_size = true
    };

    setup_widgets_data(array, 3, process);
    ui_layout_col(page, &cfg);
    return load_game && create_game && go_back
        ? SUCCESS_EXIT : FAILURE_EXIT;
}

int register_singleplayer_page(process_t *process)
{
    ui_page_t *page = ui_page_create();

    if (!page) {
        return FAILURE_EXIT;
    }
    ui_app_add_page(process->app, "singleplayer", page);
    if (add_default_menu(page) != SUCCESS_EXIT ||
        add_buttons_bar_widgets(page, process) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
        }
    return SUCCESS_EXIT;
}
