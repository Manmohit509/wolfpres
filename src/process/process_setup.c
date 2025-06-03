/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_setup
*/

#include <stdlib.h>

#include "render/pages.h"
#include "process.h"
#include "utils.h"
#include "entity_logic.h"
#include "wolf3d.h"

static bool setup_logger(process_t *process)
{
    process->logger = logger_create(LOGGER_FILE, LOGGER_LEVEL, "process");
    if (process->logger == NULL) {
        fprintf(stderr, "impossible to setup logger\n");
        return false;
    }
    logger_debug(process->logger, "logger setup success");
    return true;
}

static bool setup_clock(process_t *process)
{
    process->clock.clock = sfClock_create();
    if (process->clock.clock == NULL) {
        logger_error(process->logger, "clock setup failure");
        return false;
    }
    logger_debug(process->logger, "clock setup success");
    process_update_clock(process);
    return true;
}

static bool setup_window(process_t *process)
{
    int result = 0;

    process->window.title = WINDOW_NAME;
    process->window.video_mode = (sfVideoMode) {WINDOW_W, WINDOW_H, 32};
    process->window.settings = NULL;
    process->window.framerate = WINDOW_FRAMERATE;
    result = process_set_window_fullscreen(process, false);
    if (result != SUCCESS_EXIT) {
        logger_error(process->logger, "window setup failure");
        return false;
    }
    logger_debug(process->logger, "window setup success");
    return true;
}

static bool setup_entity_logic(process_t *process)
{
    if (process->entity_logic == NULL) {
        return false;
    }
    entity_logic_register(process->entity_logic,
        "hoppy", &entity_hoppy_logic);
    entity_logic_register(process->entity_logic,
    "player", &entity_player_logic);
    entity_logic_register(process->entity_logic,
    "projectile", &entity_projectile_logic);
    entity_logic_register(process->entity_logic,
    "jojo", &entity_jojo_logic);
    entity_logic_register(process->entity_logic,
        "heal", &entity_heal_logic);
    return true;
}

static bool setup_entity_data_handle(process_t *process)
{
    process->entity_logic = entity_logic_create();
    if (process->entity_logic == NULL) {
        return false;
    }
    entity_logic_register_tag(process->entity_logic,
        "hoppy", &hoppy_data_constructor, &hoppy_data_destructor);
    entity_logic_register_tag(process->entity_logic,
        "player", &player_data_constructor, &player_data_destructor);
    entity_logic_register_tag(process->entity_logic,
        "projectile", &projectile_data_constructor,
        &projectile_data_destructor);
    entity_logic_register_tag(process->entity_logic,
        "jojo", &jojo_data_constructor, &jojo_data_destructor);
    entity_logic_register_tag(process->entity_logic,
        "heal", &heal_data_constructor, &heal_data_destructor);
    return true;
}

static void init_default_values(process_t *process)
{
    process->level = NULL;
    process->inputs = (key_inputs_t) {0};
}

static bool setup_app(process_t *process)
{
    process->app = ui_app_create();
    if (process->app == NULL) {
        logger_error(process->logger, "app setup failure");
        return false;
    }
    if (pages_register(process) != SUCCESS_EXIT) {
        logger_error(process->logger,
            "app pages setup failure");
        return false;
    }
    ui_app_set_active_page(process->app, "main");
    logger_debug(process->logger, "app setup success");
    return true;
}

static bool load_assets(process_t *process)
{
    FILE *file = fopen("./assets/game_assets/default/default.assets", "r");

    if (file == NULL) {
        return false;
    }
    process->assets = asset_manager_create();
    if (process->assets == NULL ||
        asset_manager_load_textures_from_file(process->assets, file,
            "./assets/game_assets/default/") == FAILURE_EXIT) {
        fclose(file);
        return false;
    }
    fclose(file);
    return true;
}

sfFont *get_font(process_t *process, const char *id)
{
    font_asset_t *font = NULL;
    sfFont *sfont = NULL;

    if (process == NULL || id == NULL)
        return NULL;
    font = asset_manager_get_font(process->assets, id);
    if (font != NULL)
        sfont = font->font;
    if (sfont != NULL)
        return sfont;
    return NULL;
}

int process_setup(process_t *process)
{
    process->settings = settings_load();
    if (!setup_logger(process) ||
        !setup_clock(process) ||
        !setup_window(process) ||
        !load_assets(process) ||
        !setup_entity_data_handle(process) ||
        !setup_app(process) ||
        !setup_entity_logic(process)) {
        process_cleanup(process);
        return FAILURE_EXIT;
    }
    process->window.init_screen = sfRenderWindow_getSize(
        process->window.window);
    init_default_values(process);
    process->settings = settings_load();
    process->computer = init_jojo_computer(process);
    update_music_volume(process);
    return SUCCESS_EXIT;
}
