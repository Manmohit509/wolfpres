/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** multiplayer_callback
*/

#include "process.h"

void multiplayer_callback(void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->app) {
        return;
    }
    logger_info(process->logger, "multiplayer callback called.");
    ui_app_push_page(process->app, "singleplayer");
}
