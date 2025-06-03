/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_cleanup
*/

#include <stdlib.h>

#include "process.h"
#include "entity_logic.h"

static void destroy_window(process_t *process)
{
    if (process->window.window != NULL) {
        sfRenderWindow_destroy(process->window.window);
        if (process->logger != NULL)
            logger_debug(process->logger, "window destroyed");
    }
    if (process->window.scene != NULL) {
        sfRenderTexture_destroy(process->window.scene);
        if (process->logger != NULL)
            logger_debug(process->logger,
                "window scene destroyed");
    }
}

static void destroy_clock(process_t *process)
{
    if (process->clock.clock != NULL) {
        sfClock_destroy(process->clock.clock);
        if (process->logger != NULL)
            logger_debug(process->logger, "[process_unload] clock destroyed");
    }
}

static void destroy_app(process_t *process)
{
    if (process->app) {
        ui_app_destroy(process->app);
    }
}

static void destroy_logger(process_t *process)
{
    if (process->logger) {
        logger_debug(process->logger, "logger destroyed");
        logger_destroy(process->logger);
    }
}

void process_cleanup(process_t *process)
{
    destroy_window(process);
    destroy_clock(process);
    destroy_app(process);
    destroy_logger(process);
    if (process->level)
        destroy_level(process->level, process->entity_logic);
    if (process->assets)
        asset_manager_destroy(process->assets);
    if (process->entity_logic)
        entity_logic_destroy(process->entity_logic);
    if (process->computer->textBox)
        sfText_destroy(process->computer->textBox);
    if (process->computer)
        free(process->computer);
    settings_save(process->settings);
}
