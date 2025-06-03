/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** pages_register
*/


#include "wolf3d.h"
#include "render/pages.h"

int pages_register(process_t *process)
{
    if (register_main_page(process) != SUCCESS_EXIT ||
        register_singleplayer_page(process) != SUCCESS_EXIT ||
        register_load_game_page(process) != SUCCESS_EXIT ||
        register_settings_page(process) != SUCCESS_EXIT ||
        register_in_game_page(process) != SUCCESS_EXIT ||
        register_create_game_page(process) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
