/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** exit_callback
*/

#include "process.h"

void exit_callback(void *userdata)
{
    process_t *process = userdata;

    if (!process || !process->window.window) {
        return;
    }
    logger_info(process->logger, "exit callback called.");
    sfRenderWindow_close(process->window.window);
}
