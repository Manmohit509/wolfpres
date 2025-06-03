/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** get_original_win_size
*/

#include "utils.h"

sfVector2f get_original_win_size(sfRenderWindow const *window)
{
    return sfView_getSize(sfRenderWindow_getDefaultView(window));
}
