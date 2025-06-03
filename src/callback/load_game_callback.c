/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** load_game_callback
*/

#include "process.h"

void load_game_callback(void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->app) {
        return;
    }
    logger_info(process->logger, "load game callback called.");
    ui_app_push_page(process->app, "load_game");
}
