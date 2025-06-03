/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_update_window
*/

#include "wolf3d.h"

#include "process.h"

int process_update_window(process_t *process)
{
    sfVector2u size = {0};

    if (process->window.window)
        sfRenderWindow_destroy(process->window.window);
    process->window.window = sfRenderWindow_create(process->window.video_mode,
        process->window.title, process->window.style,
        process->window.settings);
    if (!process->window.window)
        return FAILURE_EXIT;
    sfRenderWindow_setFramerateLimit(process->window.window,
        process->window.framerate);
    sfRenderWindow_setKeyRepeatEnabled(process->window.window, false);
    size = sfRenderWindow_getSize(process->window.window);
    if (process->window.scene)
        sfRenderTexture_destroy(process->window.scene);
    process->window.scene = sfRenderTexture_create(size.x, size.y, sfFalse);
    if (!process->window.scene)
        return FAILURE_EXIT;
    return SUCCESS_EXIT;
}
