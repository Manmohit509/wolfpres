/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** utils
*/

#ifndef UTILS_H
    #define UTILS_H

    #define COLOR_RESET   "\033[0m"
    #define COLOR_GREEN   "\033[1;32m"
    #define COLOR_YELLOW  "\033[1;33m"
    #define COLOR_RED     "\033[1;31m"

    #include <SFML/Graphics.h>
    #include <math.h>

    #include "renderer.h"
    #include "entity.h"

    #define DEG (M_PI_2 / 90)

    #define RAD_TO_DEG(rad) ((rad) * (180.0f / (float)M_PI))
    #define DEG_TO_RAD(deg) ((deg) / (180.0f / (float)M_PI))

typedef struct process_s process_t;
typedef struct viewer_s viewer_t;
typedef struct game_map_s game_map_t;

void log_info(const char *fmt, ...);
void log_debug(const char *fmt, ...);
void log_warn(const char *fmt, ...);
void log_error(const char *fmt, ...);

sfVector2f get_original_win_size(sfRenderWindow const *window);
double format_rotation(double rotation);
bool is_wall_between(
    game_map_t const *map,
    viewer_t const *viewer,
    sfVector2f target);
float compute_distance(sfVector2f a, sfVector2f b);
ray_cast_result_t cast_ray(
    game_map_t const *map,
    viewer_t const *viewer,
    double ra,
    sfVector2f offset);
void update_sound_listener(entity_t *entity);
void music_switch(process_t *process, char const *id);
float compute_angle(sfVector2f a, sfVector2f b);
sfVector2f compute_orientation(float angle);
float vector2f_to_angle(sfVector2f direction);
void handle_movement(entity_t *player, process_t *d);
void update_music_volume(process_t *process);

#endif /* UTILS_H */
