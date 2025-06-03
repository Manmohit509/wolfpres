/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity
*/

#ifndef ENTITY_H
    #define ENTITY_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #include "player.h"

    #define JOJO_FOV 90
    #define JOJO_SPEED 2.0f
    #define JOJO_AGGRESSION_COOLDOWN 1.0f
    #define JOJO_AGGRESSION_DAMAGE 10
    #define JOJO_AGGRESSION_RANGE 0.5f

typedef struct process_s process_t;

typedef enum {
    ENTITY_PLAYER,
    ENTITY_ENEMY,
    ENTITY_OBJECT,
    ENTITY_PROJECTILE,
    ENTITY_UNKNOWN
} entity_type_t;

typedef struct entity_s {
    entity_type_t type;
    sfVector2f pos;
    sfVector2f direction;
    float speed;
    double angle_deg;
    int health;
    int is_active;
    int sprite_state;
    char *tag;
    void *data;
} entity_t;

typedef struct hoppy_data_s {
    sfSound *sound;
} hoppy_data_t;

typedef struct projectile_data_s {
    float rotation;
} projectile_data_t;

typedef struct jojo_data_s {
    sfVector2f agro_pos;
    bool is_agro;
    float aggression_cooldown;
    sfSound *sound;
    bool sound_playing;
} jojo_data_t;

typedef struct heal_data_s {
    bool is_using;
    sfSound *sound;
} heal_data_t;

typedef struct entity_logic_s entity_logic_t;

void player_set_weapon(entity_t *player, weapon_type_t new_weapon);
void player_start_attack(entity_t *player);
void player_handle_attack(process_t *process, entity_t *entity);

#endif /* ENTITY_H */
