/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** load_level_from_file
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "process.h"
#include "level.h"

static void skip_empty_or_comment(FILE *f, char *buf, size_t size)
{
    do {
        if (!fgets(buf, size, f)) {
            break;
        }
    } while (buf[0] == '#' || buf[0] == '\n');
}

static game_map_t *init_game(FILE *file, int *out_w, int *out_h)
{
    char line[256] = {0};
    game_map_t *map = NULL;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MAP_SIZE ", 9) == 0) {
            sscanf(line, "MAP_SIZE %d %d\n", out_w, out_h);
            break;
        }
    }
    if (*out_w <= 0 || *out_h <= 0)
        return NULL;
    map = malloc(sizeof(game_map_t));
    if (!map) {
        return NULL;
    }
    map->width = *out_w;
    map->height = *out_h;
    return map;
}

static game_map_t *parse_map(FILE *file, int *out_w, int *out_h)
{
    game_map_t *map = init_game(file, out_w, out_h);

    if (!map)
        return NULL;
    map->tiles = malloc(sizeof(int *) * *out_h);
    if (!map->tiles) {
        free(map);
        return NULL;
    }
    for (int y = 0; y < *out_h; y++) {
        map->tiles[y] = malloc(sizeof(int) * *out_w);
        if (!map->tiles[y]) {
            destroy_map(map);
            return NULL;
        }
        for (int x = 0; x < *out_w; x++) {
            fscanf(file, "%d", &map->tiles[y][x]);
        }
    }
    return map;
}

static entity_manager_t *parse_entities(FILE *file, process_t *process)
{
    entity_manager_t *manager = entity_manager_create();
    char line[256] = {0};
    entity_t e = {0};

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n')
            continue;
        e = create_entity_from_line(line, process->entity_logic, process);
        entity_manager_add(manager, e, process->entity_logic, process);
    }
    return manager;
}

level_t *load_level_from_file(FILE *file, process_t *process)
{
    int w = 0;
    int h = 0;
    game_map_t *map = parse_map(file, &w, &h);
    char line[256] = {0};
    entity_manager_t *entities = NULL;
    level_t *lvl = NULL;

    if (!map)
        return NULL;
    skip_empty_or_comment(file, line, sizeof(line));
    if (strncmp(line, "[ENTITIES]", 10) == 0)
        entities = parse_entities(file, process);
    lvl = malloc(sizeof(level_t));
    lvl->map = map;
    lvl->entities = entities ? entities : entity_manager_create();
    return lvl;
}
