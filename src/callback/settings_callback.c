/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** settings_callback
*/

#include "process.h"

void settings_callback(void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->app) {
        return;
    }
    logger_info(process->logger, "settings callback called.");
    ui_app_push_page(process->app, "settings");
}
