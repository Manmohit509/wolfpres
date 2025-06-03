/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_set_window_fullscreen
*/

#include "process.h"

int process_set_window_fullscreen(process_t *process, bool is_fullscreen)
{
    if (is_fullscreen) {
        process->window.style = sfFullscreen;
    } else {
        process->window.style = sfResize | sfClose;
    }
    process->window.is_fullscreen = is_fullscreen;
    return process_update_window(process);
}

