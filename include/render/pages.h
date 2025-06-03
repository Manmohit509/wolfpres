/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** pages
*/


#ifndef RENDER_PAGES_H
    #define RENDER_PAGES_H

    #include "ui/ui.h"
    #include "process.h"
    #include "callback.h"

int pages_register(process_t *process);

int register_main_page(process_t *process);
int register_singleplayer_page(process_t *process);
int register_load_game_page(process_t *process);
int register_create_game_page(process_t *process);
int register_settings_page(process_t *process);
int register_in_game_page(process_t *process);

int add_default_menu(ui_page_t *page);
void setup_widget_data(ui_widget_t *widget, void *data);
void setup_widgets_data(ui_widget_t **widget, int count, void *data);

static ui_rect_t const button_size = {0.02f, 0.0f, 0.3f, 0.1f};

static ui_image_button_config_t const singleplayer_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/singleplayer_hover.png",
    .texture_normal = "./assets/gui/buttons/singleplayer_off.png",
    .texture_pressed = "./assets/gui/buttons/singleplayer_on.png",
    .rect = button_size,
    .on_click = singleplayer_callback
};

static ui_image_button_config_t const multiplayer_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/multiplayer_hover.png",
    .texture_normal = "./assets/gui/buttons/multiplayer_off.png",
    .texture_pressed = "./assets/gui/buttons/multiplayer_on.png",
    .rect = button_size,
    .on_click = multiplayer_callback
};

static ui_image_button_config_t const settings_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/settings_hover.png",
    .texture_normal = "./assets/gui/buttons/settings_off.png",
    .texture_pressed = "./assets/gui/buttons/settings_on.png",
    .rect = button_size,
    .on_click = settings_callback
};

static ui_image_button_config_t const credits_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/credits_hover.png",
    .texture_normal = "./assets/gui/buttons/credits_off.png",
    .texture_pressed = "./assets/gui/buttons/credits_on.png",
    .rect = button_size
};

static ui_image_button_config_t const exit_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/exit_hover.png",
    .texture_normal = "./assets/gui/buttons/exit_off.png",
    .texture_pressed = "./assets/gui/buttons/exit_on.png",
    .rect = button_size,
    .on_click = exit_callback
};

static ui_image_button_config_t const go_back_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/go_back_hover.png",
    .texture_normal = "./assets/gui/buttons/go_back_off.png",
    .texture_pressed = "./assets/gui/buttons/go_back_on.png",
    .rect = button_size,
    .on_click = go_back_callback
};

static ui_image_button_config_t const create_game_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/create_game_hover.png",
    .texture_normal = "./assets/gui/buttons/create_game_off.png",
    .texture_pressed = "./assets/gui/buttons/create_game_on.png",
    .rect = button_size,
    .on_click = create_game_callback
};

static ui_image_button_config_t const load_game_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/load_game_hover.png",
    .texture_normal = "./assets/gui/buttons/load_game_off.png",
    .texture_pressed = "./assets/gui/buttons/load_game_on.png",
    .rect = button_size,
    .on_click = load_game_callback
};

static ui_image_button_config_t const right_arrow_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/right_arrow_hover.png",
    .texture_normal = "./assets/gui/buttons/right_arrow_off.png",
    .texture_pressed = "./assets/gui/buttons/right_arrow_on.png",
    .rect = {0.6, 0.8, 0.1, 0.1},
    .on_click = NULL
};

static ui_image_button_config_t const left_arrow_btn_cfg = {
    .texture_hover = "./assets/gui/buttons/left_arrow_hover.png",
    .texture_normal = "./assets/gui/buttons/left_arrow_off.png",
    .texture_pressed = "./assets/gui/buttons/left_arrow_on.png",
    .rect = {0.3, 0.8, 0.1, 0.1},
    .on_click = NULL
};

static ui_image_button_config_t const quality_segment_cfg = {
    .texture_hover = "./assets/gui/segment/quality_hover.png",
    .texture_normal = "./assets/gui/segment/quality_hover.png",
    .texture_pressed = "./assets/gui/segment/quality_hover.png",
    .rect = button_size,
    .on_click = NULL
};

static ui_textbox_config_t const world_name_text_box_cfg = {
    .rect = {0.3f, 0.3f, 0.4f, 0.1f},
    .bg_texture_path = "assets/gui/empty_button.png",
    .font_path = "assets/font.ttf",
    .max_chars = 24,
    .on_submit = world_name_callback,
    .text_offset = {0.1, 0.25},
    .default_text = "World name",
    .default_text_color = {140, 140, 140, 255}
};

static enum_entry_t const graphics_enum_selector_entries[] = {
    {
        .value = "low",
        .texture_off = "assets/gui/buttons/low_off.png",
        .texture_hover = "assets/gui/buttons/low_hover.png",
        .texture_on = "assets/gui/buttons/low_on.png"
    },
    {
        .value = "medium",
        .texture_off = "assets/gui/buttons/medium_off.png",
        .texture_hover = "assets/gui/buttons/medium_hover.png",
        .texture_on = "assets/gui/buttons/medium_on.png"
    },
    {
        .value = "high",
        .texture_off = "assets/gui/buttons/high_off.png",
        .texture_hover = "assets/gui/buttons/high_hover.png",
        .texture_on = "assets/gui/buttons/high_on.png"
    },
};

static ui_enum_selector_config_t const graphics_enum_selector_cfg = {
    .rect = {0.27, 0.65, 0.3, 0.1},
    .entries = graphics_enum_selector_entries,
    .entry_count = 3,
    .on_change = graphical_enum_selector_callback
};

static ui_slider_config_t const sounds_slider_cfg = {
    .rect = {0.27, 0.5, 0.3, 0.1},
    .background_texture_path = "assets/gui/buttons/slider_off.png",
    .cursor_texture_path = "assets/gui/buttons/slider_button_hover.png",
    .zero_point = {0.2f, 0.5f},
    .full_point = {0.8f, 0.5f},
    .cursor_box = {0.4f, 0.2f, 0.2f, 0.6f},
    .on_change = sounds_slider_callback,
};

static ui_image_button_config_t const sounds_segment_cfg = {
    .texture_hover = "./assets/gui/segment/sounds_hover.png",
    .texture_normal = "./assets/gui/segment/sounds_hover.png",
    .texture_pressed = "./assets/gui/segment/sounds_hover.png",
    .rect = button_size,
    .on_click = NULL
};

static ui_slider_config_t const musics_slider_cfg = {
    .rect = {0.27, 0.35, 0.3, 0.1},
    .background_texture_path = "assets/gui/buttons/slider_off.png",
    .cursor_texture_path = "assets/gui/buttons/slider_button_hover.png",
    .zero_point = {0.2f, 0.5f},
    .full_point = {0.8f, 0.5f},
    .cursor_box = {0.4f, 0.2f, 0.2f, 0.6f},
    .on_change = musics_slider_callback,
};

static ui_image_button_config_t const musics_segment_cfg = {
    .texture_hover = "./assets/gui/segment/musics_hover.png",
    .texture_normal = "./assets/gui/segment/musics_hover.png",
    .texture_pressed = "./assets/gui/segment/musics_hover.png",
    .rect = button_size,
    .on_click = NULL
};

static ui_slider_config_t const sensibility_slider_cfg = {
    .rect = {0.27, 0.35, 0.3, 0.1},
    .background_texture_path = "assets/gui/buttons/slider_off.png",
    .cursor_texture_path = "assets/gui/buttons/slider_button_hover.png",
    .zero_point = {0.2f, 0.5f},
    .full_point = {0.8f, 0.5f},
    .cursor_box = {0.4f, 0.2f, 0.2f, 0.6f},
    .on_change = sensibility_slider_callback,
};

static ui_image_button_config_t const sensibility_segment_cfg = {
    .texture_hover = "./assets/gui/segment/sensibility_hover.png",
    .texture_normal = "./assets/gui/segment/sensibility_hover.png",
    .texture_pressed = "./assets/gui/segment/sensibility_hover.png",
    .rect = button_size,
    .on_click = NULL
};

#endif /* RENDER_PAGES_H */
