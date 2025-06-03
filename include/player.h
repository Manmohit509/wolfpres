/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player
*/

#ifndef PLAYER_H
    #define PLAYER_H

    #include <stdbool.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

	#define MELEE_ID 0
    #define NB_ANIM 2
    #define RANGE_ID 1

typedef struct process_s process_t;

typedef enum weapon_type_e {
    WEAPON_MELEE = 0,
    WEAPON_RANGED = 1,
    WEAPON_NONE = 2
} weapon_type_t;

typedef enum anim_state_e {
    ANIM_NONE,
    ANIM_INSPECT,
    ANIM_ATTACK
} anim_state_t;

typedef struct animation_s {
    sfTexture *texture;
    sfSound *sound;
    sfIntRect frames;
    size_t frame_count;
    float frame_duration;
} animation_t;

typedef enum interaction_type_e {
    INTERACTION_COMPUTER,
    INTERACTION_HOPPY,
    INTERACTION_NONE
} interaction_type_t;

typedef struct player_data_s {
    bool has_flashlight;
    bool is_anim_playing;
    bool is_running;
    float stamina;
    float player_speed;
    float anim_timer;
    weapon_type_t current_weapon;
    anim_state_t anim_state;
    animation_t inspect_anim[2];
    animation_t attack_anim[2];
    size_t ranged_count;
    interaction_type_t interaction_type;
    sfSound *running;
    sfSound *out_of_breathing;
    sfSound *breathing;
} player_data_t;

struct inter_param_s {
    sfVector2f pos;
    player_data_t *player_data;
};

void player_update_interaction(
    process_t *process,
    sfVector2f pos,
    player_data_t *player_data);

#endif /* PLAYER_H */
