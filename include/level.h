/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** level
*/


#ifndef LEVEL_H
    #define LEVEL_H

    #include "game_map.h"
    #include "entity_manager.h"

typedef struct {
    game_map_t *map;
    entity_manager_t *entities;
} level_t;

typedef struct entity_logic_s entity_logic_t;

level_t *load_level_from_file(FILE *file, process_t *process);
void destroy_level(level_t *lvl, entity_logic_t *logic);
int level_save_in_file(level_t *level, FILE *file);

#endif /* LEVEL_H */
