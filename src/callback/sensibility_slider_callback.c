/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** sensibility_slider_callback
*/

#include "process.h"

void sensibility_slider_callback(float value, void *user_data)
{
    process_t *process = user_data;

    if (process == NULL)
        return;
    process->settings.sensitivity = value;
}
