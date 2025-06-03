/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_update_clock
*/

#include "process.h"

void process_update_clock(process_t *process)
{
    sfTime const new_time = sfClock_getElapsedTime(process->clock.clock);

    process->clock.delta_t = sfTime_asSeconds(new_time) -
        sfTime_asSeconds(process->clock.last_time);
    process->clock.last_time = new_time;
}
