/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** wolf3d
*/

#ifndef WOLF3D_H
    #define WOLF3D_H

    #define WIN_W 1080
    #define WIN_H 720
    #define PLAYER_SPEED 4.0f
    #define ROTATE_SPEED 2.5f
    #define FAILURE_EXIT 84
    #define SUCCESS_EXIT 0
    #define UNUSED __attribute__((unused))

    #include "process.h"

sfFont *get_font(process_t *process, const char *id);
//void handle_movement(entity_t *player, process_t const *d);
int joffreystein(void);

#endif /* WOLF3D_H */
