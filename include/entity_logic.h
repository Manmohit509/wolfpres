/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_logic
*/

#ifndef ENTITY_LOGIC_H
    #define ENTITY_LOGIC_H

    #include "entity.h"
    #include "hashmap.h"
    #include "entity_manager.h"

typedef struct logic_callback_s {
    char *tag;
    void (*callback)(entity_t *, void *);
    struct logic_callback_s *next;
} logic_callback_t;

typedef struct entity_logic_s {
    hashmap_t *constructors; // key = tag, value = constructor(void *)
    hashmap_t *destructors; // key = tag, value = destructors(void *)
    logic_callback_t *head;
} entity_logic_t;


entity_logic_t *entity_logic_create(void);
void entity_logic_destroy(entity_logic_t *logic);

void entity_logic_register(
    entity_logic_t *logic,
    const char *tag,
    void (*callback)(entity_t *, void *));

void entity_logic_apply(
    entity_logic_t *logic,
    entity_manager_t *manager,
    void *userdata);

void entity_logic_register_tag(
    entity_logic_t *logic,
    const char *tag,
    void *(*constructor)(void *),
    void (*destructor)(void *));

void *entity_logic_construct_data(
    entity_logic_t *logic,
    const char *tag,
    void *data);

void entity_logic_destroy_data(entity_logic_t *logic, entity_t *entity);

// ENTITIES LOGICS
void *hoppy_data_constructor(void *ptr);
void hoppy_data_destructor(void *ptr);
void entity_hoppy_logic(entity_t *entity, void *data);

void *jojo_data_constructor(void *ptr);
void jojo_data_destructor(void *ptr);
void entity_jojo_logic(entity_t *proj, void *data);

void *player_data_constructor(void *ptr);
void player_data_destructor(void *ptr);
void entity_player_logic(entity_t *entity, void *data);

void projectile_data_destructor(void *ptr);
void *projectile_data_constructor(void *ptr);
void entity_projectile_logic(entity_t *proj, void *data);

void heal_data_destructor(void *ptr);
void *heal_data_constructor(void *ptr);
void entity_heal_logic(entity_t *entity, void *data);
#endif /* ENTITY_LOGIC_H */
