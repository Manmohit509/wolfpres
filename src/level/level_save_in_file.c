/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** level_save_in_file
*/

#include <stdlib.h>
#include <stdio.h>

#include "level.h"

static int save_map(FILE *file, game_map_t *map)
{
    if (!file || !map || !map->tiles)
        return EXIT_FAILURE;
    fprintf(file, "MAP_SIZE %d %d\n", map->width, map->height);
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            fprintf(file, "%d%s", map->tiles[y][x],
                x < map->width - 1 ? " " : "");
        }
        fprintf(file, "\n");
    }
    return EXIT_SUCCESS;
}

static void save_entities(FILE *file, entity_manager_t *manager)
{
    entity_node_t const *node = manager->head;
    entity_t const *e = NULL;

    fprintf(file, "\n[ENTITIES]\n");
    while (node) {
        e = &node->entity;
        if (e->tag)
            fprintf(file, "%s %.2f %.2f %.0f\n",
                e->tag,
                e->pos.x,
                e->pos.y,
                e->angle_deg);
        node = node->next;
    }
}

int level_save_in_file(level_t *level, FILE *file)
{
    if (!file || !level || !level->map || !level->entities)
        return EXIT_FAILURE;
    if (save_map(file, level->map) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    save_entities(file, level->entities);
    return EXIT_SUCCESS;
}
