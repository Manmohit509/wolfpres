/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** register_main_page
*/

#include "wolf3d.h"
#include "render/pages.h"

static int add_buttons_bar_widgets(ui_page_t *page, process_t *process)
{
    ui_widget_t *singleplayer = ui_image_button_create(&singleplayer_btn_cfg);
    ui_widget_t *multiplayer = ui_image_button_create(&multiplayer_btn_cfg);
    ui_widget_t *settings = ui_image_button_create(&settings_btn_cfg);
    ui_widget_t *credits = ui_image_button_create(&credits_btn_cfg);
    ui_widget_t *exit = ui_image_button_create(&exit_btn_cfg);
    ui_widget_t *array[] = {singleplayer, multiplayer, settings, credits,
        exit};
    ui_layout_config_t cfg = {
        .widgets = array,
        .count = 5,
        .padding_y = 0.04f,
        .align_y = UI_ALIGN_MIDDLE,
        .rect = {0.0f, 0.2f, 0.3f, 0.7f},
        .use_fixed_size = true
    };

    setup_widgets_data(array, 5, process);
    ui_layout_col(page, &cfg);
    return singleplayer && multiplayer && settings && credits && exit
        ? SUCCESS_EXIT : FAILURE_EXIT;
}

int register_main_page(process_t *process)
{
    ui_page_t *page = ui_page_create();

    if (!page) {
        return FAILURE_EXIT;
    }
    ui_app_add_page(process->app, "main", page);
    if (add_default_menu(page) != SUCCESS_EXIT ||
        add_buttons_bar_widgets(page, process) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
