/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** load_map_from_file
*/

#include <stdlib.h>
#include <string.h>

#include "game_map.h"

static void free_tiles(int **tiles, size_t max_size)
{
    for (size_t i = 0; tiles[i] != NULL && i < max_size; i++) {
        free(tiles[i]);
    }
    free(tiles);
}

static int **alloc_tiles(int w, int h)
{
    int **tiles = malloc(sizeof(int *) * h);

    if (!tiles) {
        return NULL;
    }
    for (int i = 0; i < h; i++) {
        tiles[i] = malloc(sizeof(int) * w);
        if (!tiles[i]) {
            free_tiles(tiles, i);
            return NULL;
        }
    }
    return tiles;
}

static game_map_t *create_default_map(int w, int h)
{
    game_map_t *map = NULL;

    if (w <= 0 || h <= 0)
        return NULL;
    map = malloc(sizeof(game_map_t));
    if (!map)
        return NULL;
    map->width = w;
    map->height = h;
    map->tiles = alloc_tiles(w, h);
    if (!map->tiles) {
        free(map);
        return NULL;
    }
    return map;
}

game_map_t *load_map_from_file(FILE *file)
{
    char line[256] = {0};
    int width = 0;
    int height = 0;
    game_map_t *map = NULL;

    if (!file)
        return NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MAP_SIZE", 8) == 0) {
            sscanf(line, "MAP_SIZE %d %d", &width, &height);
            break;
        }
    }
    map = create_default_map(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(file, "%d", &map->tiles[y][x]);
        }
    }
    return map;
}
