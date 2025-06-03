/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** register_settings_page
*/

#include <string.h>

#include "render/pages.h"
#include "wolf3d.h"

static bool setup_sounds_slider(
    ui_page_t *page,
    process_t *process,
    ui_widget_t const *ref)
{
    ui_slider_config_t cfg = sounds_slider_cfg;
    ui_widget_t *widget = NULL;

    cfg.rect.y = ((ui_image_button_t *)ref->data)->rect.y;
    cfg.user_data = process;
    widget = ui_slider_create(&cfg);
    ((ui_slider_t *)widget->data)->value = process->settings.sound_multiplier;
    ui_page_add_widget(page, widget);
    return widget;
}

static bool setup_musics_slider(
    ui_page_t *page,
    process_t *process,
    ui_widget_t const *ref)
{
    ui_slider_config_t cfg = musics_slider_cfg;
    ui_widget_t *widget = NULL;

    cfg.rect.y = ((ui_image_button_t *)ref->data)->rect.y;
    cfg.user_data = process;
    widget = ui_slider_create(&cfg);
    ((ui_slider_t *)widget->data)->value = process->settings.music_multiplier;
    ui_page_add_widget(page, widget);
    return widget;
}

static bool setup_sensibility_slider(
    ui_page_t *page,
    process_t *process,
    ui_widget_t const *ref)
{
    ui_slider_config_t cfg = sensibility_slider_cfg;
    ui_widget_t *widget = NULL;

    cfg.rect.y = ((ui_image_button_t *)ref->data)->rect.y;
    cfg.user_data = process;
    widget = ui_slider_create(&cfg);
    ((ui_slider_t *)widget->data)->value = process->settings.sensitivity;
    ui_page_add_widget(page, widget);
    return widget;
}

static int get_quality_index(quality_t quality)
{
    if (quality == LOW) {
        return 0;
    }
    if (quality == MEDIUM) {
        return 1;
    }
    if (quality == HIGH) {
        return 2;
    }
    return 0;
}

static bool setup_quality_enum_selector(
    ui_page_t *page,
    process_t *process,
    ui_widget_t const *ref)
{
    ui_enum_selector_config_t cfg = graphics_enum_selector_cfg;
    ui_widget_t *widget = NULL;

    cfg.rect.y = ((ui_image_button_t *)ref->data)->rect.y;
    cfg.user_data = process;
    widget = ui_enum_selector_create(&cfg);
    printf("%d\n", process->settings.render_quality);
    ((ui_enum_selector_t *) widget->data)->current_index = get_quality_index(process->settings.render_quality);
    ui_page_add_widget(page, widget);
    return widget;
}

static int add_widgets(ui_page_t *page, process_t *process)
{
    ui_widget_t *sounds = ui_image_button_create(&sounds_segment_cfg);
    ui_widget_t *musics = ui_image_button_create(&musics_segment_cfg);
    ui_widget_t *quality = ui_image_button_create(&quality_segment_cfg);
    ui_widget_t *sensi = ui_image_button_create(&sensibility_segment_cfg);
    ui_widget_t *back = ui_image_button_create(&go_back_btn_cfg);
    ui_widget_t *array[] = {quality, sensi, sounds, musics, back};
    ui_layout_config_t cfg = {.widgets = array, .count = 5, .padding_y = 0.04f,
        .align_y = UI_ALIGN_MIDDLE,
        .rect = {0.0f, 0.2f, 0.3f, 0.7f},
        .use_fixed_size = true
    };

    setup_widgets_data(array, 5, process);
    ui_layout_col(page, &cfg);
    return sounds && musics && quality && back && sensi &&
        setup_sounds_slider(page, process, sounds) &&
        setup_musics_slider(page, process, musics) &&
        setup_sensibility_slider(page, process, sensi) &&
        setup_quality_enum_selector(page, process, quality)
        ? SUCCESS_EXIT : FAILURE_EXIT;
}

int register_settings_page(process_t *process)
{
    ui_page_t *page = ui_page_create();

    if (!page) {
        return FAILURE_EXIT;
    }
    ui_app_add_page(process->app, "settings", page);
    if (add_default_menu(page) != SUCCESS_EXIT ||
        add_widgets(page, process) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
