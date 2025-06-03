/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** game_map_destroy
*/

#include <stdlib.h>

#include "game_map.h"

static void free_tiles(int **tiles, int h)
{
    for (int i = 0; i < h && tiles[i]; i++)
        free(tiles[i]);
    free(tiles);
}

void destroy_map(game_map_t *map)
{
    if (!map)
        return;
    free_tiles(map->tiles, map->height);
    free(map);
}
