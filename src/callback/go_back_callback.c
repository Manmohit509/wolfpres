/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** go_back_callback
*/

#include "process.h"

void go_back_callback(void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->app) {
        return;
    }
    logger_info(process->logger, "go back callback called.");
    ui_app_pop_page(process->app);
}
