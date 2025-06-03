/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** register_create_game_page
*/

#include "ui/ui.h"
#include "wolf3d.h"
#include "render/pages.h"

static ui_widget_t *create_name_textbox(process_t *process)
{
    ui_textbox_config_t cfg = world_name_text_box_cfg;
    ui_widget_t *textbox = NULL;

    cfg.user_data = process;
    textbox = ui_textbox_create(&cfg);
    return textbox;
}

//todo implement difficulty on game creation
static ui_widget_t *create_difficulty_textbox(process_t *process)
{
    (void) process;
    return NULL;
}

static int add_go_back_button(ui_page_t *page, process_t *process)
{
    ui_widget_t *world_name = create_name_textbox(process);
    ui_widget_t *go_back = ui_image_button_create(&go_back_btn_cfg);
    ui_widget_t *array[] = {world_name, go_back};
    ui_layout_config_t cfg = {
        .widgets = array,
        .count = 2,
        .padding_y = 0.04f,
        .align_y = UI_ALIGN_MIDDLE,
        .rect = {0.0f, 0.2f, 0.3f, 0.7f},
        .use_fixed_size = false
    };

    setup_widget_data(go_back, process);
    ui_layout_col(page, &cfg);
    return world_name && go_back ? SUCCESS_EXIT : FAILURE_EXIT;
}

int register_create_game_page(process_t *process)
{
    ui_page_t *page = ui_page_create();

    if (!page) {
        return FAILURE_EXIT;
    }
    create_difficulty_textbox(process);
    ui_app_add_page(process->app, "create_game", page);
    if (add_default_menu(page) != SUCCESS_EXIT ||
        add_go_back_button(page, process) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
