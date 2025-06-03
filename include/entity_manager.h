/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_manager
*/

#ifndef ENTITY_MANAGER_H
    #define ENTITY_MANAGER_H

    #include "entity.h"

typedef struct entity_logic_s entity_logic_t;

typedef struct entity_node_s {
    entity_t entity;
    struct entity_node_s *next;
    bool marked_for_removal;
} entity_node_t;

typedef struct {
    entity_node_t *head;
    size_t count;
} entity_manager_t;

entity_manager_t *entity_manager_create(void);

void entity_manager_mark_for_removal(
    entity_manager_t *manager,
    entity_t *target);

entity_t *entity_manager_add(
    entity_manager_t *manager,
    entity_t entity,
    entity_logic_t *logic,
    void *data);

entity_t create_entity_from_line(
    const char *line,
    entity_logic_t *logic,
    void *data);

entity_t *entity_manager_get_by_tag(
    entity_manager_t *manager,
    const char *tag);

void entity_manager_print(const entity_manager_t *manager);
void entity_logic_destroy_data(entity_logic_t *logic, entity_t *entity);
void entity_manager_cleanup(entity_manager_t *manager, entity_logic_t *logic);
void entity_manager_destroy(
    entity_manager_t *manager,
    entity_logic_t *logic);
void entity_manager_for_each(
    entity_manager_t *manager,
    void (*callback)(entity_t *, void *),
    void *userdata);
void entity_manager_sort(entity_manager_t *manager, sfVector2f pos);

typedef struct {
    entity_t *entity;
    float distance;
} entity_dist_pair_t;

#endif /* ENTITY_MANAGER_H */
