/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** create_game_callback
*/

#include "process.h"

void create_game_callback(void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->app) {
        return;
    }
    logger_info(process->logger, "create game callback called.");
    ui_app_push_page(process->app, "create_game");
}
