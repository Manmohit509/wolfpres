/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game_map
*/

#ifndef GAM_MAP_H
    #define GAM_MAP_H

    #include <stdio.h>

typedef struct game_map_s {
    int width;
    int height;
    int **tiles;
} game_map_t;

game_map_t *load_map_from_file(FILE *file);
void destroy_map(game_map_t *map);

#endif /* GAM_MAP_H */
